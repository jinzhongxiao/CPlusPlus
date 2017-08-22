#include <iostream>
using namespace std;
#include <ros/ros.h>
//#include "tf/Transform.h"
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>

int main(int argc, char ** argv){
  tf::Transform transform1, transform2;
//a :world      b:  kinect    c:beer
  //Rab: b在a中表示
  transform1.setOrigin(tf::Vector3(1.1306105592788473, -0.023380240667990177, 0.14249669943110535));
  tf::Quaternion q1(-7.527518111164107e-06, 5.9763349822339885e-06, 3, 0.6004010900676073);
  transform1.setRotation(q1);
  //Rac:  beer (c)在a 中表示
  transform2.setOrigin(tf::Vector3(4.317941566083451, 1.5709863840103493, 0.05491839929534929));
  tf::Quaternion q2(-0.32174980469150205, 0.6295233496884052, -0.629746763082377, -0.32186399265114907);
  transform2.setRotation(q2);
//求c在a中表示
  transform1.mult(transform1.inverse(), transform2);


  tf::Vector3 ty = transform1.getOrigin();
  tf::Quaternion qq = transform1.getRotation();

  cout<<"("<< ty[0] <<","<<ty[1]<<","<<ty[2]<<")"<<endl;

  cout<<"("<< qq.getX()<<","<< qq.getY()<<","<< qq.getZ()<<","<< qq.getW()<<","<<")"<<endl;;
  return 0;
}
