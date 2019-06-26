cmake_minimum_required(VERSION 3.0.0)

#include_directories()

add_library(color_plugin SHARED color_plugin.cpp)
add_library(color
	color_node.h
	color_node.cpp
	color_node_item.h
	color_node_item.cpp
	)
target_link_libraries(color_plugin color)
