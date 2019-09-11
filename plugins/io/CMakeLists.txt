cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DIO_PLUGIN)

add_library(io_plugin SHARED io_plugin.cpp)
add_library(io
	input_node.h
	input_node.cpp
	input_node_item.h
	input_node_item.cpp
	output_node.h
	output_node.cpp
	output_node_item.h
	output_node_item.cpp
	)
target_link_libraries(io_plugin io real_t)
