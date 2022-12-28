from launch import LaunchDescription
from launch_ros.actions import Node
import os
import yaml
import launch_ros.actions
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='record_pcd',
            executable='record_pcd_node',
            name='record_pcd_node',
            remappings=[
                ("/pointcloud_in", "/depth/color/points")
            ],
            output='both'
        ),
        Node(
            package='realsense2_camera',
            executable='realsense2_camera_node',
            name='scanning_camera',
            parameters=[
                {'enable_fisheye1': True},
                {'enable_fisheye2': True},
                {'enable_infra1': False},
                {'enable_infra2': False},
                {'enable_depth': True},
                {'enable_color': True},
                {'pointcloud.enable': True},
            ],
            output='screen',
            emulate_tty=True,
        ),
    ])
