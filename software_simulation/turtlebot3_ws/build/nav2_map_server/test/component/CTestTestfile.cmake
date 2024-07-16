# CMake generated Testfile for 
# Source directory: /home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test/component
# Build directory: /home/khanh247/software_simulation/turtlebot3_ws/build/nav2_map_server/test/component
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_map_server_node "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_map_server/test_results/nav2_map_server/test_map_server_node.xml" "--package-name" "nav2_map_server" "--generate-result-on-success" "--env" "TEST_DIR=/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test" "TEST_LAUNCH_DIR=/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test/test_launch_files" "TEST_EXECUTABLE=/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_map_server/test/component/test_map_server_node" "--command" "/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test/component/test_map_server_launch.py")
set_tests_properties(test_map_server_node PROPERTIES  TIMEOUT "60" WORKING_DIRECTORY "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_map_server/test/component" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test/component/CMakeLists.txt;13;ament_add_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test/component/CMakeLists.txt;0;")
add_test(test_map_saver_node "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_map_server/test_results/nav2_map_server/test_map_saver_node.xml" "--package-name" "nav2_map_server" "--generate-result-on-success" "--env" "TEST_DIR=/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test" "TEST_LAUNCH_DIR=/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test/test_launch_files" "TEST_EXECUTABLE=/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_map_server/test/component/test_map_saver_node" "--command" "/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test/component/test_map_saver_launch.py")
set_tests_properties(test_map_saver_node PROPERTIES  TIMEOUT "60" WORKING_DIRECTORY "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_map_server/test/component" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test/component/CMakeLists.txt;43;ament_add_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_map_server/test/component/CMakeLists.txt;0;")
