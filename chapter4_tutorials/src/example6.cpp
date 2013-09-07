#include<ros/ros.h>
#include<turtlesim/Velocity.h>
#include<sensor_msgs/Imu.h>
#include<iostream>
#include<tf/LinearMath/Matrix3x3.h>
#include<tf/LinearMath/Quaternion.h>

using namespace std;

class TeleopImu{
	public:
		TeleopImu();
	private:
		void callBack(const sensor_msgs::Imu::ConstPtr& imu);
		ros::NodeHandle n;
		ros::Publisher pub;
		ros::Subscriber sub;
};

TeleopImu::TeleopImu()
{	
	pub = n.advertise<turtlesim::Velocity>("turtle1/command_velocity",1);
	sub = n.subscribe<sensor_msgs::Imu>("imu", 10, &TeleopImu::callBack, this);
}

void TeleopImu::callBack(const sensor_msgs::Imu::ConstPtr& imu)
{

	turtlesim::Velocity vel;
	

	tf::Quaternion bq(imu->orientation.x,imu->orientation.y,imu->orientation.z,imu->orientation.w);
   	double roll,pitch,yaw;
   	tf::Matrix3x3(bq).getRPY(roll,pitch,yaw);

	
	vel.angular = roll;
	vel.linear = pitch;
	pub.publish(vel);

}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "teleopImu");
	TeleopImu teleop_turtle;

	ros::spin();
}
