#ifndef OBJECT_H_
#define OBJECT_H_

#include "geometry_util.hpp"
#include "probability_util.hpp"

#include "utility_ros_msgs/Object.h"

class Object
{
public:
    size_t id;
    std::string label;
    pd_u::NormalDistribution2d nd2d;
    cv::Point2d position2d;
    cv::Point3d position3d;
    cv::Rect bbPix;

public:
    Object(){};
    ~Object(){};
    Object(utility_ros_msgs::Object msg)
    {
        label = msg.Class;
        bbPix = cv::Rect(msg.bbPix.x, msg.bbPix.y, msg.bbPix.w, msg.bbPix.h);
        position2d = cv::Point2d(msg.position3d.x, msg.position3d.y);
        position3d = cv::Point3d(msg.position3d.x, msg.position3d.y, msg.position3d.z);
    }
};

#endif