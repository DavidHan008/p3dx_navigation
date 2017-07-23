#[Rosaria](http://wiki.ros.org/ROSARIA) Demo Client
This package is a series of simple demos meant to demonstrate how the robot is controlled in both ROS and Mobile Robots's [Aria](http://robots.mobilerobots.com/wiki/ARIA) 

# Usage

Prerequisites: catkin workspace is setup, and use "git clone https://github.com/pengtang/rosaria_client.git" under the directory of catkin_ws/src. Then, under the catkin_ws directory type "catkin_make" to compile and make executable files. Last, still under catkin_ws, type "source devel/setup.bash".

Step 1. If you are operating with a real robot, look at Case 1, if you are using the mobilesim, look at Case 2.

 * Case 1: Please refer to http://wiki.ros.org/ROSARIA/Tutorials/How%20to%20use%20ROSARIA
  
 * Case 2: Open mobilesim, typically achieved by using the MobileSim command in the terminal

Step 2. Open a terminal with two tabs. Do this sequentially: The first tab type "roscore", the second tab type "roslaunch rosaria_client rosaria_client_launcher.launch".

Alternatively, if you don't want to use a launch file and would like to open the interface manually, follow these steps:
     -Open a terminal with three tabs. 
     -Do this sequentially: The first tab type "roscore", the second tab type "rosrun rosaria RosAria", the third tab type "rosrun rosaria_client interface"

Step 3. Follow the instruction in the interface program, run the programs from the interface menu respectively.

Update date: Apr. 20
*************************************************************************

# Update Log

Beta V1.0 Most of the time it works fine, sometimes it does not stop(continue going ahead or continue spinning).

Beta V1.1 (Mar. 28) Fix the bug sometimes the robot does not stop Add feature of Stopping the robot first, and then do its functionality

Beta V1.2 (Apr. 5) Add print_state function(could print part of the info right now, need to be enhanced).

Beta V1.3 (Apr. 10) Pushed some small corrections to spin_clockwise, renamed spin_anticlockwise to spin_counterclockwise and added small corrections to that as well. Also added (very) rough draft of interface program.

Beta V1.4 (Apr. 10) Change the spin from 180 to 90 degree, finished the print_state function.

Beta V1.5 (Apr. 14) Add function enable_motors, fix the printing information about the front_motors and rear_motors state.

Beta V1.6 (Apr 16) Added a functional version of the interface 

Beta V1.7 (Apr 18) Changed stop key to spacebar in teleop, where the user now hits 'q' to quit.  Also edited interface to prompt user for inputs every time its ready for a selection

Beta V1.8 (Apr. 20) Add launch file for rosaria_client

Beta V1.9 (Apr. 30) Added print_state feature, documentation 
