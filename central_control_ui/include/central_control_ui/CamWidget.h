/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CamWidget.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This widget adds a layer of abstraction to the development
 *                   process, handling the ROS --> QT conversions behind the
 *                   scenes for video processing.
 *
 * Created on March 8, 2016, 4:40 PM
 * Last Modified: 3/25/2016
 */

#ifndef CAM_WIDGET_H
#define CAM_WIDGET_H

#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/Range.h>
#include <image_transport/image_transport.h>

#include <QWidget>
#include <QtGui/QPainter>
#include <QImage>
#include <QFrame>
#include <QString>
#include <QGridLayout>

#include <iostream>

#include "CCSystem.h"
#include "CustomLabel.h"

using namespace ros;
using namespace std;

class CamWidget : public QWidget
{
    Q_OBJECT
            
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        explicit CamWidget(int index, const char* defaultImgStr, QWidget* parent = 0);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void addBorder();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void focus();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void unfocus();
        
        
        void swapTopic(const char* camSubTopic);
    
        /**
        * Callback method for camera subscriber.
        *
        * <dt><b>Pre:<b></dd> the Nodehandle and subscriber must be set up.  A QBasicTimer
        *      should be running somewhere in this node, otherwise the video
        *      UI won't update regularly.
        * <dt><b>Post:<b></dd> The image member variable will contain the newest image.
        *       @see #qimage.
        *
        * @param msg The newest ROS frame from the camera
        */
        void callback(const sensor_msgs::ImageConstPtr& msg);
    
    
        void ir_callback(const sensor_msgs::Range::ConstPtr& msg);
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void resizeImage();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        CustomLabel* getLabel() const;
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        char* toString();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        virtual ~CamWidget();
        
        
    protected:
        /**
         * Draws/re-draws the image on the UI.
         *
         * <dt><b>Pre:<b></dd> the image object should contain a valid image, or Bad Things may
         *      happen.
         * <dt><b>Post:<b></dd> The video UI is updated.
         *
         * @param event This isn't used.
         */
        void paintEvent(QPaintEvent *event);
        
        
    private:
        CustomLabel* imageContainerLblPtr;
        bool swapRG;
        QImage fakeImg; /**  */
        QLabel fakeImgLbl;
        QString* camSubTopic;
        QStringList* camSubTopicStrLst; //TODO: implement
        QImage qimage;
        bool shutdown_required;
        QGridLayout* outerLayout;
        ros::NodeHandle nh;
        image_transport::ImageTransport it;
        //ros::Subscriber sub;
        image_transport::Subscriber sub;
        int rejectCount;
};

#endif /* CAM_WIDGET_H */
