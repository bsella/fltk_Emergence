cmake_minimum_required(VERSION 3.5)

include_directories(
   ${CMAKE_SOURCE_DIR}
)

#set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra")

add_library(core
	node.h
	node.cpp
	)
add_library(data_t
	data_t.h
	data_t.cpp
)

add_library(real_t
	real_t.h
	real_t.cpp
)

add_library(bool_t
	bool_t.h
	bool_t.cpp
)

add_library(color_t
	color_t.h
	color_t.cpp
)

target_link_libraries(core -Wl,--whole-archive data_t real_t bool_t color_t -Wl,--no-whole-archive)
