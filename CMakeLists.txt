cmake_minimum_required(VERSION 3.14)
project(algorithm)
set(CMAKE_CXX_STANDARD 14)
set(LIBRARIES
        gtest
        gtest_main)
add_executable(algorithm main.cpp)
add_executable(test DivideAndConquer/partitionGet.cpp DivideAndConquer/mergeSort.cpp DivideAndConquer/quickSort.cpp)
target_link_libraries(test ${LIBRARIES})
find_package(Threads REQUIRED)
target_link_libraries(test Threads::Threads)

