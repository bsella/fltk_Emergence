cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DCOMPLEX_T_PLUGIN)

add_library(complex_t_plugin SHARED complex_t_plugin.cpp)
add_library(complex_t
	complex_t.h
	complex_t.cpp
	)
target_link_libraries(complex_t_plugin complex_t)
