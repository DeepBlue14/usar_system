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

#include "../include/robot_operator_ui/CamWidget.h"

CamWidget::CamWidget(const char* camSubTopic, QWidget* parent) : QWidget(parent), shutdown_required(false)
{
    //By loading a pure alpha image, this prevents QT from shrinking
    //TODO: make this image/label resizeable?
    //fakeImg.load("src/usar_teleop/robot_operator_ui/res/place_holder2.png");
    //fakeImgLbl.setPixmap(QPixmap::fromImage(fakeImg) );
    
    rejectCount = 0;
    this->camSubTopic = new QString(camSubTopic);
    
    qimage.load("src/usar_teleop/robot_operator_ui/res/place_holder.png");
    
    ccs::computeScreenSize();
    resizeImage();
    
    outerLayout = new QGridLayout();
    //outerLayout->addWidget(&fakeImgLbl, 0, 0);
    
    this->setLayout(outerLayout);
    this->resize(650, 490);
    
    ros::NodeHandle nh;
    sub = nh.subscribe<sensor_msgs::Image>(camSubTopic, 10, &CamWidget::callback, this);
}


void CamWidget::paintEvent(QPaintEvent *event)
{
    //cout << "@paintEvent(...)" << endl;
	QPainter myPainter(this);
	QPointF p(5, 5);
	myPainter.drawImage(p, qimage);
}


void CamWidget::callback(const sensor_msgs::ImageConstPtr& msg)
{
    if(rejectCount < 10)
    {
        rejectCount++;
    }
    else
    {
        QImage tmpQimage(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
        qimage = tmpQimage;
        resizeImage();
    }
    
}


void CamWidget::resizeImage()
{
    qimage = QImage(qimage.scaled(qimage.width()*ccs::screenSize->width()/1800,
                          qimage.height()*ccs::screenSize->height()/180,
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
