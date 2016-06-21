#usar_joy
=====


###**Project Synopsis**

This module maps between the raw ROS game controller data and filters
it into individual topics, some of which are used by the operator_ui, and some used directly by the robot.


###**Dependencies**

- joy_node
- a game controller

```
sudo apt-get install ros-indigo-joy*
```

###**Build & Run**

You may have to configure the joystick.
Reference: http://wiki.ros.org/joy/Tutorials/ConfiguringALinuxJoystick
On my laptop, run:
```
sudo chmod a+rw /dev/input/js1
rosparam set joy_node/dev "/dev/input/js1"
```

Run
```
roscore
rosrun joy joy_node
rosrun joy_practice joy_practice
```
