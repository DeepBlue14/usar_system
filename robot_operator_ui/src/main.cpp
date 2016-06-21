/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/*
 * File:   main.cpp
 * Author: james
 *
 * Created on March 2, 2016, 11:30 PM
 */

#include <ros/ros.h>

#include <QApplication>

#include "../include/robot_operator_ui/MasterGui.h"
#include "../include/robot_operator_ui/SplashScreen.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "robot_operator_ui");

    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    SplashScreen* splash = new SplashScreen(&app);
    MasterGui masterGui;
    splash->show();
    QTimer::singleShot(5000, splash, SLOT(close() ) );
    QTimer::singleShot(5000, &masterGui, SLOT(show() ) );
    splash->spin();
    
    return app.exec();
}

