/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   PointCloudToRangeImage.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on April 05, 2016, 11:34 PM
 * Last Modified: 4/05/2016
 */

#ifndef POINT_CLOUD_TO_RANGE_IMAGE_H
#define POINT_CLOUD_TO_RANGE_IMAGE_H

#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/PointCloud2.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>

#include <pcl/point_types.h>
#include <pcl/range_image/range_image.h>

#include <iostream>

using namespace ros;
using namespace pcl;
using namespace std;

class PointCloudToRangeImage
{
    public:
        PointCloudToRangeImage();
        void callback(PointCloud<PointXYZRGB>::Ptr input);
        Publisher* getPublisher();
        RangeImage toPclRangeImage(PointCloud<PointXYZRGB>::Ptr input);
        ~PointCloudToRangeImage();
        
    private:
        void depthColor(PointCloud<PointXYZRGB>::Ptr input, int i);
    
        const int RUNS_PER_COLOR;
        const int COLOR_COEF;
        const float ABSOLUTE_MIN;//kinect cannot identify anything closer then this 
        bool loop;
        float incVal;
        float currentMin;
        float currentMax;
        Publisher* pub;

};

#endif /*POINT_CLOUD_TO_RANGE_IMAGE_H*/
