# Gazebo - atlas_msgs; not required if drcsim is installed
export GAZEBO_PLUGIN_PATH="`rospack find atlas_msgs`/lib:$GAZEBO_PLUGIN_PATH"
export LD_LIBRARY_PATH="`rospack find atlas_msgs`/lib:$LD_LIBRARY_PATH"

# Gazebo - PAL
export GAZEBO_PLUGIN_PATH="`rospack find pal_gazebo_plugins`/lib:$GAZEBO_PLUGIN_PATH"
export LD_LIBRARY_PATH="`rospack find pal_gazebo_plugins`/lib:$LD_LIBRARY_PATH"

# Gazebo - REEM-H3
export GAZEBO_MODEL_PATH="`rospack find reem_gazebo`/models:$GAZEBO_MODEL_PATH"
export GAZEBO_RESOURCE_PATH="`rospack find reem_gazebo`/worlds:$GAZEBO_RESOURCE_PATH"

