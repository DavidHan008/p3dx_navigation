#!/usr/bin/env python

NAME='add_two_ints_server'

from multinav.srv import *
import rospy

def add_two_ints(req):
    print("add %s + %s = %s"%(req.A,req.B,(req.A+req.B)))
    sum=req.A+req.B
    return AddTwoIntsResponse(sum)

def add_two_ints_server():
    rospy.init_node(NAME)
    s=rospy.Service('add_two_ints',AddTwoInts,add_two_ints)
    print "read to add two ints"
    rospy.spin()

if __name__=="__main__":
    add_two_ints_server()
