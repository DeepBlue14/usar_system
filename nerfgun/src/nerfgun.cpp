#include <ros/ros.h>
#include <nerfgun/ml_lib.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Bool.h>

double cmd_vel_deadband;
int refresh_rate;
MissileLauncher ml;
MissileCmd currentCmd;

void fire_cb(const std_msgs::BoolConstPtr& msg) {

    if(msg->data == true)
	    currentCmd = FIRE;
}

void cmd_vel_cb(const geometry_msgs::TwistConstPtr& msg) {

    //cout << "@cmd_vel_cb" << endl;
	double yaw   = msg->angular.z; // + is ccw
	double pitch = msg->angular.y; // + is down (bc follows right hand rule)
	cout << "yaw: " << yaw << endl;

	if(currentCmd != FIRE) {
		if(yaw > cmd_vel_deadband)
			currentCmd = LEFT;
		else if(yaw < -cmd_vel_deadband)
			currentCmd = RIGHT;
		else if(pitch > cmd_vel_deadband)
			currentCmd = DOWN;
		else if(pitch < -cmd_vel_deadband)
			currentCmd = UP;
		else
			currentCmd = STOP;
	}
}


int main(int argc, char **argv) {
	ros::init(argc, argv, "nerfgun_driver");
	ros::NodeHandle nh("nerf");
	nh.param("cmd_vel_deadband", cmd_vel_deadband, 0.25);
	nh.param("refresh_rate", refresh_rate, 10);

	currentCmd = STOP;
	if(ml.init() == 1)
		return 0;

	ros::Subscriber fireSub = nh.subscribe("fire", 1, fire_cb);
	ros::Subscriber cmd_vel = nh.subscribe("cmd_vel", 1, cmd_vel_cb);

	ros::Rate rate(refresh_rate);
	while(ros::ok()) {
		ros::spinOnce();
		ml.turn(currentCmd);
		currentCmd = STOP;
		rate.sleep();
		ml.turn(currentCmd);
		rate.sleep();
		//cout << "spinning" << endl;
	}

	ml.deinit();
	return 0;
}
