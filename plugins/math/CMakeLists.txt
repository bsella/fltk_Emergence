cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DMATH_PLUGIN)

add_library(math_plugin SHARED math_plugin.cpp)
add_library(math
	math_nodes.h
	math_nodes.cpp
	#lerp.h
	#lerp.cpp
	math_node_items.h
	math_node_items.cpp
	#lerp_items.h
	#lerp_items.cpp
	func_def.h
	func_def.cpp
	)
target_link_libraries(math_plugin math real_t)
