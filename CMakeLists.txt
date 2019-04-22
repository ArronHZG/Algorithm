cmake_minimum_required(VERSION 3.14)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

## 编译google test，会在当前目录生成libtest.a动态库
#add_subdirectory(./googletest)
# 将用于google test的头文件gtest.h添加到include路径中
include_directories(./googletest/googlemock/include)
include_directories(./googletest/googletest/include)
# 将libtest.a添加到链接路径中（同时需要添加googletest运行需要的pthread）
link_directories(./googletest/build/lib)
set(LIBRARIES
        gtest
        gtest_main)

add_executable(algorithm main.cpp)
add_executable(test DivideAndConquer/partitionGet.cpp DivideAndConquer/mergeSort.cpp)
target_link_libraries(test ${LIBRARIES})