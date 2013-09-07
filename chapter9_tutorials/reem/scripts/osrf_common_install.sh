#!/bin/bash

# Download osrf-common:
cd $HOME/ros/stacks
hg clone ssh://hg@bitbucket.org/osrf/osrf-common

# Make and install osrf-common:
cd osrf-common
mkdir build
cd build
cmake ..
make
sudo make install

