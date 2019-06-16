cmake_minimum_required(VERSION 3.5)

include_directories(
   ${CMAKE_SOURCE_DIR}
)

#set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra")

add_library(core
	node.h
	node.cpp
	)
add_library(data
	data_t.h
	data_t.cpp
)

add_library(real
	real_t.h
	real_t.cpp
)

add_library(bool
	bool_t.h
	bool_t.cpp
)

target_link_libraries(core -Wl,--whole-archive data real bool -Wl,--no-whole-archive)
