cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DCOLOR_T_PLUGIN)

add_library(color_t_plugin SHARED color_t_plugin.cpp)
add_library(color_t
	color_t.h
	color_t.cpp
	)
target_link_libraries(color_t_plugin color_t)
