set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra -fPIC")

add_definitions(-DEMERGENCE_PLUGIN)

add_subdirectory(io)
add_subdirectory(compare)
add_subdirectory(color)
add_subdirectory(math)
