cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DIMAGE_PLUGIN)

add_library(image_plugin SHARED image_plugin.cpp)
add_library(image
	image_node.h
	image_node.cpp
	image_node_item.h
	image_node_item.cpp
	)

resource(image.png)

target_link_libraries(image_plugin image color_t)
