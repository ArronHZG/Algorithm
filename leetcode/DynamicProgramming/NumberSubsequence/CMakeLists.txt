cmake_minimum_required(VERSION 3.15)
project(LongestIncreasingSubsequence)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        pthread)

add_executable(${PROJECT_NAME}
        300-longest-increasing-subsequence.cpp 646-maximum-length-of-pair-chain.cpp 376-wiggle-subsequence.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})