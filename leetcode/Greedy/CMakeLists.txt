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

add_executable(${PROJECT_NAME}
        455-assign-cookies.cpp
        435-non-overlapping-intervals.cpp
        452-minimum-number-of-arrows-to-burst-balloons.cpp
        406-queue-reconstruction-by-height.cpp
        121-best-time-to-buy-and-sell-stock.cpp
        122-best-time-to-buy-and-sell-stock-ii.cpp
        605-can-place-flowers.cpp
        392-is-subsequence.cpp
        665-non-decreasing-array.cpp
        53-maximum-subarray.cpp
        763-partition-labels.cpp 55-jump-game.cpp 45-jump-game-ii.cpp)

include_directories(${CMAKE_SOURCE_DIR}/Utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})