#include "ros/ros.h"
#include "husky_mover/husky_mover.h"
#include <sstream>

int main(int argc, char **argv)
{

    ros::init(argc, argv, "husky_mover");
    ros::start();
    ros::Rate loop_rate(10);


    HuskyMover huskyMover;
    huskyMover.start();

    return 0;
}