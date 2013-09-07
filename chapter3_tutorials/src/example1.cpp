
#include "ros/ros.h"

#define OVERRIDE_NODE_VERBOSITY_LEVEL 1

int main( int argc, char **argv )
{

  ros::init( argc, argv, "example1" );

#if OVERRIDE_NODE_VERBOSITY_LEVEL
  // Se the logging level manually to DEBUG
  ROSCONSOLE_AUTOINIT;
  log4cxx::LoggerPtr my_logger =
    log4cxx::Logger::getLogger( ROSCONSOLE_DEFAULT_NAME );
  my_logger->setLevel(
    ros::console::g_level_lookup[ros::console::levels::Debug]
  );
#endif

  ros::NodeHandle n;

  const double val = 3.14;

  ROS_DEBUG( "This is a simple DEBUG message!" );

  ROS_DEBUG( "This is a DEBUG message with an argument: %f", val );

  ROS_DEBUG_STREAM(
    "This is DEBUG stream message with an argument: " << val
  );

  ros::spinOnce();

  return EXIT_SUCCESS;

}

