/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/* 
 * File:   MapTab.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This widget will get joy commands from ROS, and activate
 *                   or modify the GUI with them.
 *                   (functions, or signal/slots?)
 *
 * Created on March 3, 2016, 9:40 AM
 * Last Modified: 3/08/2016
 */

#ifndef JOY_UI_BRIDGE_H
#define JOY_UI_BRIDGE_H

#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Bool.h>

#include <QObject>

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

class JoyUiBridge : public QObject
{
    Q_OBJECT
    
    signals:
        void swapTopic(int num);
        void armSys(bool is);
        void openOpt(bool is);
    
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        JoyUiBridge();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void topicCallback(std_msgs::Int32 msg);
        
        /**
         * Arm/disarm the nerfgun.
         *
         * @param msg
         */
        void armSysCallback(std_msgs::Bool msg);
        
        /**
         * Open/close the options menu.
         *
         * @param msg
         */
        void openOptCallback(std_msgs::Bool msg);
        
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
        ~JoyUiBridge();
        
    private:
        int currMsg;
        ros::NodeHandle nh;
        ros::Subscriber sub;
        ros::Subscriber armSysSub;
        
};

#endif /* JOY_UI_BRIDGE_H */
