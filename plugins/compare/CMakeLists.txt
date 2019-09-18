cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DCOMPARE_PLUGIN)

add_library(compare_plugin SHARED compare_plugin.cpp)
add_library(compare
	if_node.h
	if_node.cpp
	if_node_item.h
	if_node_item.cpp
	compare_nodes.h
	compare_nodes.cpp
	compare_node_items.h
	compare_node_items.cpp
	)

resource(gt.png)
resource(lt.png)
resource(eq.png)
resource(ne.png)
resource(if.png)

target_link_libraries(compare_plugin compare bool_t)
