/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/central_control_ui/CamWidget.h"


CamWidget::CamWidget(int index, const char* defaultImgStr, QWidget* parent) : QWidget(parent), it(nh)
{
    rejectCount = 0;
    swapRG = true;
    this->camSubTopic = new QString(defaultImgStr);
    
    qimage.load("src/usar_teleop/central_control_ui/res/place_holder_small.jpg");
    
    ccs::computeScreenSize();
    //resizeImage();
    
    imageContainerLblPtr = new CustomLabel(index);
    imageContainerLblPtr->setPixmap(QPixmap::fromImage(qimage) );
    
    outerLayout = new QGridLayout();
    //outerLayout->addWidget(&fakeImgLbl, 0, 0);
    outerLayout->addWidget(imageContainerLblPtr, 0, 0);
    
    this->setLayout(outerLayout);
    
    //sub = nh.subscribe<sensor_msgs::Image>(camSubTopic, 10, &CamWidget::callback, this);
    swapTopic("/camera/rgb/image_rect_color");
}


void CamWidget::addBorder()
{
    imageContainerLblPtr->setFrameStyle(QFrame::Panel | QFrame::Raised);
    imageContainerLblPtr->setLineWidth(5);
}


void CamWidget::focus()
{
    imageContainerLblPtr->setStyleSheet("QFrame { background-color: blue }");
}


void CamWidget::unfocus()
{
    imageContainerLblPtr->setStyleSheet("QFrame { background-color: white }");
}


void CamWidget::swapTopic(const char* camSubTopic)
{
    cout << "camtopic: " << camSubTopic << endl;

    QString tmpQstr(camSubTopic);
    if(QString::compare(camSubTopic, "/camera/rgb/image_rect_color", Qt::CaseSensitive) )
        swapRG = true;
    else
        swapRG = false;
        

    if(QString::compare(camSubTopic, "/camera/ir/image", Qt::CaseSensitive) )
    {
        //sub = nh.subscribe<sensor_msgs::Image>(camSubTopic, 10, &CamWidget::callback, this);
        sub = it.subscribe(camSubTopic, 10, &CamWidget::callback, this);
        cout << "********calling IMAGE" << endl;
    }
    else
    {
        //sub = nh.subscribe<sensor_msgs::Range>(camSubTopic, 10, &CamWidget::ir_callback, this);
        cout << "*********Calling IR" << endl;
    }
}


void CamWidget::paintEvent(QPaintEvent* event)
{
    //cout << "@paintEvent(...)" << endl;
	QPainter myPainter(this);
	QPointF p(5, 5);
	//myPainter.drawImage(p, qimage);
}


void CamWidget::callback(const sensor_msgs::ImageConstPtr& msg)
{
    //cout << "@CamWidget::callback(...)" << endl;
    if(rejectCount < 10)
    {
        rejectCount++;
    }
    else
    {
        QImage tmpQimage(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
        if(swapRG)
            qimage = tmpQimage.rgbSwapped();
        else
            qimage = tmpQimage;
            
        resizeImage();
        imageContainerLblPtr->setPixmap(QPixmap::fromImage(qimage) );
    }
    
}


void CamWidget::ir_callback(const sensor_msgs::Range::ConstPtr& msg)
{
    ;
}



void CamWidget::resizeImage()
{
    qimage = QImage(qimage.scaled(qimage.width()*ccs::screenSize->width()/1700,
                          qimage.height()*ccs::screenSize->height()/170,
                          Qt::KeepAspectRatio) );
}


CustomLabel* CamWidget::getLabel() const
{
    return imageContainerLblPtr;
}


char* CamWidget::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


CamWidget::~CamWidget()
{
    ;
}
