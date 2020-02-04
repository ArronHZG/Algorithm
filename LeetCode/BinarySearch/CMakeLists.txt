cmake_minimum_required(VERSION 3.15)
project(BinarySearch)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        pthread)

add_executable(${PROJECT_NAME} 69-sqrtx.cpp 744-find-smallest-letter-greater-than-target.cpp 540-single-element-in-a-sorted-array.cpp 278-first-bad-version.cpp 153-find-minimum-in-rotated-sorted-array.cpp 34-find-first-and-last-position-of-element-in-sorted-array.cpp ../DivideAndConquer/241-different-ways-to-add-parentheses.cpp ../DivideAndConquer/95-unique-binary-search-trees-ii.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})