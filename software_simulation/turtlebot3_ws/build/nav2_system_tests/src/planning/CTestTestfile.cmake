# CMake generated Testfile for 
# Source directory: /home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning
# Build directory: /home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_planner_costmaps "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/test_results/nav2_system_tests/test_planner_costmaps.xml" "--package-name" "nav2_system_tests" "--generate-result-on-success" "--env" "TEST_LAUNCH_DIR=" "TEST_EXECUTABLE=/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning/test_planner_costmaps_node" "TEST_MAP=/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/maps/map.pgm" "--command" "/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning/test_planner_costmaps_launch.py")
set_tests_properties(test_planner_costmaps PROPERTIES  TIMEOUT "60" WORKING_DIRECTORY "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning/CMakeLists.txt;29;ament_add_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning/CMakeLists.txt;0;")
add_test(test_planner_random "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/test_results/nav2_system_tests/test_planner_random.xml" "--package-name" "nav2_system_tests" "--generate-result-on-success" "--env" "TEST_LAUNCH_DIR=" "TEST_EXECUTABLE=/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning/test_planner_random_node" "TEST_MAP=/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/maps/map.pgm" "--command" "/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning/test_planner_random_launch.py")
set_tests_properties(test_planner_random PROPERTIES  TIMEOUT "60" WORKING_DIRECTORY "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning/CMakeLists.txt;39;ament_add_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning/CMakeLists.txt;0;")
add_test(test_planner_plugins "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/test_results/nav2_system_tests/test_planner_plugins.gtest.xml" "--package-name" "nav2_system_tests" "--output-file" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/ament_cmake_gtest/test_planner_plugins.txt" "--command" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning/test_planner_plugins" "--gtest_output=xml:/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/test_results/nav2_system_tests/test_planner_plugins.gtest.xml")
set_tests_properties(test_planner_plugins PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning/test_planner_plugins" TIMEOUT "10" WORKING_DIRECTORY "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning/CMakeLists.txt;49;ament_add_gtest;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning/CMakeLists.txt;0;")
add_test(test_planner_is_path_valid "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/test_results/nav2_system_tests/test_planner_is_path_valid.gtest.xml" "--package-name" "nav2_system_tests" "--output-file" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/ament_cmake_gtest/test_planner_is_path_valid.txt" "--command" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning/test_planner_is_path_valid" "--gtest_output=xml:/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/test_results/nav2_system_tests/test_planner_is_path_valid.gtest.xml")
set_tests_properties(test_planner_is_path_valid PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning/test_planner_is_path_valid" TIMEOUT "60" WORKING_DIRECTORY "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_system_tests/src/planning" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning/CMakeLists.txt;59;ament_add_gtest;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_system_tests/src/planning/CMakeLists.txt;0;")
