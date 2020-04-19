cmake_minimum_required(VERSION 3.15)
project(Backtracking)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        pthread)

add_executable(${PROJECT_NAME}
#        17-letter-combinations-of-a-phone-number.cpp
#        93-restore-ip-addresses.cpp
#        79-word-search.cpp
#        257-binary-tree-paths.cpp
#        77-combinations.cpp
#        39-combination-sum.cpp
#        40-combination-sum-ii.cpp
#        216-combination-sum-iii.cpp
        78-subsets.cpp 131-palindrome-partitioning.cpp sudoku-solver.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})