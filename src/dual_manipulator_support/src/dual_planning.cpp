#include "ros/ros.h"
#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv) {
    ros::init(argc, argv, "dual_planning");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
    moveit_msgs::DisplayTrajectory display_trajectory;

    moveit::planning_interface::MoveGroup group1("dual_manipulator");
    moveit::planning_interface::PlanningSceneInterface planningSceneInterface;
    moveit::planning_interface::MoveGroup::Plan my_plan;

    std::vector<geometry_msgs::Pose> waypoints;

    geometry_msgs::Pose target_pose = group1.getCurrentPose().pose;
    waypoints.push_back(target_pose);


    target_pose.position.z -= 0.2;
    waypoints.push_back(target_pose);

    target_pose.position.y -= 0.2;
    waypoints.push_back(target_pose);

    target_pose.position.y += 0.1;
    target_pose.position.z += 0.1;
    waypoints.push_back(target_pose);


    moveit_msgs::RobotTrajectory trajectory;
    double fraction = group1.computeCartesianPath(waypoints,
                                                 0.01,  // eef_step
                                                 0.0,   // jump_threshold
                                                 trajectory);
    my_plan.trajectory_ = trajectory;

    ROS_INFO("Visualizing plan 4 (cartesian path) (%.2f%% acheived)",
             fraction * 100.0);
    sleep(5.0);

    ROS_INFO("Moving");
    group1.execute(my_plan);
    //group.move();
    sleep(5.0);
}
