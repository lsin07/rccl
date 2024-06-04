// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/rccltest/RcclTestStubDefault.hpp>
// #include "SpeedControlStubImpl.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class RcclTestStubImpl: public v1_0::rccltest::RcclTestStubDefault
{
  public:
    RcclTestStubImpl() {}
    virtual ~RcclTestStubImpl() {}
    virtual void hello(std::string message) {
      RcclTestStubDefault::fireHelloEvent(message);
    }
};

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::string domain = "local";
    std::string instance = "RcclTest";
    std::string connection = "RcclTestTalker";
    myService = std::make_shared<RcclTestStubImpl>();
    runtime->registerService(domain, instance, myService, connection);
    // std::cout << "Service Registered Successfully." << std::endl;
    
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic_Test", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  void rccl_publish(const std_msgs::msg::String & message)
  {
    // data repacker (for string only)
    std::string message_str(message.data.c_str());
  
    // RCLCPP_INFO(this->get_logger(), "About to publish message: '%s'", message.data.c_str());
    // Additional modifications or checks can be added here
    publisher_->publish(message);
    myService->hello(message_str);
  }
  void timer_callback()
  {
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    this->rccl_publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
  std::shared_ptr<RcclTestStubImpl> myService;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
