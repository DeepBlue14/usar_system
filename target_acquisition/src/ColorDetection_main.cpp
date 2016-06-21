/*
 * File: ColorDetection_main.cpp
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * 
 */
 
 
#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/PointCloud2.h>
#include <dynamic_reconfigure/server.h>
#include <target_aquisition/ImageParamsConfig.h>

#include <iostream>
#include <cstdlib>

#include "../include/target_aquisition/ColorDetection.h"

using namespace ros;
using namespace std;


ColorDetection ColorDetection;


void drCallback(target_aquisition::ImageParamsConfig& config, uint32_t level)
{
    if(config.Activate == true)
    {
        ColorDetection.setActivateGuiBool(config.Activate);
        ColorDetection.setRedMinInt(config.Red_Min);
        ColorDetection.setGreenMinInt(config.Green_Min);
        ColorDetection.setBlueMinInt(config.Blue_Min);
        ColorDetection.setRedMaxInt(config.Red_Max);
        ColorDetection.setGreenMaxInt(config.Green_Max);
        ColorDetection.setBlueMaxInt(config.Blue_Max);
        
        ColorDetection.setHMinInt(config.H_Min);
        ColorDetection.setSMinInt(config.S_Min);
        ColorDetection.setVMinInt(config.V_Min);
        ColorDetection.setHMaxInt(config.H_Max);
        ColorDetection.setSMaxInt(config.S_Max);
        ColorDetection.setVMaxInt(config.V_Max);
    }
    else
    {
        ROS_INFO("GUI has not been activated\n");
    }
}


int main(int argc, char **argv)
{
    init(argc, argv, "ColorDetectionmentation");
    
    ROS_INFO("Starting node\n");

    NodeHandle nh;

    Publisher* mainsPub = ColorDetection.getPublisher();

    Subscriber sub = nh.subscribe<sensor_msgs::Image>("/camera/rgb/image_rect_color",
                                                        10,
                                                        &ColorDetection::callback,
                                                        &ColorDetection);

    *mainsPub = nh.advertise<sensor_msgs::Image>("/target_aqu/rgb/image_rect_color", 10);

    dynamic_reconfigure::Server<target_aquisition::ImageParamsConfig> server;
    dynamic_reconfigure::Server<target_aquisition::ImageParamsConfig>::CallbackType f;
    f = boost::bind(&drCallback, _1, _2);
    server.setCallback(f);


    spin();
    
    return EXIT_SUCCESS;
}
