#!/usr/bin/env python
import rospy
from rospy.numpy_msg import numpy_msg
from rospy_tutorials.msg import Floats

import numpy

def talker():
    pub=rospy.Publisher('floats',numpy_msg(Floats),queue_size=10)
    rospy.init_node('talker',anonymous=True)
    r=rospy.Rate(10)
    while not rospy.is_shutdown():
        a=numpy.array([1.9,9.1,2.0],dtype=numpy.float32)
        pub.publish(a)
        r.sleep()

if __name__=='__main__':
    talker()