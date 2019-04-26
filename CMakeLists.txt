cmake_minimum_required(VERSION 3.14)
project(algorithm)
set(CMAKE_CXX_STANDARD 14)
## 编译google test，会在当前目录生成libtest.a动态库
#add_subdirectory(./googletest)
# 将用于google test的头文件gtest.h添加到include路径中
#include_directories(./googletest/googlemock/include)
#include_directories(./googletest/googletest/include)
# 将libtest.a添加到链接路径中（同时需要添加googletest运行需要的pthread）
link_directories(/usr/local/lib)
find_package(Threads REQUIRED)
set(LIBRARIES
        gtest
        gtest_main
        Threads::Threads)# 添加pthread 库
add_executable(DivideAndConquer
        DivideAndConquer/partitionGet.cpp
        DivideAndConquer/mergeSort.cpp
        DivideAndConquer/quickSort.cpp
        DivideAndConquer/binSearch.cpp
        DivideAndConquer/farmer.cpp)
target_link_libraries(DivideAndConquer ${LIBRARIES})

add_executable(LeetCode
        LeetCode/0_template.cpp
        LeetCode/1_two_num.cpp
        LeetCode/15_three_sum.cpp)
target_link_libraries(LeetCode ${LIBRARIES})


