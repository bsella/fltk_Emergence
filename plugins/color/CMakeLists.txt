cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DCOLOR_PLUGIN)

add_library(color_plugin SHARED color_plugin.cpp)
add_library(color
	color_node.h
	color_node.cpp
	color_node_item.h
	color_node_item.cpp
	rgb_nodes.h
	rgb_nodes.cpp
	rgb_node_items.h
	rgb_node_items.cpp
	hsv_nodes.h
	hsv_nodes.cpp
	hsv_node_items.h
	hsv_node_items.cpp
	)
resource(color.png)
target_link_libraries(color_plugin color color_t real_t)
