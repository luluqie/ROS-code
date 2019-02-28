#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	//print received message
	ROS_INFO("I heard :[%s]",msg->data.c_str());
}

int main(int argc, char **argv)
{
	//ROS node init
	ros::init(argc, argv, "listener");
	//creat node 
	ros::NodeHandle n;
	//creat a Subscriber,name:chatter,type:std_msgs::String
	ros::Subscriber sub = n.subscribe("chatter",1000, chatterCallback);
	//loop for replay
	ros::spin();
	return 0;
}