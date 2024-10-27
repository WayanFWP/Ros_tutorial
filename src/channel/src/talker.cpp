#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <custom_msg/dataDiri.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::Publisher chatter_pub = nh.advertise<custom_msg::dataDiri>("chatter", 1000);
    ros::Rate loop_rate(10);

    float count = 0;
    while (ros::ok())
    {
        custom_msg::dataDiri msg;
        std::stringstream ss;
        ss << "wayan " << count;
        msg.nama = ss.str();
        msg.umur = count;

        ROS_INFO("namanya %s", msg.nama.c_str());

        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        count +=0.1;
    }

    return 0;
}