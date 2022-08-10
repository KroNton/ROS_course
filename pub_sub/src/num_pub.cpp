#include "ros/ros.h"
#include "std_msgs/Int32.h"



/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "num_pub");


  ros::NodeHandle n;


  ros::Publisher float_pub = n.advertise<std_msgs::Int32>("float_chatter", 50);

  ros::Rate loop_rate(1);


  int count = 20;
  while (ros::ok())
  {

    std_msgs::Int32 msg;


    for(count;count<=100;count++){

    ROS_INFO_STREAM(count);
    msg.data = count;
    float_pub.publish(msg);
    sleep(1);
  }
    ros::spinOnce();
    loop_rate.sleep();
    count=100;
  }


  return 0;
}
