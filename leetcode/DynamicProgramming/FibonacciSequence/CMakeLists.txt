cmake_minimum_required(VERSION 3.15)
project(DynamicProgramming)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        pthread)

add_executable(${PROJECT_NAME}
        213-house-robber-ii.cpp
        198-house-robber.cpp
        96-unique-binary-search-trees.cpp
        70-climbing-stairs.cpp sum-fibon.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})