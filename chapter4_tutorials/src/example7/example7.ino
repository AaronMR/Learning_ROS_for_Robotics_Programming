#include <ros.h>
// message type to publish
#include <std_msgs/Float32.h>

// libraries for the accelerometer
#include <Wire.h>
#include <ADXL345.h>

ADXL345 Accel;

ros::NodeHandle  nh;
std_msgs::Float32 velLinear_x;
std_msgs::Float32 velAngular_z;

ros::Publisher velLinear_x_pub("velLinear_x", &velLinear_x);
ros::Publisher velAngular_z_pub("velAngular_z", &velAngular_z);

void setup(){

  nh.initNode();
  nh.advertise(velLinear_x_pub);
  nh.advertise(velAngular_z_pub);
  
  Wire.begin();
  delay(100);
  Accel.set_bw(ADXL345_BW_12);

}

void loop(){
  
  double acc_data[3];
  Accel.get_Gxyz(acc_data);
  
  velLinear_x.data = acc_data[0];
  velAngular_z.data = acc_data[1];
  
  velLinear_x_pub.publish(&velLinear_x);  
  velAngular_z_pub.publish(&velAngular_z);
    
  nh.spinOnce();
  delay(10);
}

