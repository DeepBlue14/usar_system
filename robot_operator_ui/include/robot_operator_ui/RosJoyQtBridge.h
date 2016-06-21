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
 
 
#ifndef ROS_JOY_QT_BRIDGE_H
#define ROS_JOY_QT_BRIDGE_H

#include <ros/ros.h>

#include <QObject>

class RosJoyQtBridge
{
    public:
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        RosJoyQtBridge();
        
        /**
         *
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         */
        void callback()
        
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
        ~RosJoyQtBridge();
        
    private:
        ;
}

#endif /* ROS_JOY_QT_BRIDGE_H */
