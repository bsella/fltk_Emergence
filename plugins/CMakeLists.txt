set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_definitions(-DEMERGENCE_PLUGIN)
add_subdirectory(io)
add_subdirectory(condition)
