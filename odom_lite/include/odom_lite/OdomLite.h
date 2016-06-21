#ifndef ODOM_LITE_H
#define ODOM_LITE_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Point.h>

#include <iostream>

using namespace ros;
using std::cout;
using std::cerr;
using std::endl;

class OdomLite
{
    public:
        OdomLite();
        void callback(const geometry_msgs::TwistConstPtr& msg);
        Publisher* getPublisher() const;
        char* toString();
        ~OdomLite();

    private:
        Publisher* pub;

};

#endif /* ODOM_LITE_H */
