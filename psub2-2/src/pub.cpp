#include "psub2-2/pub.hpp"
Pub::Pub() : Node("mypub"), count_(0)
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    pub_ = this->create_publisher<geometry_msgs::msg::Vector3>("mytopic2_2", qos_profile);
    timer_ = this->create_wall_timer(1s, std::bind(&Pub::publish_msg, this));
}
void Pub::publish_msg()
{
    auto cnt = geometry_msgs::msg::Vector3();
    cnt.x = cnt.y = cnt.z = count_++;
    RCLCPP_INFO(this->get_logger(), "Published: x= %f y= %f y= %f", cnt.x, cnt.y, cnt.z);
    pub_->publish(cnt);
}