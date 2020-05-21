
cmake_minimum_required(VERSION 3.15)
project(ListNode)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} 206-reverse-linked-list.cpp 21-merge-two-sorted-lists.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
