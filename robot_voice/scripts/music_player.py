#!/usr/bin/env python

########################################################################
##
## File:
## Author: 
## Email: 
## File Description: 
##
## Ref: https://docs.python.org/2/library/xml.etree.elementtree.html
##
## Created: 4/07/2016
## Last Modified: 4/07/2016
##
#########################################################################

import rospy
from sound_play.msg import SoundRequest
from sound_play.libsoundplay import SoundClient


def playMusic():

    soundhandle.playWave('/home/james/catkin_ws/src/usar_teleop/robot_voice/res/Tchaikovsky.ogg')
    rospy.sleep(1)
    
    
def listener():
    rospy.init_node('listener', anonymous=True)
    
    playMusic()


soundhandle = SoundClient()


if __name__ == '__main__':
    listener()
