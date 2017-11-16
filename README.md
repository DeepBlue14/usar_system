![Logo](https://github.com/DeepBlue14/usar_system/blob/master/operator_ui/res/icon_small.png)

# usar_teleop
*Final project for [92.450: Mobile Robotics I][3], with [Dr. Fred Martin][4]*

*Author/Maintainer:* James Kuczynski,  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Undergraduate Researcher,  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[Robotics Laboratory][1],  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[University of Massachusetts Lowell][2].  
*Email:* jkuczyns@cs.uml.edu

=====


### **Index**
- [Project Synopsis](#project_synopsis)
- [Introduction]
- [Modules]
  - [central_control_ui](#central_control_ui)
  - [interference](#interference)
  - [nerfgun](#nerfgun)
  - [observer_ui](#observer_ui)
  - [odom_lite](#odom_lite)
  - [operator_ui](operator_ui)
  - [robot_operator_ui](#robot_operator_ui)  **DEPRECATED**
  - [robot_sim](#robot_sim)
  - [robot_voice](#robot_voice)
  - [target_aquisition](#target_aquisition)
  - [trajectory_rgbd](#trajectory_rgbd)
  - [usar_joy](#usar_joy)
- [Dependencies](#dependencies)
- [Install](#install)
- [Build & Run](#build_and_run)
  - [build](#build)
  - [run](#run)
- [Future Work](#future_work)
- [Acknowledgements](#acknowledgements)


### **Project Synopsis**

This project is a implementation of a tactical urban search and rescue (USAR) distributed system.  The author developed it as a class final project for Mobile Robotics 1 with Dr. Fred Martin at UMass Lowell.


### **Introduction**

This system includes modules for robotic field agents and human operators, observers on mobile devices, and Central Command.

**A few statistics**
The combined system is about 15 processes, several of which are multithreaded.  These applications are developed in C/C++, Python, BASH, and HTML/JavaScript, with a combined total of some 12,000 lines of code.


### **Modules**

#### **central_control_ui**

This module is the Central Control server and user interface.


#### **interference**

This module intercepts topics, pauses for a configurable amount of time, and republishes them with the prefix ```/interference```.  This allows the simulation of long-distance communications (i.e. to the moon).  It can also add static to video feeds, etc.

**NOTE: This module has only been partialy implemented.**


#### **nerfgun**

This module controls the nerf-gun, converting ROS messages to hexadecimal commands which in sends to the nerf-gun using libusb.


#### **observer_ui**

This is the browser-based observer interface.


#### **odom_lite**

This module computes estimated odometry of the robot.


#### **operator_ui**

Graphical user interface of the robot operator.


#### **robot_operator_ui**

**DEPRECIATED** graphical user interface of the robot operator.


#### **robot_sim**

*For test purpose only*
Publishers simulated data test test the interfaces.


#### **robot_voice**

ROS Python scripts to enable the robot to play music or say things with a synthasized voice.


#### **target_aquisition**

Detects targets:
- People's faces
- Large red objects


#### **trajectory_rgbd**

Generates a gun scope.  Checks to see the distance of a target from the nerf-gun.  If it is within range (i.e. two meters) the gun scope will turn green, otherwise the scope will be red.


#### **usar_joy**

Converts the game controller data into individual topics for the user interfaces.


### **Dependencies**

**Hardware**
- Turtlebot
- 1 laptop (robot-brain)
- 2 laptops OR desktops (driver, Central Control)
- 1+ computers or mobile devices (observers)
- 1 game controller
- USB nerf gun
- Primesense Carmine RGB-D camera
- 522mm (red) 5mw laser pointer
- 6 AA batteries

**Software**
- Ubuntu 14.04LTS
- ROS Indigo
- QT 5.5
- OpenCV >= 2.9
- PCL >= 1.7.0


### **Install**

**NOTE: Do NOT implement the install instructions.  At the moment, no such install script exists.  Also the software is VERY unstable.**

```
cd catkin_ws/src
source devel/setup.bash
git clone xxxxxxxxxxx
cd usar_teleop/[node-name]/install
sudo chmod +x install.bash
./install.bash
```


### **Build & Run**

#### **Build**
```
cd catkin_ws
source devel/setup.bash
catkin_make
```

#### **Run**



**Robot**

```
roslaunch turtlebot_bringup turtlebot_bringup --screen
roslaunch openni2_launch openni2.launch
roslaunch nerfgun nerfgun_bringup.launch
rosrun sound_play soundplay_node.py

rosrun robot_voice music_player.py
#### OR
rosrun robot_voice RobotTalker.py
```

Note: music_player and RobotTalker are mutually exclusive.


**Robot Operator**
*Setup: *
In the terminal where you will launch the joy nodes, run:
```
cd usar_joy/scripts
sudo chmod +x joy_setup.bash
cd ../../..
```



```
roslaunch usar_joy usar_joy.launch
roslaunch trajectory_rgbd trajectory_rgbd.launch
rosrun target_aquisition person
rosrun operator_ui operator_ui
rosrun odom_lite odom_lite
```


**Central Control**

```
rosrun joy joy_node #optional
rosrun central_control central_control
```


**Observer**

Open a web browser.  Go to: http://.........
Sign in (the default username and password are both "default")
Open a new tab.  Go to: http://camera/rgb/image_rect_color


### **Future Work**

In the future it would be interesting to make this robot more autonomous.


### **Acknowledgements**

*TBA...*



[1]: http://robotics.cs.uml.edu/
[2]: http://www.uml.edu/
[3]: http://www.cs.uml.edu/ecg/index.php/MRIspr16/MRIspr16
[4]: http://www.cs.uml.edu/~fredm/
