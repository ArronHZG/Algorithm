cmake_minimum_required(VERSION 3.15)
project(ArrayInterval)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        pthread)

add_executable(${PROJECT_NAME}
        show.cpp show.h
        303-range-sum-query-immutable.cpp 413-arithmetic-slices.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})