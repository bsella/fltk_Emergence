cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DCOLOR_PLUGIN)

add_library(color_plugin SHARED color_plugin.cpp)
add_library(color
	color_node.h
	color_node.cpp
	color_node_item.h
	color_node_item.cpp
	rgb_node.h
	rgb_node.cpp
	rgb_node_item.h
	rgb_node_item.cpp
	)
resource(color.png)
target_link_libraries(color_plugin color color_t real_t)
