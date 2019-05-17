cmake_minimum_required(VERSION 3.5)
project(Emergence)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra -rdynamic")

include_directories(
   ${CMAKE_SOURCE_DIR}/src
)

add_executable(Emergence
	src/main.cpp
	src/core/plugin.h
)

add_subdirectory(src/gui)
add_subdirectory(src/core)
add_subdirectory(plugins)

set(CMAKE_EXE_LINKER_FLAGS "-ldl")
target_link_libraries(Emergence gui core)
