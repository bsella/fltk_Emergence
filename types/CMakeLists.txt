set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib_t)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -Wextra -fPIC")

add_subdirectory(real)
add_subdirectory(bool)
add_subdirectory(color)
