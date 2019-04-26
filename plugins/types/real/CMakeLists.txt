cmake_minimum_required(VERSION 3.0.0)

add_library(real_t_plugin SHARED real_t_plugin.cpp real_t_plugin.h)
add_library(real_t
	real_t.cpp
	real_t.h
	)
target_link_libraries(real_t_plugin real_t)
