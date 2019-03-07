cmake_minimum_required(VERSION 3.0.0)
project(MathPlugin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_PATH})

#include_directories(${MAIN_SRC_DIR} ${BIN_SRC_DIR} ${Qt5Widgets_INCLUDE_DIRS})

add_library(${PROJECT_NAME} SHARED MathPlugin.cpp MathPlugin.h)
add_library(math
	MathNode.cpp
	RealNode.cpp
	ComplexNode.cpp
	MathNode.h
	RealNode.h
	fromToStream.cpp
	ComplexNode.h)

target_link_libraries(${PROJECT_NAME} math) 
