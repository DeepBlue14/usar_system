/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CenterDepth_main.cpp
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on April 05, 2016, 11:34 PM
 * Last Modified: 4/05/2016
 */

#include <ros/ros.h>
#include <std_msgs/Bool.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/range_image/range_image.h>

#include <iostream>
#include <cstdlib>

#include "../include/trajectory_rgbd/CenterDepth.h"

using namespace ros;
using namespace pcl;
using namespace std;

int main(int argc, char **argv)
{
    init(argc, argv, "center_depth");

    CenterDepth centerDepth;
    NodeHandle nh;

    Publisher* mainsPub = centerDepth.getPublisher();

    Subscriber sub = nh.subscribe<PointCloud<PointXYZRGB>::Ptr>("/camera/depth_registered/points",
							                                    10,
							                                    &CenterDepth::callback,
							                                    &centerDepth);

    *mainsPub = nh.advertise<std_msgs::Bool>("/usar/depth/dist", 10);

    spin();

    return EXIT_SUCCESS;
}
