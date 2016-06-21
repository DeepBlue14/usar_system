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

#include "../include/operator_ui/MasterGui.h"
#include "../include/operator_ui/ConfigJoyGui.h"
#include "../include/operator_ui/OpConfigGui.h"
#include "../include/operator_ui/InRunGui.h"
#include "../include/operator_ui/HriMap.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "operator_ui");

    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    MasterGui masterGui;
    masterGui.show();
    //ConfigJoyGui configJoyGui;
    //configJoyGui.show();
    //OpConfigGui opConfigGui;
    //opConfigGui.show();
    //InRunGui inRunGui;
    //inRunGui.show();
    //HriMap hriMap;
    //hriMap.show();
    
    return app.exec();
}

