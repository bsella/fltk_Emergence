cmake_minimum_required(VERSION 3.5)

include_directories(
   ${CMAKE_SOURCE_DIR}
)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra")

add_library(core
	node.h
	node.cpp
)
