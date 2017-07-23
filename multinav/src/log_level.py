#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def log_level():
    debug="This is debug"
    rospy.logdebug("success to debug %s",debug)

    info="This is info"
    rospy.loginfo("success to info %s",info)

    warn="This is warn"
    rospy.logwarn("success to warn %s",warn)

    error="This is error"
    rospy.logerr("success to err %s",error)

    fatal="This is fatal"
    rospy.logfatal("success to fatal %s", fatal)

if __name__=='__main__':
    try:
        rospy.init_node('log_level',log_level=rospy.DEBUG)
        log_level()
    except rospy.ROSException:
        pass