/*
 * Copyright (C) 2016 James T. Kuczynski
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

/*
 * File:   main.cpp
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description:
 *
 * Created on March 8, 2016, 5:50 PM
 * Last Modified: 3/25/2016
 */

#include <ros/ros.h>

#include <QApplication>

#include <iostream>

#include <cstdlib>
#include <signal.h>

#include "../include/central_control_ui/Server.h"
#include "../include/central_control_ui/RqtSpinner.h"


// Signal handler
//void cleanup();


int main(int argc, char **argv)
{
    ros::init(argc, argv, "central_control_ui");

    QApplication a(argc, argv);
    Server server;
    server.setup(1234);
    RqtSpinner spinner;
    spinner.setup(&server);

    //signal(SIGINT, cleanup() );
    //signal(SIGTERM, cleanup() );

    return a.exec();
}


/*
void cleanup()
{
    std::cout << "Cleaning up program after signal quit" << std::endl;
    delete server->getMasterGui();
    delete server;
    
    exit(EXIT_SUCCESS);
}
*/
