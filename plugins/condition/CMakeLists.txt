cmake_minimum_required(VERSION 3.0.0)

add_library(condition_plugin SHARED condition_plugin.cpp)
add_library(condition
	if_node.h
	if_node.cpp
	if_node_item.h
	if_node_item.cpp
	)
target_link_libraries(condition_plugin condition)
