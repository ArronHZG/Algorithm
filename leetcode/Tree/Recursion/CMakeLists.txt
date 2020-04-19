
cmake_minimum_required(VERSION 3.15)
project(Recursion)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}
        543-diameter-of-binary-tree.cpp
        110-balanced-binary-tree.cpp
        104-maximum-depth-of-binary-tree.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
