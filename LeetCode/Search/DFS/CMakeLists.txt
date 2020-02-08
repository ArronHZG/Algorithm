cmake_minimum_required(VERSION 3.15)
project(DFS)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        pthread)

add_executable(${PROJECT_NAME} 695-max-area-of-island.cpp 200-number-of-islands.cpp 547-friend-circles.cpp 130-surrounded-regions.cpp 417-pacific-atlantic-water-flow.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})