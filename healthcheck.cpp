#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "iostream"
#include "cstdlib"

using namespace std::chrono_literals;

#define TIMEOUT 2s

int msg_received = EXIT_FAILURE;

void msg_callback(const sensor_msgs::msg::Image::SharedPtr msg)
{
  std::cout << "Message received" << std::endl;
  msg_received = EXIT_SUCCESS;
  rclcpp::shutdown();
}

void timeout_callback()
{
  std::cout << "Timeout" << std::endl;
  rclcpp::shutdown();
}

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("healthcheck_node");
  char* zed = std::getenv("CAMERA_LAUNCH");

  if (zed)
  {
    std::string zed_str(zed);
    zed_str = zed_str.substr(0, zed_str.find('.'));
    std::string topic_name = "/" + zed_str + "/zed_node/rgb/image_rect_color";

    std::cout << topic_name <<std::endl;
    auto sub = node->create_subscription<sensor_msgs::msg::Image>(topic_name, rclcpp::SensorDataQoS(), msg_callback);

    auto timer = node->create_wall_timer(TIMEOUT, timeout_callback);

    rclcpp::spin(node);
    return msg_received;
  }
  else
  {
    std::cerr << "CAMERA_LAUNCH environment variable not set" << std::endl;
    return EXIT_FAILURE;
  }
}
