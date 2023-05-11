#!/bin/bash
set -e

# setup ros environment
source "/opt/ros/$ROS_DISTRO/setup.bash"
catkin_make -DCMAKE_BUILD_TYPE=Release || true
source "/ros_ws/devel/setup.bash"

exec "$@"