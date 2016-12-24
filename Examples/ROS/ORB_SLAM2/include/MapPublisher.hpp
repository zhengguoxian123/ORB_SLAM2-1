#ifndef MAPPUBLISHER_H
#define MAPPUBLISHER_H

#include<vector>
#include<opencv2/core/core.hpp>
#include<ros/ros.h>
#include <visualization_msgs/Marker.h>
#include<pcl/point_cloud.h>  
#include<pcl_conversions/pcl_conversions.h>  
#include<sensor_msgs/PointCloud2.h> 
namespace ROS_ORB_SLAM
{
class MapPublisher
{
public:
  MapPublisher();
  void PublishCurrentCamera(const cv::Mat &Tcw);
  //void PublishMapPoints(const std::vector<MapPoint*> &vpMPs);
  void PublishMapPoints(pcl::PointCloud<pcl::PointXYZ> &cloud);
private: 
  ros::NodeHandle nh;
  ros::Publisher publisher;
  float fCameraSize;
  float fPointSize;
  visualization_msgs::Marker mPoints;
  visualization_msgs::Marker mCurrentCamera;
};
} // namespace ROS_ORB_SLAM

#endif // MAPPUBLISHER_H

