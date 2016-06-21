/*
 * missile_launcher.h
 *
 */

#ifndef MISSILE_LAUNCHER_H_
#define MISSILE_LAUNCHER_H_

#include <usb.h>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <ros/ros.h>

using namespace std;

typedef enum
{
	FIRE = 0x10, LEFT = 0x4, RIGHT = 0x8, UP = 0x1, DOWN = 0x2, STOP = 0x0
} MissileCmd;

class MissileLauncher
{
public:
	//Setup and teardown
	int init();
	void deinit();
	//Motion commands
	void fire();
	void stop();
	void turn(MissileCmd direction);
private:
	usb_dev_handle* launcher;
	int sendMsg(MissileCmd cmd);
};

#endif /* MISSILE_LAUNCHER_H_ */
