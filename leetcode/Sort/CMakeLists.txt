cmake_minimum_required(VERSION 3.15)
project(Sort)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        pthread)

add_executable(${PROJECT_NAME}
        215-kth-largest-element-in-an-array.cpp
        347-top-k-frequent-elements.cpp
        451-sort-characters-by-frequency.cpp
        75-sort-colors.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})