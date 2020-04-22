cmake_minimum_required(VERSION 3.15)
project(Algorithm)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)

set(LIBRARIES
        gtest
        gtest_main
        pthread
        utils)

add_subdirectory(utils)
add_subdirectory(test)
add_subdirectory(leetcode)
add_subdirectory(DeepGlint)
add_subdirectory(alibaba)
add_subdirectory(Nowcoder)


