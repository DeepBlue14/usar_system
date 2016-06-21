/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   CamTab.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 29, 2016, 9:40 AM
 * Last Modified: 3/08/2016
 */

#ifndef USAR_JOY_H
#define USAR_JOY_H

#include <ros/ros.h>
#include <sensor_msgs/Joy.h>

#include <geometry_msgs/Twist.h>

#include <std_msgs/Int32.h>
#include <std_msgs/Bool.h>

#include <iostream>

#include "Usar.h"

using namespace ros;
using namespace std;
using namespace usar;

class usar::UsarJoy
{
    public:
        UsarJoy();
        void callback(const sensor_msgs::JoyConstPtr& msg);
        Publisher* getRobotNavPubPtr() const;
        Publisher* getTurretNavPubPtr() const;
        Publisher* getTopicPubPtr() const;
        Publisher* getFireTurretPubPtr() const;
        //Publisher* getUiModePubPtr() const;
        //Publisher* getFocusPubPtr() const;
        Publisher* getEnableTurretPubPtr() const;
        Publisher* getConfigPubPtr() const;
        char* toString();
        ~UsarJoy();

    private:
        Publisher* robotNavPubPtr;
        Publisher* turretNavPubPtr;
        Publisher* topicPubPtr;
        Publisher* fireTurretPubPtr;
        //Publisher* uiModePubPtr;
        //Publisher* focusPubPtr;
        Publisher* enableTurretPubPtr;
        Publisher* configPubPtr;
        
        float joyToVelScaler; //turtlebot Create v2 max speed = 0.5
        
        geometry_msgs::Twist robotNav;
        geometry_msgs::Twist turretNav;
        std_msgs::Int32 topic;
        std_msgs::Bool fireTurret;
        //std_msgs::Bool uiMode;
        //std_msgs::Int32 focus;
        std_msgs::Bool enableTurret;
        std_msgs::Bool config;
};

#endif /* USAR_JOY_H */
