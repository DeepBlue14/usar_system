/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
#include <QtCore/QDebug>

#include <iostream>

#include "../include/operator_ui/CamWidget.h"

CamWidget::CamWidget(const char* camSubTopic, QWidget* parent) : QWidget(parent), shutdown_required(false), it(nh)
{
    rejectCount = 0;
    swapRG = true;
    this->camSubTopic = new QString(camSubTopic);
    
    qimage.load("src/usar_teleop/robot_operator_ui/res/place_holder.png");
    
    ccs::computeScreenSize();
    resizeImage();
    
    outerLayout = new QGridLayout();
    //outerLayout->addWidget(&fakeImgLbl, 0, 0);
    
    this->setLayout(outerLayout);
    
    //it(nh);
    //sub = nh.subscribe<sensor_msgs::Image>(camSubTopic, 10, &CamWidget::callback, this);
    swapTopic(camSubTopic);
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
	myPainter.drawImage(p, qimage);
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
    }
    
}


void CamWidget::ir_callback(const sensor_msgs::Range::ConstPtr& msg)
{
    ;
}


void CamWidget::resizeImage()
{
    qimage = QImage(qimage.scaled(qimage.width()*1.4,
                          qimage.height()*1.4,
                          Qt::KeepAspectRatio) );
}


char* CamWidget::toString()
{
    char* str = const_cast<char*>("***METHOD STUB @CamWidget::toString()***");
    
    return str;
}


CamWidget::~CamWidget()
{
    delete camSubTopic;
}
