//
// Created by arron on 2019/4/22.
// 分治法寻找最大值和最小值
//
#include <iostream>
#include <gtest/gtest.h>

void partitionGet(int start, int end, const int *meter, int *max, int *min);


TEST(partitionGet, partitionGet) {
    int array[10] = {1, -2, 422, 23, 4, 1, 4, 5, 234, 0};
    int max = 0;
    int min = 0;
    partitionGet(0, 9, array, &max, &min);
    std::cout<<std::endl<<"max:"<<max<<std::endl;
    std::cout<<"min:"<<min<<std::endl;
    EXPECT_EQ(max,422);
    EXPECT_EQ(min,-2);
}

void partitionGet(int start, int end, const int *meter, int *max, int *min) {
    int i;
    int localMax = 0;
    int localMin = 0;
    if (end - start <= 1) {
        if (meter[start] > meter[end]) {
            localMax = meter[start];
            localMin = meter[end];
        } else {
            localMin = meter[start];
            localMax = meter[end];
        }
        if (localMax > *max) {
            *max = localMax;
        }
        if (localMin < *min) {
            *min = localMin;
        }
        return;
    }
    i = start + (end - start) / 2;
    partitionGet(start, i, meter, max, min);
    partitionGet(i + 1, end, meter, max, min);
}