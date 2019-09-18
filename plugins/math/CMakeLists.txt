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
	#lerp_node_items.h
	#lerp_node_items.cpp
	real_node.h
	real_node.cpp
	real_node_item.h
	real_node_item.cpp
	)

add_library(real_chooser
	real_chooser.h
	real_chooser.cpp
	)

resource(add.png)
resource(subtract.png)
resource(multiply.png)
resource(divide.png)
resource(neg.png)
resource(sqrt.png)
resource(sin.png)
resource(cos.png)
resource(real.png)

target_link_libraries(real_chooser real_t)
target_link_libraries(math_plugin math real_chooser real_t)
