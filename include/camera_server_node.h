#pragma once
#include "camera.h"
#include "camera_utils.h"
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>

constexpr int LUMINOSITY_PUB_TIMER_MS = 1000;
constexpr char CAMERA_SERVER_NODE_NAME[] = "camera_server_node";

class CameraServerNode : public rclcpp::Node, protected camera_driver::Camera
{
  public:
    CameraServerNode();
    CameraServerNode(std::string name, std::string type, int index, int fps);
    ~CameraServerNode();

  private:
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr luminosityPub_;
    rclcpp::TimerBase::SharedPtr timer_;

    void InitializeCameraServer();
    void Start();
    void Stop();
};