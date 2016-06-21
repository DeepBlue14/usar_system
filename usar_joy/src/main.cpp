/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/**
 * File:   main.cpp
 * Module: usar_joy
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This node handles the game controller.
 *
 * Created: 1/01/2016
 * Last Modified: 1/05/2016
 */


#include <ros/ros.h>
#include <sensor_msgs/Joy.h>

#include <geometry_msgs/Twist.h>

#include <std_msgs/Int32.h>
#include <std_msgs/Bool.h>

#include <iostream>

#include "../include/usar_joy/UsarJoy.h"

using namespace std;
using namespace ros;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "usar_joy");
    
    UsarJoy usarJoy;
    
    ros::NodeHandle nh;
    Subscriber sub = nh.subscribe<sensor_msgs::Joy>("/joy",
                                                      10,
                                                      &UsarJoy::callback,
                                                      &usarJoy);

    Publisher* robotNavPubPtr = usarJoy.getRobotNavPubPtr();
    *robotNavPubPtr = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/navi", 1); // /cmd_vel_mux/input/navi; /joy/robot_nav
    Publisher* turretNavPubPtr = usarJoy.getTurretNavPubPtr();
    *turretNavPubPtr = nh.advertise<geometry_msgs::Twist>("/nerf/cmd_vel", 1);
    Publisher* topicPubPtr = usarJoy.getTopicPubPtr();
    *topicPubPtr = nh.advertise<std_msgs::Int32>("/joy/topic", 1);
    Publisher* fireTurretPubPtr = usarJoy.getFireTurretPubPtr();
    *fireTurretPubPtr = nh.advertise<std_msgs::Bool>("/nerf/fire", 1);
    //Publisher* uiModePubPtr = usarJoy.getUiModePubPtr();
    //*uiModePubPtr = nh.advertise<std_msgs::Bool>("/joy/ui_mode", 1);
    //Publisher* focusPubPtr = usarJoy.getFocusPubPtr();
    //*focusPubPtr = nh.advertise<std_msgs::Int32>("/joy/focus", 1);
    Publisher* enableTurretPubPtr = usarJoy.getEnableTurretPubPtr();
    *enableTurretPubPtr = nh.advertise<std_msgs::Bool>("/joy/enable_gun", 1);
    Publisher* configPubPtr = usarJoy.getConfigPubPtr();
    *configPubPtr = nh.advertise<std_msgs::Bool>("/joy/config", 1);
    
    spin();
    
    return 0;
}
