#!/usr/bin/env python
import rospy as rp
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Vector3
from sensor_msgs.msg import Joy
from std_msgs.msg import Empty


def joy_cb(msg):
    #print("@joy_cb\n")
    global last_pos
    if msg.buttons[0] or msg.buttons[5]:
        #print("publishing \"fire\"\n")
        fire_pub.publish()
    else:
        #print("publisher \"Twist\"")
        last_pos = Twist(angular=Vector3(z=msg.axes[0], y=-msg.axes[1]))


def main():
    global fire_pub
    global last_pos
    rp.init_node('keyboard_teleop')
    last_pos = Twist()

    cmd_vel_pub = rp.Publisher('/nerf/cmd_vel', Twist, queue_size=10)
    fire_pub = rp.Publisher('/nerf/fire', Empty, queue_size=10)
    joy_sub = rp.Subscriber('/joy', Joy, joy_cb, queue_size=10)

    rate = rp.Rate(5)
    while not rp.is_shutdown():
        cmd_vel_pub.publish(last_pos)
        rate.sleep()
        #print("spinning @.py\n")


if __name__ == '__main__':
    main()
