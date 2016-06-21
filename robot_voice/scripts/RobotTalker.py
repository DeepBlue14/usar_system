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
from std_msgs.msg import Int32
from sound_play.msg import SoundRequest
from sound_play.libsoundplay import SoundClient

import xml.etree.ElementTree as ET

def loadData():
    tree = ET.parse('/home/james/catkin_ws/src/usar_teleop/robot_voice/res/dictionary.xml')
    root = tree.getroot()



    for child in root:
        #print child.tag, child.get('brief'), child.get('say')
        a.append(child.get('say') )

    for elem in a:
        print elem + '\n'

    print("done")


def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard: %s", data.data)
    
    s = a[data.data]
    soundhandle.say(s, voice)
    rospy.sleep(4)
    
    
def listener():
    rospy.init_node('listener', anonymous=True)
    
    loadData()
    
    rospy.Subscriber("chatter", Int32, callback)
    
    rospy.spin()


a = []
soundhandle = SoundClient()
voice = 'voice_kal_diphone'
volume = 1.0


if __name__ == '__main__':
    listener()
