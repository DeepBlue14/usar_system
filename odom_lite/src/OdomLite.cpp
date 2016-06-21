#include "../include/odom_lite/OdomLite.h"

OdomLite::OdomLite()
{
    pub = new Publisher();
}


void OdomLite::callback(const geometry_msgs::TwistConstPtr& msg)
{
    cout << "@Odom::callback(...) linear.x: " << msg->linear.x << endl;
    
    geometry_msgs::Twist movBy;
    
    if(msg->linear.x > 0.1 || msg->linear.x < -0.01)
    {
        movBy.linear.x = msg->linear.x;
    }
    
    if(msg->linear.y > 0.1 || msg->linear.y < -0.01)
    {
        movBy.linear.y = msg->linear.y;
    }
    
    if(msg->angular.z > 0.1 || msg->angular.z < -0.01)
    {
        movBy.angular.z = msg->angular.z;
    }
    
    
    
    pub->publish(movBy);
}


Publisher* OdomLite::getPublisher() const
{
    return pub;
}


char* OdomLite::toString()
{
    char* str = const_cast<char*>("***METHOD STUB***");

    return str;
}


OdomLite::~OdomLite()
{
    delete pub;
}
