#include <ros/ros.h>  
#include <tf/transform_listener.h>  
#include <geometry_msgs/Twist.h>  
#include <unistd.h>  
#include "std_msgs/String.h"  

using namespace std;
int main (int argc, char** argv)  
{ 
    //const char *str_distance，*str_angle;  
    int count_running = 0;   
    ros::init (argc, argv, "kinect_tf");
    ros::NodeHandle nh;  
    geometry_msgs::Twist cmd;  
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist> ("/cmd_vel", 10);
    tf::TransformListener listener;  
    ros::Rate loop_rate(10.0);  
    while (nh.ok()){ 
        tf::StampedTransform tf, tf_right_hand, tf_right_shoulder; 
        try{          
            listener.lookupTransform("/openni_depth_frame", "/torso_1", ros::Time(0), tf); 
	   // listener.lookupTransform("/openni_depth_frame", "/torso_2", ros::Time(0), tf);  
            double pose_x = tf.getOrigin().x();  
            double pose_y = tf.getOrigin().y();  
	    double pose_x2 = tf.getOrigin().x();  
            double pose_y2 = tf.getOrigin().y();
 
            double pose_theta = tf::getYaw(tf.getRotation());  
            ROS_INFO("Pose of User: [x,y,theta]: [%f, %f, %f]...",pose_x,pose_y,pose_theta);  
            listener.lookupTransform("/openni_depth_frame", "/right_hand_1", ros::Time(0), tf_right_hand);
            double tf_right_hand_z = tf_right_hand.getOrigin().z();  
            listener.lookupTransform("/openni_depth_frame", "/right_shoulder_1", ros::Time(0), tf_right_shoulder);
            double tf_right_shoulder_z = tf_right_shoulder.getOrigin().z();  
        }  
        catch (tf::TransformException& ex){  
            ROS_ERROR("Received an exception trying to get information: %s", ex.what());
            ros::Duration(1.0).sleep();  
            continue;  
        }  
        cmd.linear.x = 0.0;
        cmd.linear.y = 0.0;  
        cmd.angular.z = 0.0;  
	double pose_x = tf.getOrigin().x();  
        double pose_y = tf.getOrigin().y();  
        double pose_theta = tf::getYaw(tf.getRotation()); 
	double tf_right_hand_z = tf_right_hand.getOrigin().z();  
	double tf_right_shoulder_z = tf_right_shoulder.getOrigin().z();   
	
//如果Ｘ的方向比Ｘ1 .6米小的话
        if (pose_x<1.4) 
        {  
           // str_distance = "knee thai jean ler";
    
            cmd.linear.x = -0.1; 
        }  
        else if (pose_x>1.8)  
        {  
            //str_distance = "knee thai yuan ler";
           
	    cmd.linear.x = 0.2;    
        }  
        else
        {  
     
		cmd.linear.x = 0.0;  
        }  
        if (pose_y> 0.15)  
        {  
           // str_angle = "zai Geo bian";
            cmd.angular.z = 0.25;  
        }  
        else if (pose_y< -0.15)  
        {  
           // str_angle = "zai you bian";
            cmd.angular.z = -0.25;  
        }  
        else 
        {  
           // str_angle = "zai june jain";  
            cmd.angular.z = 0.0;  
        }

        if (tf_right_hand_z >= tf_right_shoulder_z)
        {  
            cmd.linear.x = 0.0;  
            cmd.linear.y = 0.0;  
            cmd.angular.z = 0.0;  
            pub.publish(cmd);  
            ROS_INFO("cmd published: [v_x,v_y,w]:[%f, %f, %f]", cmd.linear.x, cmd.linear.y, cmd.angular.z);  
            const char *str1 = "I am stopping now!";   
            loop_rate.sleep();  
            continue;  
        }  
        pub.publish(cmd);  
        ROS_INFO("cmd published: [v_x,v_y,w]:[%f, %f, %f]", cmd.linear.x, cmd.linear.y, cmd.angular.z);  
        count_running++;  
        if (count_running > 30)  
        {  
           
            count_running = 0;  
        }  
    }             
    return 0;  
}  
