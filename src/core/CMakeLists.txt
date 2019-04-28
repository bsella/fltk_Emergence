cmake_minimum_required(VERSION 3.5)


include_directories(
   ${CMAKE_SOURCE_DIR}
)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra")

add_library(core
	node.h
	node.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
add_library(plugin
	plugin.h
	plugin.cpp
)
