#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "go_three_second");
  ros::NodeHandle nh;
  
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("RosAria/cmd_vel", 1000);
  geometry_msgs::Twist msg;

  double BASE_SPEED = 0.2, MOVE_TIME = 3.0, CLOCK_SPEED = 0.5;
  int count = 0;
  ros::Rate rate(CLOCK_SPEED);

  // Make the robot stop (robot perhaps has a speed already)
  msg.linear.x = 0;
  msg.linear.y = 0;
  msg.linear.z = 0;
  msg.angular.x = 0;
  msg.angular.y = 0;
  msg.angular.z = 0;
  pub.publish(msg);

  while(ros::ok() && count<MOVE_TIME/CLOCK_SPEED + 1)
    {
      if (count == 0 || count == 1)
	{
	    msg.linear.x = BASE_SPEED;
	    pub.publish(msg);
	}
      ROS_INFO_STREAM("The robot is now moving forward!");
      count++;
      ros::spinOnce();
      rate.sleep();
   }
  
  // make the robot stop
  for (int i = 0; i < 2; i++)
    {  

      msg.linear.x = 0;
      msg.linear.y = 0;
      msg.linear.z = 0;
      pub.publish(msg);

    }
    ROS_INFO_STREAM("The robot finished moving forward three seconds!");
    
    // Guard, make sure the robot stops.
    rate.sleep();
    msg.linear.x = 0;
    msg.linear.y = 0;
    msg.linear.z = 0;
    pub.publish(msg); 

}
