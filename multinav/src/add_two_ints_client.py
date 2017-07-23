#!/usr/bin/env python

import sys
import os

import rospy

from multinav.srv import *

def add_two_ints_client():
    try:
        add_two_ints=rospy.ServiceProxy('add_two_inits',AddTwoInts)
        print "Requesting %s+%s"%(x,y)
        resp1=add_two_ints(x,y)
        resp2=add_two_ints.call(AddTwoInts)

        if not resp1.sum==(x+y):
            raise Exception("test fail,sum is %s"%resp1.sum)
        if not resp2.sum==(x+y):
            raise Exception("test fail,sum is %s",resp2.sum)
        return resp1.sum

def usage():
    return "%s[x,y]"%sys.argv[0]

    if __name__=="__main__":
        argv=rospy.myargv()
        if len(argv)==1
            import random
            x=random.randint(-50000,50000)
            y=random.randint(-50000,50000)
        elif len(argv)==3:
            try:
                x=int(argv[1])
                y=int(argv[2])
            except:
                print usage()
                sys.exit(1)
            else:
                print usage()
                sys.exit()
            print "%s + %s ="%x(x,y,add_two_ints_client(x,y))
