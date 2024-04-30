#include "psub2-1/sub.hpp"
void Sub::subscribe_msg(const std_msgs::msg::Int32::SharedPtr cnt) const
{
    RCLCPP_INFO(this->get_logger(), "Received message: %d", cnt->data);
}
Sub::Sub() : Node("mysub")
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    sub_ = this->create_subscription<std_msgs::msg::Int32>("mytopic2_1", qos_profile,
    std::bind(&Sub::subscribe_msg, this, _1));
}