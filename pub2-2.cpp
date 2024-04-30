#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include <memory>
#include <chrono>
#include <functional>
//#include <string>
using namespace std::chrono_literals;
void callback(rclcpp::Node::SharedPtr node, rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr pub)
{
    //static int count;
    //auto message = std_msgs::msg::String();
    auto input = geometry_msgs::msg::Vector3();
    std::cin >> input.x;
    std::cin >> input.y;
    std::cin >> input.z;
    //message.data = "Hello world! " + std::to_string(count++);
    RCLCPP_INFO(node->get_logger(), "Publish: %f %f %f", input.x, input.y, input.z);
    pub->publish(input);
    
}
int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("mynode");
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    auto pub = node->create_publisher<geometry_msgs::msg::Vector3>("mytopic", qos_profile);
    std::function<void()> fn = std::bind(callback, node, pub);
    auto timer = node->create_wall_timer(1s, fn);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}