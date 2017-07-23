#!/usr/bin/env python
import rospy
from rospy_tutorials.msg import Floats
from rospy.numpy_msg import numpy_msg

def callback(data):
    print rospy.get_name(), "I head %s"%str(data.data)

def listern():
    rospy.init_node('listener')
    rospy.Subscriber("floats",numpy_msg(Floats),callback)
    rospy.spin()

if __name__=="__main__":
    listern()