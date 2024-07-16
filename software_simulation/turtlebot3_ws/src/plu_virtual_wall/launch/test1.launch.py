from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='plu_virtual_wall',
            executable='virtual_wall_node',
            name='virtual_wall_node',
            output='screen',
            parameters=[
                {'virtual_wall_points': '/home/khanh247/software_simulation/turtlebot3_ws/src/plu_virtual_wall/positions.yaml'},
                {'global_frame': 'map'}
            ]
        )
    ])
