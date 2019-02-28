#include "ros/ros.h"
#include "learning_communication/AddTwoInts.h"

//service 回调函数，输入req 输出res
bool add(learning_communication::AddTwoInts::Request &req,
         learning_communication::AddTwoInts::Response &res)
{
	//将输入参数相加求和
	res.sum = req.a +req.b;
	ROS_INFO("request: x=%1d, y=%1d", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response:[%1d]",(long int)res.sum);
	return true;
}

int main(int argc, char **argv)
{
	//ROS node init
	ros::init(argc, argv, "add_two_ints_server");
	//creat node 
	ros::NodeHandle n;
	//创建一个service 注册回调函数add
	ros::ServiceServer service = n.advertiseService("add_two_ints",add);
	//循环等待回调函数
	ROS_INFO("Ready to add two ints.");
	ros::spin();
	return 0;
}