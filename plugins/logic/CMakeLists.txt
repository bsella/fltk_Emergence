cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DLOGIC_PLUGIN)

add_library(logic_plugin SHARED logic_plugin.cpp)
add_library(logic
	logic_nodes.h
	logic_nodes.cpp
	logic_node_items.h
	logic_node_items.cpp
	)

resource(and.png)
resource(or.png)
resource(xor.png)
resource(not.png)

target_link_libraries(logic_plugin logic bool_t)
