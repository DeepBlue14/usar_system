/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include "../include/usar_joy/UsarJoy.h"

UsarJoy::UsarJoy()
{
    joyToVelScaler = 0.5;

    ros::NodeHandle nh;
    Subscriber sub = nh.subscribe<sensor_msgs::Joy>("/joy",
                                                      10,
                                                      &UsarJoy::callback,
                                                      this);

    robotNavPubPtr = new Publisher();
    turretNavPubPtr = new Publisher();
    topicPubPtr = new Publisher();
    fireTurretPubPtr = new Publisher();
    //uiModePubPtr = new Publisher();
    //focusPubPtr = new Publisher();
    enableTurretPubPtr = new Publisher();
    configPubPtr = new Publisher();
}


void UsarJoy::callback(const sensor_msgs::JoyConstPtr& msg)
{
    robotNav.linear.x = msg->axes[1] * joyToVelScaler;
    robotNav.angular.z = msg->axes[0] * joyToVelScaler;
    
    turretNav.angular.y = msg->axes[3];
    turretNav.angular.z = msg->axes[2];
    cout << "z: " << msg->axes[2] << endl;
    
    if(static_cast<int>(msg->axes[5] ) == -1 || static_cast<int>(msg->axes[5] ) == 1)
    {
        topic.data = static_cast<int>(msg->axes[5] );
        //cout << "UsarJoy::callback(...); sending: " << topic.data << endl;
        topicPubPtr->publish(topic);
    }
    else if(static_cast<int>(msg->axes[4] ) == 1)
    {
        topic.data = 2;
        //cout << "UsarJoy::callback(...); sending: " << topic.data << endl;
        topicPubPtr->publish(topic);
    }
        
    fireTurret.data = msg->buttons[5];
    //
    //
    enableTurret.data = msg->buttons[9];
    
    if(msg->buttons[2] == true)
    {
        config.data = msg->buttons[2];
        configPubPtr->publish(config);
    }

    
    robotNavPubPtr->publish(robotNav);
    turretNavPubPtr->publish(turretNav);
    fireTurretPubPtr->publish(fireTurret);
    enableTurretPubPtr->publish(enableTurret);
    
    //cout << "Pressed " << msg->buttons[2] << endl;
    //cout << "Sent nav command to turret" << endl;
}


Publisher* UsarJoy::getRobotNavPubPtr() const
{
    return robotNavPubPtr;
}


Publisher* UsarJoy::getTurretNavPubPtr() const
{
    return turretNavPubPtr;
}


Publisher* UsarJoy::getTopicPubPtr() const
{
    return topicPubPtr;
}


Publisher* UsarJoy::getFireTurretPubPtr() const
{
    return fireTurretPubPtr;
}


//Publisher* UsarJoy::getUiModePubPtr() const
//{
//    return uiModePubPtr;
//}


//Publisher* UsarJoy::getFocusPubPtr() const
//{
//    return focusPubPtr;
//}


Publisher* UsarJoy::getEnableTurretPubPtr() const
{
    return enableTurretPubPtr;
}


Publisher* UsarJoy::getConfigPubPtr() const
{
    return configPubPtr;
}


char* UsarJoy::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");
    
    return str;
}


UsarJoy::~UsarJoy()
{
    ;
}
