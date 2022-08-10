#include "ros/ros.h"
#include "std_msgs/Float32.h"


float num ;

void chatterCallback(const std_msgs::Float32& msg)
{  
 // ROS_INFO("I heard: [%f]", msg.data);

num = msg.data;

}

int main(int argc, char **argv)
{

  
  
  ros::init(argc, argv, "listener");
 
  ros::NodeHandle n;
  ros::NodeHandle nh;

  std_msgs::Float32 result;
  float res=num/2;  
  result.data = res;
  ros::Subscriber sub = n.subscribe("float_chatter", 50, chatterCallback);
  ros::Publisher res_pub = nh.advertise<std_msgs::Float32>("result", 50);
  ros::Rate loop_rate(10);
  while (ros::ok()) {

  ros::spinOnce();
  

  res_pub.publish(result);
  //ROS_INFO("I heard: [%f]", result.data);  
 
  
  loop_rate.sleep();}
  return 0;
}

