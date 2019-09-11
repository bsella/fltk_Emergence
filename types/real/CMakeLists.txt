cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DREAL_T_PLUGIN)

add_library(real_t_plugin SHARED real_t_plugin.cpp)
add_library(real_t
	real_t.h
	real_t.cpp
	)
target_link_libraries(real_t_plugin real_t)
