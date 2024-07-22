cmake_minimum_required(VERSION 3.8)
project(plu_virtual_wall)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav2_costmap_2d REQUIRED)
find_package(pluginlib REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(pcl_ros REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)

include_directories(${Boost_INCLUDE_DIRS})
#find_package(costmap_2d REQUIRED)
# Add the plugin source file
add_library(${PROJECT_NAME} SHARED src/virtual_wall_tes1.cpp)
# Add the executable for the node
add_executable(virtual_wall_node src/virtual_wall_node.cpp)
# Specify include directories
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

# Link the necessary libraries
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  nav2_costmap_2d
  pluginlib
  tf2_ros
  geometry_msgs
  pcl_ros
  Boost
  pcl_conversions
  yaml-cpp)
  
# Link the necessary libraries for the node
target_link_libraries(virtual_wall_node ${PROJECT_NAME} yaml-cpp)
# Link Boost libraries to your target
target_link_libraries(${PROJECT_NAME}
  ${Boost_LIBRARIES}
)
# Link the necessary libraries for the node
target_link_libraries(virtual_wall_node
  ${PROJECT_NAME}
  yaml-cpp
  ${Boost_LIBRARIES}
)
ament_target_dependencies(virtual_wall_node
  rclcpp
  nav2_costmap_2d
  pluginlib
  tf2_ros
  geometry_msgs
  pcl_ros
  pcl_conversions
  Boost
  yaml-cpp)

# Export the plugin
pluginlib_export_plugin_description_file(nav2_costmap_2d virtual_wall_ros2_plugin.xml)
# Install the node
install(TARGETS virtual_wall_node
  RUNTIME DESTINATION lib/${PROJECT_NAME})
# Install the plugin library
install(TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  RUNTIME DESTINATION lib/${PROJECT_NAME})

# Install include files
install(DIRECTORY include/
  DESTINATION include)

# Install params files
install(DIRECTORY params
  DESTINATION share/${PROJECT_NAME}/
)

# Install launch files
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
