#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include "../include/interference/TimeDelay.h"

using namespace ros;

int main(int argc, char **argv)
{
    init(argc, argv, "time_delay");
    
    TimeDelay timeDelay;
    
    NodeHandle nh;
    Publihser* mainsBasePub = timeDelay.getBasePub();
    Subscriber basePub = nh.subscribe<geometry_msgs::Twist>("/cmd_vel",
                                                            10,
                                                            &TimeDelay::robot);
    
    spin();
    
    return EXIT_SUCCESS;
}
