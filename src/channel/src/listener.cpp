#include <ros/ros.h>
#include <std_msgs/String.h>
#include <custom_msg/dataDiri.h>
#include <sstream>

void chatterCallback(const custom_msg::dataDiri::ConstPtr &msg)
{
    ROS_INFO("nama:  %s", msg->nama.c_str());
    ROS_INFO("Umur: %.2lf", msg->umur);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);
    ros::spin();
    return 0;
}