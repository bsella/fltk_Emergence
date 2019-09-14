cmake_minimum_required(VERSION 3.12)
project(Emergence)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra -rdynamic")

include_directories(
   ${CMAKE_SOURCE_DIR}/src
   ${CMAKE_SOURCE_DIR}/types
)

macro(resource file_name)
	configure_file(${file_name} ${file_name} COPYONLY)
endmacro()

add_executable(Emergence
	src/main.cpp
	src/core/plugin.h
)

add_subdirectory(src/core)
add_subdirectory(src/gui)
add_subdirectory(types)
add_subdirectory(plugins)

target_link_libraries(Emergence gui core -ldl)
