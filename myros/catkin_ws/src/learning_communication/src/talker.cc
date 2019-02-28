#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
	//ROS node init
	ros::init(argc, argv, "talker");
	//creat node 
	ros::NodeHandle n;
	//creat a publisher,name:chatter,type:std_msgs::String
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1000);
	//set Frequency
	ros::Rate loop_rate(10);
	
	int count = 0;
	while (ros::ok())
	{
		//init messages
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello!Long time no see!How are you?" << count;
		msg.data = ss.str();
		
		//pub msgs
		ROS_INFO("%s", msg.data.c_str());
		chatter_pub.publish(msg);
		//loop for replay
		ros::spinOnce();
		//delay time
		loop_rate.sleep();
		++count;
	}
	return 0;
}