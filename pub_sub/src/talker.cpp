#include "ros/ros.h"
#include "std_msgs/Float32.h"



/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "ahmed_talker");


  ros::NodeHandle n;


  ros::Publisher float_pub = n.advertise<std_msgs::Float32>("float_chatter", 50);

  ros::Rate loop_rate(10);


  float count = 0.0;
  while (ros::ok())
  {

    std_msgs::Float32 msg;


    msg.data = count;
   // ROS_INFO("%s", msg.data.c_str());

    float_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
