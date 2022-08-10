#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32.h"


float num ;

void chatterCallback(const std_msgs::Int32& msg)
{  
 // ROS_INFO("I heard: [%f]", msg.data);

num = msg.data;

}

int main(int argc, char **argv)
{

  
  
  ros::init(argc, argv, "listener");
 
  ros::NodeHandle n;


  std_msgs::Float32 result;

  ros::Subscriber sub = n.subscribe("float_chatter", 50, chatterCallback);
  ros::Publisher res_pub = n.advertise<std_msgs::Float32>("result", 50);
  ros::Rate loop_rate(10);
  while (ros::ok()) {
  float res=num/2;  
  result.data = res;
  ros::spinOnce();
  ROS_INFO_STREAM(result.data);
  res_pub.publish(result);
  loop_rate.sleep();}
  return 0;
}

