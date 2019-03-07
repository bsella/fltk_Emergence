cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra")

include_directories(
   ${CMAKE_SOURCE_DIR}
)

FILE(GLOB HEADERS
	*.h
)

add_library(core
	${HEADERS}
	node.cpp
)
