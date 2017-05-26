#include "husky_mover/husky_mover.h"

HuskyMover::HuskyMover() {
    move = false;
}

void HuskyMover::keyboardCallback(const keyboard_reader::Key& keyMsg) {
    ROS_INFO("## Received key ##");
    if (keyMsg.key_pressed) {
        move = !move;
    }
}

void HuskyMover::start() {
    ROS_INFO("## Mover started ##");

    pub = pubHandle.advertise<geometry_msgs::Twist>("husky_mover/cmd_vel", 100);
    keyboardSub = subHandle.subscribe("/keyboard", 10, &HuskyMover::keyboardCallback, this);

    ros::Rate loop_rate(10);

    geometry_msgs::Twist msg;
    msg.angular.z=10;
    while (ros::ok()) {
        if (move) {
            pub.publish(msg);
        }
        loop_rate.sleep();
        ros::spinOnce();
    }
}