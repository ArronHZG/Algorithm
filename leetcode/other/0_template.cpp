//
// Created by arron on 19-4-26.
//
#include <iostream>
#include <gtest/gtest.h>

void quickSort(std::array<int, 7> &array, int low, int high);

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
    for (int i : array) std::cout << i << " ";
    std::cout << std::endl;

    EXPECT_EQ(answer, array);
}

/**
 * 如果大于轴心点放在前面，如果小于轴心点放在后面
 * 定义两个变量记录i,j
 * i 从前向后搜索第一个大于轴心点的位置
 * j 从后向前搜索第一个小于轴心点的位置
     交换i,j
 * 重复上述三步直到 i>=j 准确来讲应该是i>j
 * @param array
 * @param low
 * @param high
 */
void quickSort(std::array<int, 7> &array, int low, int high) {
    if (low < high) {
        //定义轴心点
        int axisPoint = array[low];

        int i = low;
        int j = high + 1;//加一后面会剪掉
        while (i < j) {
            //如果没有后面限制，++i/--j 会导致数组溢出
            while (array[++i] < axisPoint && i <= high);
            while (array[--j] > axisPoint && j >= low);
            if (i >= j) {
                i--;
                j++;
                break;
            }
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;

        }
        int temp = array[i];
        array[i] = array[low];
        array[low] = temp;
        quickSort(array, low, i);
        quickSort(array, j, high);
    }
}