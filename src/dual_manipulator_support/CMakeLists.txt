cmake_minimum_required(VERSION 2.8.3)
project(dual_manipulator_support)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        message_generation
        moveit_core
        moveit_ros_planning
        moveit_ros_planning_interface
        pluginlib
        geometric_shapes
        moveit_visual_tools
        )

catkin_package(
        CATKIN_DEPENDS
        roscpp
        rospy
        std_msgs
        message_runtime
        moveit_core
        moveit_ros_planning_interface
        interactive_markers
        DEPENDS
)

include_directories(
        ${catkin_INCLUDE_DIRS}
)

add_executable(dual_planning src/dual_planning.cpp)
target_link_libraries(dual_planning ${catkin_LIBRARIES})
add_dependencies(dual_planning dual_manipulator_support_gencpp)
