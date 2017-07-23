#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Spin_Counter_Clockwise");
  ros::NodeHandle nh;
  
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("RosAria/cmd_vel", 1000);
  geometry_msgs::Twist msg;

  double BASE_SPEED = 0.2, MOVE_TIME = 3.0, CLOCK_SPEED = 0.5, PI = 3.14159;
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

  while(ros::ok() && count<MOVE_TIME/CLOCK_SPEED + 2)
  {
      // Spin PI/4
      if (count == 0 || count == 1)
	    {
	       msg.angular.z = PI/ int(MOVE_TIME/CLOCK_SPEED) / 4;
	       pub.publish(msg);
	    }
      ROS_INFO_STREAM("The robot is now spinning counter_clockwise!");
      count++;
      ros::spinOnce();
      rate.sleep();
  }    

    // Stop the spin
  for(int i = 0; i < 2; i++)
  {
      msg.angular.x = 0;
      msg.angular.y = 0;
      msg.angular.z = 0;
      pub.publish(msg);
  }
  ROS_INFO_STREAM("The robot finished spinning 90 degrees!");
    
  //Guard, make sure the robot stops
  rate.sleep();
  msg.linear.x = 0;
  msg.linear.y = 0;
  msg.linear.z = 0;
  pub.publish(msg);
}
