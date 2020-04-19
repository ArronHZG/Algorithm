cmake_minimum_required(VERSION 3.15)
project(utils)
set(CMAKE_CXX_STANDARD 14)

set(src
        show.cpp show.h
        ListNode.cpp ListNode.h
        TreeNode.cpp TreeNode.h)

add_library(${PROJECT_NAME} ${src})
