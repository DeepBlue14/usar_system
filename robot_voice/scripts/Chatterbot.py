#!/usr/bin/env python

#!/usr/bin/env python

########################################################################
##
## Test program
## 
##
#########################################################################

import rospy
from std_msgs.msg import Int32

def talker():
    pub = rospy.Publisher('chatter', Int32, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        num = 1
        rospy.loginfo(num)
        pub.publish(num)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
