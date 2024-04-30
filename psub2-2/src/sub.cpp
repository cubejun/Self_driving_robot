#include "psub2-2/sub.hpp"
void Sub::subscribe_msg(const geometry_msgs::msg::Vector3::SharedPtr cnt) const
{
    RCLCPP_INFO(this->get_logger(), "Received: x= %f y= %f y= %f", cnt->x, cnt->y, cnt->z);
}
Sub::Sub() : Node("mysub")
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    sub_ = this->create_subscription<geometry_msgs::msg::Vector3>("mytopic2_2", qos_profile,
    std::bind(&Sub::subscribe_msg, this, _1));
}