# CMake generated Testfile for 
# Source directory: /home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/navigation2/nav2_voxel_grid/test
# Build directory: /home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(voxel_grid_tests "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test_results/nav2_voxel_grid/voxel_grid_tests.gtest.xml" "--package-name" "nav2_voxel_grid" "--output-file" "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/ament_cmake_gtest/voxel_grid_tests.txt" "--command" "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test/voxel_grid_tests" "--gtest_output=xml:/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test_results/nav2_voxel_grid/voxel_grid_tests.gtest.xml")
set_tests_properties(voxel_grid_tests PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test/voxel_grid_tests" TIMEOUT "60" WORKING_DIRECTORY "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/navigation2/nav2_voxel_grid/test/CMakeLists.txt;1;ament_add_gtest;/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/navigation2/nav2_voxel_grid/test/CMakeLists.txt;0;")
add_test(voxel_grid_bresenham_3d "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test_results/nav2_voxel_grid/voxel_grid_bresenham_3d.gtest.xml" "--package-name" "nav2_voxel_grid" "--output-file" "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/ament_cmake_gtest/voxel_grid_bresenham_3d.txt" "--command" "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test/voxel_grid_bresenham_3d" "--gtest_output=xml:/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test_results/nav2_voxel_grid/voxel_grid_bresenham_3d.gtest.xml")
set_tests_properties(voxel_grid_bresenham_3d PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test/voxel_grid_bresenham_3d" TIMEOUT "60" WORKING_DIRECTORY "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/build/nav2_voxel_grid/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/navigation2/nav2_voxel_grid/test/CMakeLists.txt;4;ament_add_gtest;/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/navigation2/nav2_voxel_grid/test/CMakeLists.txt;0;")
subdirs("../gtest")
