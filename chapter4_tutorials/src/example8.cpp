#include<ros/ros.h>
#include<turtlesim/Velocity.h>
#include<std_msgs/Float32.h>

class TeleopImu{
	public:
		TeleopImu();
	private:
		void velLinearCallBack(const std_msgs::Float32::ConstPtr& vx);
		void velAngularCallBack(const std_msgs::Float32::ConstPtr& wz);
		ros::NodeHandle n;
		ros::Publisher pub;
		ros::Subscriber velAngular_z_sub;
		ros::Subscriber velLinear_x_sub;
		turtlesim::Velocity vel;

};

TeleopImu::TeleopImu()
{	
	pub = n.advertise<turtlesim::Velocity>("turtle1/command_velocity",1);

	velLinear_x_sub = n.subscribe<std_msgs::Float32>("/velLinear_x", 1, &TeleopImu::velLinearCallBack, this);
	velAngular_z_sub = n.subscribe<std_msgs::Float32>("/velAngular_z", 1, &TeleopImu::velAngularCallBack, this);
}


void TeleopImu::velAngularCallBack(const std_msgs::Float32::ConstPtr& wz){
        vel.linear = -1 * wz->data;
        pub.publish(vel);
}

void TeleopImu::velLinearCallBack(const std_msgs::Float32::ConstPtr& vx){
	vel.angular =  vx->data;
        pub.publish(vel);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "example8");
	TeleopImu teleop_turtle;

	ros::spin();
}
