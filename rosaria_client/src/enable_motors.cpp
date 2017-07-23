#include <ros/ros.h>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "enable_motors");
  ros::NodeHandle nh;

  std::system("rosservice call /RosAria/enable_motors");

  ROS_INFO_STREAM("Motors are enabled!");

  return 0;
}
