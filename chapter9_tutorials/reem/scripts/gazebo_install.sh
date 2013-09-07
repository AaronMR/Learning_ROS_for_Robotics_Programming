#!/bin/bash

# Setup packages.osrfoundation.org sources:
sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu quantal main" > /etc/apt/sources.list.d/gazebo-latest.list'
wget http://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -

# Instal gazebo:
sudo apt-get update
sudo apt-get install gazebo

# Source setup.sh in .bashrc:
echo "source /usr/share/gazebo/setup.sh" >> ~/.bashrc
source ~/.bashrc

