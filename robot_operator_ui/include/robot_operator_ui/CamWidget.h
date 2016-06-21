/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/**
 * File:   CamWidget.h
 * Module: ros_ip_transform
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This widget subscribes to a ROS image topic and displays
 *                   the image in a UI window.
 *
 * Notes: this link is for cv::Mat --> QImage: http://stackoverflow.com/questions/17127762/cvmat-to-qimage-and-back
 *
 * Created: 1/23/2016
 * Last Modified: 1/28/2016
 */
 

#ifndef CAM_WIDGET_H
#define CAM_WIDGET_H

#include <ros/ros.h>
#include <sensor_msgs/Image.h>

#include <QTimer>
#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QtGui/QImage>
#include <QtGui/QPainter>
#include <QtGui/QPaintDevice>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QtCore/QRegExp>
#include <QtCore/QString>
#include <QtCore/QStringList>

#include <iostream>
#include <string>

#include "CCSystem.h"

using namespace std;

class CamWidget : public QWidget
{
    Q_OBJECT
    
public:
    /**
     * Constructor.
     *
     * <dt><b>Pre:<b></dd> None
     * <dt><b>Post:<b></dd> Member variables of this class are instantiated.
     *
     * @param camSubTopic Default topic for to be displayed
     * @param parent Parent type
     */
    explicit CamWidget(const char* camSubTopic, QWidget* parent = 0);
    
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
    
    /**
     * Resizes the image relative to the size of the computer screen.
     *
     * <dt><b>Pre:<b></dd> The image object must contain a valid image, either from the
     *      default one initially loaded, or a valid frame passed by the
     *      subscriber.
     * <dt><b>Post:<b></dd> The image object @see #qimage will contain the newest frame.
     */
    void resizeImage();
    
    /**
     * Java-style toString() method.
     *
     * <dt><b>Pre:<b></dd> None
     *<dt><b>Post:<b></dd> None
     *
     * @return data of this class.
     */
    char* toString();
    
    /**
     * Destructor.
     *
     * <dt><b>Pre:<b></dd> None
     * <dt><b>Post:<b></dd> All member objects will be deleted.
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
    QImage fakeImg; /**  */
    QLabel fakeImgLbl;
    QString* camSubTopic;
    QStringList* camSubTopicStrLst; //TODO: implement
    QImage qimage;
    bool shutdown_required;
    QGridLayout* outerLayout;
    ros::Subscriber sub;
    int rejectCount;
    
};

#endif /* CAM_WIDGET_H */
