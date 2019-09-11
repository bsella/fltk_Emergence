cmake_minimum_required(VERSION 3.5)

include_directories(
   ${CMAKE_SOURCE_DIR}
)

#set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra")

add_library(core
	node.h
	node.cpp
	)
add_library(type_manager
	type_manager.h
	type_manager.cpp
	)
add_library(data_t
	data_t.h
	data_t.cpp
)

target_link_libraries(core type_manager -Wl,--whole-archive data_t -Wl,--no-whole-archive)
