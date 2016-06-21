

#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/Bool.h>
#include <image_transport/image_transport.h>

#include <iostream>
#include <cstdlib>

#include "../include/trajectory_rgbd/Scope.h"

using namespace ros;
using namespace std;

int main(int argc, char **argv)
{
    init(argc, argv, "scope");
    
    Scope scope;
    NodeHandle nh;
    image_transport::ImageTransport it(nh);
    image_transport::Publisher* mainsPub = scope.getPublisher();
    Subscriber sub = nh.subscribe<sensor_msgs::Image>("/camera/rgb/image_rect_color",
                                                      10,
                                                      &Scope::imageCallback,
                                                      &scope);
                                                     
    Subscriber sub2 = nh.subscribe<std_msgs::Bool>("/usar/depth/dist",
                                                  10,
                                                  &Scope::distCallback,
                                                  &scope);
                                                      
   *mainsPub = it.advertise("/trajectory_rgbd/scope", 10);
    
    spin();
    
    return EXIT_SUCCESS;
}
