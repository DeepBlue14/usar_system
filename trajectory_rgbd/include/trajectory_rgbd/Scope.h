/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   Scope.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on April 05, 2016, 11:34 PM
 * Last Modified: 4/05/2016
 */

#ifndef SCOPE_H
#define SCOPE_H

// ROS
#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/PointCloud2.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/Bool.h>
#include <image_transport/image_transport.h>

// OpenCV
#include <opencv/cv.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//STL
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace ros;
using namespace cv;
using namespace std;

class Scope
{
    public:
        Scope();
        void imageCallback(const sensor_msgs::ImageConstPtr& input);
        void distCallback(const std_msgs::BoolConstPtr& input);
        void drawTarget();
        image_transport::Publisher* getPublisher() const;
        char* toString();
        ~Scope();
        
    private:
        cv_bridge::CvImagePtr cv_ptr;
        //int frameCount;
        //int distCount;
        Mat cvImage;
        Scalar* color;
        //Publisher* pub;
        image_transport::Publisher* pub;
};


#endif /* SCOPE_H */
