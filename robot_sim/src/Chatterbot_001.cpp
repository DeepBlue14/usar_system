/**
 * File:   Chatterbot_1.h
 * Module: ros_ip_transform
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This is developed to test for the HriMap. It publishes fake odometry data, so that
 *                   the map will update itself as if the robot was moving.
 *
 * Notes: Interesting observation--mutltiple publishers can publish to the same topic. 
 *
 * Created: 1/01/2016
 * Last Modified: 1/05/2016
 */
 


#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "chatterbot_001");
    
    ros::NodeHandle nh;
    ros::Publisher chatter_pub = nh.advertise<geometry_msgs::Twist>("/odom_lite/pos", 1);
    
    ros::Rate loop_rate(30); //30 hz
    
    int count = 0;
    while(ros::ok() )
    {
        geometry_msgs::Twist pos;
        
        if(count < 100)
        {
            //pos.angular.z = 1.0;
            pos.linear.y = -1.0;
        }
        else if(count >= 10 && count < 150)
        {
            pos.angular.z = -1.0;
        }
        else if(count >= 150 && count < 200)
        {
            pos.linear.x = 1.0;
        }
        else if(count >= 200 && count < 250)
        {
            pos.angular.z = 1.0;
        }
        else
        {
            count = -1;
        }
        
        
        chatter_pub.publish(pos);
        
        ros::spinOnce();
        
        loop_rate.sleep();
        count++;
    }
    
    return 0;
}
