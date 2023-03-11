/*
 * yolo_obstacle_detector_node.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: Marko Bjelonic
 *   Institute: ETH Zurich, Robotic Systems Lab
 */

#include "darknet_ros/YoloObjectDetector.hpp"
#include <am_utils/am_ros2_utility.h>

std::shared_ptr<am::AMLifeCycle> am::Node::node;


int main(int argc, char** argv) {
  rclcpp::init(argc, argv);


  am::Node::node = std::make_shared<am::AMLifeCycle>("darknet_ros");

  auto yoloObjectDetector = std::make_shared<darknet_ros::YoloObjectDetector>();

  yoloObjectDetector->init();
  
  rclcpp::spin(am::Node::node);

  rclcpp::shutdown();

  return 0;
}
