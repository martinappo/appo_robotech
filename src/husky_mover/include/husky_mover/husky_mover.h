#pragma  once

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "ros/console.h"
#include <keyboard_reader/Key.h>

class HuskyMover {
public:
    HuskyMover();
    void start();

private:
    void keyboardCallback(const keyboard_reader::Key& msg);
    ros::NodeHandle pubHandle, subHandle;
    ros::Publisher pub;
    ros::Subscriber keyboardSub;
    bool move;
};