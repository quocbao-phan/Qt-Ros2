import os
import argparse
import sys
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
	gui_node = Node(
		package="tomo_ui",
		executable="tomo_ui",
		output="screen",
	)
	return LaunchDescription([gui_node])