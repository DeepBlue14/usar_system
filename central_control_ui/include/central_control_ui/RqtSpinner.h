/**
 * File:   RqtSpinner.h
 * Module: ros_ip_transform
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class implements most of the ROS side of this
 *                   program, listening for rostopic messages from the robots.
 *
 * Created: 1/01/2016
 * Last Modified: 1/05/2016
 */


#ifndef RQT_SPINNER_H
#define RQT_SPINNER_H

//#include <QtGui>
//#include <QApplication>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include <ecl/threads/thread.hpp> // or boost threads if you prefer

#include "Server.h"

class RqtSpinner
{    

public:
    RqtSpinner();
    void setup(Server* rqtServer);
    void spin();
    void callback(const geometry_msgs::TwistConstPtr& msg);
    void setRqtServer(Server* rqtServer);
    ~RqtSpinner();
        
private:
    Server* rqtServer;
    bool shutdown_required;
    ecl::Thread thread; // similarly, a boost thread
};

#endif /* RQT_SPINNER_H */
