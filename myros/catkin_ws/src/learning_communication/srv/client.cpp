#include <cstdlib>
#include "ros/ros.h"
#include "learning_communication/AddTwoInts.h"

int main(int argc, char **argv)
{
	//ROS node init
	ros::init(argc, argv, "add_two_ints_client");
	//从终端获取数据
	if(argc != 3)
	{
		ROS_INFO("usage: add_two_ints_client X Y");
		return 1;
	}
	//creat node 
	ros::NodeHandle n;
	//创建一个client 请求add_two_int
	ros::ServiceClient client = n.serviceClient<learning_communication::AddTwoInts>("add_two_ints");
	//创建service消息
	learning_communication::AddTwoInts srv;
	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);
	
	//发布service请求
	if(client.call(srv))
	{
		ROS_INFO("Sum: %1d",(long int)srv.response.sum);
	}
	else
	{
		ROS_INFO("Failed to call service add_two_ints");
		return 1;
	}
	
	return 0;
}