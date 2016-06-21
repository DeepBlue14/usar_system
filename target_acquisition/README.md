###**Build & Run**

###**Project Synopsis**

This module detects two sets of targets.

**1:** Using Haar Cascades, this first program can detect humans.

**2:** Using HSV image data, this program allows the user to dynamically
select a specific color range as the target.

###**Build & Run**

Face capture
```
roslaunch openni2_launch openni2.launch
rosrun person_recognizer prepare_faces
```
