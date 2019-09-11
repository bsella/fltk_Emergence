cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DBOOL_T_PLUGIN)

add_library(bool_t_plugin SHARED bool_t_plugin.cpp)
add_library(bool_t
	bool_t.h
	bool_t.cpp
	)
target_link_libraries(bool_t_plugin bool_t)
