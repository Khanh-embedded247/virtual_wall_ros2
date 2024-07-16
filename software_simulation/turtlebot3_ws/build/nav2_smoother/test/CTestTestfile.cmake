# CMake generated Testfile for 
# Source directory: /home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_smoother/test
# Build directory: /home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_smoother_server "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test_results/nav2_smoother/test_smoother_server.gtest.xml" "--package-name" "nav2_smoother" "--output-file" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/ament_cmake_gtest/test_smoother_server.txt" "--command" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test/test_smoother_server" "--gtest_output=xml:/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test_results/nav2_smoother/test_smoother_server.gtest.xml")
set_tests_properties(test_smoother_server PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test/test_smoother_server" TIMEOUT "60" WORKING_DIRECTORY "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_smoother/test/CMakeLists.txt;1;ament_add_gtest;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_smoother/test/CMakeLists.txt;0;")
add_test(test_simple_smoother "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test_results/nav2_smoother/test_simple_smoother.gtest.xml" "--package-name" "nav2_smoother" "--output-file" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/ament_cmake_gtest/test_simple_smoother.txt" "--command" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test/test_simple_smoother" "--gtest_output=xml:/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test_results/nav2_smoother/test_simple_smoother.gtest.xml")
set_tests_properties(test_simple_smoother PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test/test_simple_smoother" TIMEOUT "60" WORKING_DIRECTORY "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_smoother/test/CMakeLists.txt;13;ament_add_gtest;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_smoother/test/CMakeLists.txt;0;")
add_test(test_savitzky_golay_smoother "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test_results/nav2_smoother/test_savitzky_golay_smoother.gtest.xml" "--package-name" "nav2_smoother" "--output-file" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/ament_cmake_gtest/test_savitzky_golay_smoother.txt" "--command" "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test/test_savitzky_golay_smoother" "--gtest_output=xml:/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test_results/nav2_smoother/test_savitzky_golay_smoother.gtest.xml")
set_tests_properties(test_savitzky_golay_smoother PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test/test_savitzky_golay_smoother" TIMEOUT "60" WORKING_DIRECTORY "/home/khanh247/software_simulation/turtlebot3_ws/build/nav2_smoother/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_smoother/test/CMakeLists.txt;26;ament_add_gtest;/home/khanh247/software_simulation/turtlebot3_ws/src/navigation2/nav2_smoother/test/CMakeLists.txt;0;")
subdirs("../gtest")
