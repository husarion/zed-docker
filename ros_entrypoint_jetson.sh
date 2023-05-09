#!/bin/bash
set -e

# setup ros environment
source "/opt/ros/$ROS_DISTRO/setup.bash"
catkin_make -DCMAKE_BUILD_TYPE=Release
source "/ros_ws/devel/setup.bash"

# Welcome information
echo "ZED ROS Docker Image"
echo "---------------------"
echo 'ROS distro: ' $ROS_DISTRO
echo "---------------------"    

exec "$@"