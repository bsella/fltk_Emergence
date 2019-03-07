cmake_minimum_required(VERSION 3.5)
project(Emergence)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra")

#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

include_directories(
   ${CMAKE_SOURCE_DIR}/src
)

add_executable(Emergence
	src/main.cpp
)

add_subdirectory(src/gui)
add_subdirectory(src/core)

target_link_libraries(Emergence gui core)
