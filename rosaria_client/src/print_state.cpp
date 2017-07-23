#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Bool.h>
#include <nav_msgs/Odometry.h>
#include <rosaria/BumperState.h>
#include <iomanip> // for std :: setprecision and std :: fixed

int battery_msg_count = 0, bumper_msg_count = 0;

/* checks pose messages and outputs them to user */
void poseMessageReceived(const nav_msgs::Odometry& msg) 
{
	std::cout << std::setprecision(2) << std::fixed << /* output the pose information using standard output */
	  "Current position=(" << msg.pose.pose.position.x << ", " << msg.pose.pose.position.y << ") " << 
	  "Current direction=" << std::setprecision(2) << std::fixed << msg.pose.pose.orientation.w<<"\r";
	std::flush(std::cout);
}

/* output the state of the bumpers using rosaria */
void bumperStateMessageReceived(const rosaria::BumperState &msg)
{
	int front_size, rear_size;    
    if (bumper_msg_count == 0)
    {
//    	ROS_INFO_STREAM("The front bumpers are "<<msg.front_bumpers<<std::endl<<"The rear bumpers are "<<msg.rear_bumpers);
    	front_size = sizeof(msg.front_bumpers) / sizeof(bool);
    	rear_size = sizeof(msg.rear_bumpers) / sizeof(bool);
    	ROS_INFO_STREAM("The front bumpers state are('1' means good): ");
      std::cout << "    ";
    	for (int i=0;i<front_size;i++)
	  if (msg.front_bumpers[i])
    	    std::cout<<'1';
	  else
	    std::cout<<'0';
    	std::cout<<std::endl;
    	ROS_INFO_STREAM("The rear bumpers state are('1' means good): ");
      std::cout << "    ";
    	for (int i=0;i<rear_size;i++)
	  if (msg.rear_bumpers[i])
	    std::cout<<'1';
	  else
	    std::cout<<'0';
    	std::cout<<std::endl;
    	bumper_msg_count++;
    }
}

/* check the status of the battery charge */
void batteryStateOfChargeMessageReceived(const std_msgs::Float32 msg)
{
	// Right now this feature is not included in the pioneer-3 robot	
  	ROS_INFO_STREAM("The battery state of charge is "<<msg);
}

/* check + output the voltage of the battery using standard output */
void batteryVoltageMessageReceived(const std_msgs::Float64 msg)
{  
    if (battery_msg_count == 0)
    {
      battery_msg_count++;
      ROS_INFO_STREAM("The battery voltage is "<< msg);
    }
}

void batteryChargeStateMessageReceived(const std_msgs::Int8 msg)
{
	// Right now this feature is not included in the pioneer-3 robot
	ROS_INFO_STREAM("The battery charge state message received is "<< msg);
}

/* check the state of the motor and output using standard output */
void motorsStateMessageReceived(const std_msgs::Bool msg)
{
	if (msg.data)
		ROS_INFO_STREAM("The motor is good");
	else
		ROS_INFO_STREAM("The motor is bad");
}

/* call all of the functions implemented above and provide user with robot state info */
int main(int argc, char **argv)
{
	// Initialize the ROS system and become a node.
	ros::init(argc, argv, "print_aria_state"); ros::NodeHandle nh;
	// Create a subscriber object .
	ros::Subscriber pose, bumper_state, battery_state_of_charge, battery_voltage, battery_charge_state, motors_state;
	pose = nh.subscribe("RosAria/pose", 1000, &poseMessageReceived) ; //supply pose
	bumper_state = nh.subscribe("RosAria/bumper_state", 1000, &bumperStateMessageReceived) ; //inform bumper state
	battery_state_of_charge = nh.subscribe("RosAria/bumper_state_of_charge", 1000, &batteryStateOfChargeMessageReceived) ; //inform state of charge
	battery_voltage = nh.subscribe("RosAria/battery_voltage", 1000, &batteryVoltageMessageReceived) ; //inform battery voltage level
	battery_charge_state = nh.subscribe("RosAria/battery_charge_state", 1000, &batteryChargeStateMessageReceived) ; //inform charge state
	motors_state = nh.subscribe("RosAria/motors_state", 1000, &motorsStateMessageReceived) ; //inform motor state
	// Let ROS take over.
	ros::spin(); 
}
