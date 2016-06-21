#include <ros/ros.h>
#include <sensor_msgs/Image.h>

#include <stdlib.h>
#include <stdio.h>

#include <iostream>

#include "../include/target_aquisition/Snapshot.h"

using namespace ros;
using namespace std;


int main(int argc, char **argv)
{
    init(argc, argv, "snapshot");
    
    NodeHandle nh;
    Snapshot snapshot;
    
    Publisher* mainsPub = snapshot.getPublisher();

    Subscriber sub = nh.subscribe<sensor_msgs::Image>("/camera/rgb/image_rect_color",
							                            1,
							                            &Snapshot::callback,
							                            &snapshot);

    *mainsPub = nh.advertise<sensor_msgs::Image>("/target_aquisition/rgb/image_with_face", 1);
    
    spin();
    
    return EXIT_SUCCESS;
}
