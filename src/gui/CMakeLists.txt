cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra")

set(FLTK_SKIP_OPENGL true)
set(FLTK_SKIP_FLUID true)
find_package(FLTK REQUIRED)

include_directories(
   ${CMAKE_SOURCE_DIR}
   ${FLTK_INCLUDE_DIR}
)

FILE(GLOB HEADERS
	*.h
)

add_library(gui
	${HEADERS}
	main_window.cpp
	node_box.cpp
	graphics_view.cpp
	workspace.cpp
	item.cpp
	node_item.cpp
)

target_link_libraries(gui ${FLTK_LIBRARIES})
