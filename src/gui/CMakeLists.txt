cmake_minimum_required(VERSION 3.5)

set(FLTK_SKIP_OPENGL true)
set(FLTK_SKIP_FLUID true)
find_package(FLTK REQUIRED)

include_directories(
   ${CMAKE_SOURCE_DIR}
   ${FLTK_INCLUDE_DIR}
)

add_library(graphics_view
	graphics_view.cpp
	graphics_view.h
	item.cpp
	item.h
)

add_library(workspace
	workspace.cpp
	workspace.h
	node_item.cpp
	node_item.h
)
target_link_libraries(workspace graphics_view core)

add_library(gui
	main_window.cpp
	main_window.h
)

add_library(toolbox
	toolbox/toolbox.cpp
	toolbox/toolbox.h
	toolbox/toolbox_item.cpp
	toolbox/toolbox_item.h
	toolbox/toolbox_category.cpp
	toolbox/toolbox_category.h
	toolbox/toolbox_node_item.cpp
	toolbox/toolbox_node_item.h
)
resource(toolbox/open.png)
resource(toolbox/closed.png)
target_link_libraries(toolbox graphics_view)

target_link_libraries(gui -Wl,--whole-archive workspace toolbox -Wl,--no-whole-archive ${FLTK_LIBRARIES})
#target_link_libraries(gui workspace toolbox ${FLTK_LIBRARIES})
