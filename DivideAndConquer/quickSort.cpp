//
// Created by arron on 19-4-23.
//
#include <iostream>
#include <gtest/gtest.h>

void quickSort(std::array<int, 7> &array, int iow, int high);

template<typename T, size_t size>
::testing::AssertionResult ArraysMatch(const T (&expected)[size],
                                       const T (&actual)[size]) {
    for (size_t i(0); i < size; ++i) {
        if (expected[i] != actual[i]) {
            return ::testing::AssertionFailure() << "array[" << i
                                                 << "] (" << actual[i] << ") != expected[" << i
                                                 << "] (" << expected[i] << ")";
        }
    }

    return ::testing::AssertionSuccess();
}

int num = 7;

TEST(quickSort, quickSort) {
    std::cout << std::endl;
    std::array<int, 7> array = {31, 15, 7, 33, 35, 7, 2};
    std::array<int, 7> answer = {2, 7, 7, 15, 31, 33, 35};
    quickSort(array, 0, 6);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    EXPECT_EQ(answer, array);
}


void quickSort(std::array<int, 7> &array, int low, int high) {
    if (low < high) {
        //定义轴心点
        int axisPoint = array[low];
        // 如果大于轴心点放在前面，如果小于轴心点放在后面
        //定义两个变量记录i,j
        //i 从前向后搜索第一个大于轴心点的位置 k
        //j 从后向前搜索第一个小于轴心点的位置 y
        //交换i,j
        //重复上述三步直到i==j
        int i = low;
        int j = high + 1;
        while (i < j) {
            while (array[++i] < axisPoint);
            while (array[--j] > axisPoint);
            if(i>=j){
                i--;
                j++;
                break;
            }
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            for (int t = 0; t < num; t++) std::cout << array[t] << " ";
            std::cout << std::endl;
        }
        int temp = array[i];
        array[i] = array[low];
        array[low] = temp;
        quickSort(array, low, i);
        quickSort(array, j, high);
    }
}