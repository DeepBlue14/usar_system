/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CenterDepth.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on April 05, 2016, 11:34 PM
 * Last Modified: 4/05/2016
 */

#ifndef CENTER_DEPTH_H
#define CENTER_DEPTH_H

#include <ros/ros.h>
#include <std_msgs/Bool.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace ros;
using namespace pcl;
using namespace cv;
using namespace std;

class CenterDepth
{
    public:
        CenterDepth();
        void callback(PointCloud<PointXYZRGB>::Ptr input);
        Publisher* getPublisher() const;
        char* toString();
        ~CenterDepth();
        
    private:
        std_msgs::Bool isInRange;
        Publisher* pub;
};

#endif /* CENTER_DEPTH_H */
