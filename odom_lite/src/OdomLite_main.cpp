#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include "../include/odom_lite/OdomLite.h"

using namespace ros;

int main(int argc, char **argv)
{
    init(argc, argv, "odom_lite");

    OdomLite odomLite;

    NodeHandle nh;
    Publisher* mainsPub = odomLite.getPublisher();
    Subscriber baseSub = nh.subscribe<geometry_msgs::Twist>("/cmd_vel_mux/input/navi",
                                                             10,
                                                             &OdomLite::callback,
                                                             &odomLite);

    *mainsPub = nh.advertise<geometry_msgs::Twist>("/odom_lite/pos", 1);
    
    spin();
    
    return 0;
}
