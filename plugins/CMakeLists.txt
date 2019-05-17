set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_definitions(-DEMERGENCE_PLUGIN)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra -fPIC")

add_subdirectory(io)
add_subdirectory(condition)
