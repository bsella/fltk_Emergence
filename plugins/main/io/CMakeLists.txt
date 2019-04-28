cmake_minimum_required(VERSION 3.0.0)

#include_directories()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
add_library(io_plugin SHARED io_plugin.cpp)
add_library(io
	input_node.h
	input_node.cpp
	input_node_item.h
	input_node_item.cpp
	)
target_link_libraries(io_plugin io gui real_t)
