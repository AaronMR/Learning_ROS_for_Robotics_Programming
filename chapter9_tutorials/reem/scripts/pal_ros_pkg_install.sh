#!/bin/bash

# Install dependencies:
./gazebo_install.sh
./osrf_common_install.sh

sudo apt-get install ros-groovy-pr2-simulator
sudo apt-get install libglew-dev libdevil-dev

# Set environment:
roscd pal_install
cd scripts
cat environment/pal_ros_pkg_environment.sh >> ~/.bashrc

# Create pal-ros-pkg dir:
mkdir -p ~/ros/stacks/pal-ros-pkg
cd ~/ros/stacks/pal-ros-pkg

# Download repositories:
rosinstall . https://raw.github.com/pal-robotics/pal-ros-pkg/master/pal-ros-pkg-gazebo-standalone.rosinstall

# Update environment:
rosstack profile && rospack profile
source ~/.bashrc

# Build everything (atlas_msgs not if drcsim install; move_arm not if ros-*-arm-experimental installed):
stacks=(atlas_msgs pal_gazebo_plugins pal_image_processing perception_blort reem_arm_navigation reem_common reem_controllers reem_kinematics reem_msgs reem_robot reem_simulation)

for stack in ${stacks[@]}
do
	rosmake -i $stack
done

