cmake_minimum_required(VERSION 3.15)
project(DoublePointer)
set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)
include_directories(/usr/local/include)

find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        pthread)

add_executable(${PROJECT_NAME}
        167-two-sum-ii-input-array-is-sorted.cpp
        633-sum-of-square-numbers.cpp
        345-reverse-vowels-of-a-string.cpp
        680-valid-palindrome-ii.cpp
        88-merge-sorted-array.cpp 141-linked-list-cycle.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})