cmake_minimum_required(VERSION 3.15)
project(Algorithm)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        pthread)

add_subdirectory(Utils)
add_subdirectory(Test)
add_subdirectory(LeetCode)


