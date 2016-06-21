#ifndef TIME_DELAY_H
#define TIME_DELAY_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

class TimeDelay
{
    public:
        TimeDelay();
        void robotNavCallback(const geometry_msgs::TwistConstPtr& msg);
        //void turretNavCallback(const geometry_msgs::TwistConstPtr& msg)
        char* toString();
        ~TimeDelay();
        
    private:
        //Subscriber* baseSub;
        //Subscriber* turretSub;
        Publisher* basePub;
        Publisher* turretPub;

};

#endif /* TIME_DELAY_H */
