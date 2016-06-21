#include "../include/central_control_ui/RqtSpinner.h"


RqtSpinner::RqtSpinner() : shutdown_required(false), thread(&RqtSpinner::spin, *this)
{

    //ros::Publisher* pub = rqtServer->getPublisher();
    

}


void RqtSpinner::setup(Server* rqtServer)
{
    this->rqtServer = rqtServer;
}


void RqtSpinner::spin()
{
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<geometry_msgs::Twist>("/odom_lite/pos", 10, &RqtSpinner::callback, this);
    ros::Publisher* mainsPub = rqtServer->getPublisher();
    *mainsPub = nh.advertise<geometry_msgs::Twist>("/user/chatter", 10);
    
    
    ros::Rate loop(10);
    sleep(1);
    while(ros::ok() && !shutdown_required)
    {
        ros::spinOnce();
        loop.sleep();
        //ROS_INFO("Spinning!");
    }
}


void RqtSpinner::callback(const geometry_msgs::TwistConstPtr& msg)
{
    //ROS_INFO("I heard: [%s]", msg->data.c_str() );
    
    rqtServer->messageBridge(msg);
}


void RqtSpinner::setRqtServer(Server* rqtServer)
{
    this->rqtServer = rqtServer;
}


RqtSpinner::~RqtSpinner()
{
    shutdown_required = true;
    thread.join();
}
