import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/install/turtlebot3_example'
