cmake_minimum_required(VERSION 3.15)
project(Greedy)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        pthread)

add_executable(${PROJECT_NAME} 455-assign-cookies.cpp 435-non-overlapping-intervals.cpp 452-minimum-number-of-arrows-to-burst-balloons.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})