cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DGRADIENT_PLUGIN)

add_library(gradient_plugin SHARED gradient_plugin.cpp)
add_library(gradient
	gradient.h
	gradient.cpp
	gradient_node.h
	gradient_node.cpp
	gradient_node_item.h
	gradient_node_item.cpp
	)

target_link_libraries(gradient_plugin gradient color_t real_t)
