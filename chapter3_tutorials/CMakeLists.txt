cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Log4cxx
find_library(LOG4CXX_LIBRARY log4cxx)

#uncomment if you have defined messages
#rosbuild_genmsg()
rosbuild_gensrv()

rosbuild_add_executable(example1 src/example1.cpp)
target_link_libraries(example1 ${LOG4CXX_LIBRARY})

rosbuild_add_executable(example2 src/example2.cpp)
rosbuild_add_executable(example3 src/example3.cpp)
rosbuild_add_executable(example4 src/example4.cpp)
rosbuild_add_executable(example5 src/example5.cpp)
rosbuild_add_executable(example6 src/example6.cpp)
rosbuild_add_executable(example7 src/example7.cpp)

