from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='plu_virtual_wall',
            executable='virtual_wall_node',
            name='virtual_wall_node',
            output='screen',
            parameters=["/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/plu_virtual_wall/config/virtual_wall_params.yaml"]
        ),
        # Node(
        #     package='tf2_ros',
        #     executable='static_transform_publisher',
        #     #name='static_transform_publisher',
        #     arguments=['0', '0', '0', '0', '0', '0', 'map', 'base_link']
        # )
    ])
