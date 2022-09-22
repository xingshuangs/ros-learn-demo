#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv){

    ros::init(argc,argv,"test111");

    ros::NodeHandle n;

    ros::Publisher p = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        /* code */
        geometry_msgs::Twist msg;
        msg.linear.x = 0.5;
        msg.angular.z = 0.2;

        p.publish(msg);
        ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]", 
        msg.linear.x,msg.angular.z);

        loop_rate.sleep();
    }
    

    return 0;
}