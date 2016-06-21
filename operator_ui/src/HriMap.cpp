#include "../include/operator_ui/HriMap.h"

HriMap::HriMap(QWidget* parent) : QWidget(parent), image("src/usar_teleop/operator_ui/res/3rdfloor_5cm_opacity60.png")
{
    widgetOffsetX = 0;
    widgetOffsetY = 0;
    degrees = 0;
    x = 0;
    y = 0;
    width = 300;
    height = 300;
    
    image = image.copy(0, 0, width, height);
    
    outerLayout = new QGridLayout();
    
    this->setLayout(outerLayout);
    this->setMinimumSize(width, height-40);
    
    sub = nh.subscribe<geometry_msgs::Twist>("/odom_lite/pos", 1, &HriMap::callback, this);
}


void HriMap::callback(const geometry_msgs::TwistConstPtr& msg)
{
    cout << "@HriMap::callback(...); y:" << mov.linear.y << endl;
    mov.linear.x = msg->linear.x;
    mov.linear.y = msg->linear.y;
    mov.angular.z = msg->angular.z;



}


void HriMap::rotateCounterClockwise()
{
    QMatrix mat;
    mat.rotate(degrees--);
}


void HriMap::rotateClockwise()
{
    QMatrix mat;
    mat.rotate(degrees++);
}


void HriMap::shiftLeft()
{
    image = QImage("src/usar_teleop/operator_ui/res/3rdfloor_5cm_opacity60.png");
    image = image.copy(x--, y, width, height);
    image = image.scaled(width, height, Qt::KeepAspectRatio);
}


void HriMap::shiftRight()
{
    image = QImage("src/usar_teleop/operator_ui/res/3rdfloor_5cm_opacity60.png");
    image = image.copy(x++, y, width, height);
    image = image.scaled(width, height, Qt::KeepAspectRatio);
}


void HriMap::shiftUp()
{
    image = QImage("src/usar_teleop/operator_ui/res/3rdfloor_5cm_opacity60.png");
    image = image.copy(x, y--, width, height);
    image = image.scaled(width, height, Qt::KeepAspectRatio);
}


void HriMap::shiftDown()
{
    image = QImage("src/usar_teleop/operator_ui/res/3rdfloor_5cm_opacity60.png");
    image = image.copy(x, y++, width, height);
    image = image.scaled(width, height, Qt::KeepAspectRatio);
}


void HriMap::zoomIn()
{
    image = image.scaled(width+=25, height+=25, Qt::KeepAspectRatio);
}


void HriMap::zoomOut()
{
    image = image.scaled(width-=25, height-=25, Qt::KeepAspectRatio);
}


void HriMap::paintEvent(QPaintEvent* event)
{
    if(mov.linear.x > 0)
    {
        //shiftRight();
        shiftUp();
    }
    
    if(mov.linear.x < 0)
    {
        //shiftLeft();
        shiftDown();
    }
    
    if(mov.linear.y > 0)
    {
        shiftUp();
    }
    
    if(mov.linear.y < 0)
    {
        shiftDown();
    }
    
    if(mov.angular.z > 0)
    {
        rotateCounterClockwise();
    }
    
    if(mov.angular.z < 0)
    {
        rotateClockwise();
    }

    QPainter painter(this);
    
    
    ///manipulate and paint the map
    QTransform trans;
    trans.translate(image.width()/2 - 25 + widgetOffsetX, image.height()/2 - 25 + widgetOffsetY);
    trans.rotate(degrees);
    trans.translate(-image.width()/2 + 25 - widgetOffsetX, -image.height()/2 + 25 - widgetOffsetY);
    
    painter.setTransform(trans);
    
    int tmp_w = (width/32)*28;
    int tmp_h = (height/32)*28;
    QRegion r(QRect(widgetOffsetX, widgetOffsetY, tmp_w, tmp_h), QRegion::Ellipse);
    //QRegion r(QRect(widgetOffsetX, widgetOffsetY, 300, 300), QRegion::Rectangle);
    painter.setClipRegion(r);
    
    painter.drawImage(QPoint(0, 0), image);
    
    ///paint the robot
    QBrush brush(Qt::green);
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(130, 130), 7, 7);
    
}


char* HriMap::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


HriMap::~HriMap()
{
    //delete mapLbl;
}
