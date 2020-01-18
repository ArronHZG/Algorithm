//
// Created by arron on 2019/4/23.
//
#include <iostream>
#include <gtest/gtest.h>

void mergeSort(int a[], int low, int high);

void merge(int a[], int low, int mid, int high);

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

TEST(mergeSort, mergeSort) {
    int array[7] = {31, 15, 7, 33, 35, 7, 2};
    int answer[7] = {2, 7, 7, 15, 31, 33, 35};
    mergeSort(array, 0, 6);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    EXPECT_TRUE(ArraysMatch(answer, array));

}

void mergeSort(int a[], int low, int high) {
    // 要排序的数组是 a[low..high]
    if (low < high) { // base case: low >= high (0 or 1 item)
        int mid = (low + high) / 2;
        mergeSort(a, low, mid); // 分成一半
        mergeSort(a, mid + 1, high); // 递归地将它们排序
        merge(a, low, mid, high); // 解决: 归并子程序
    }
}

void merge(int a[], int low, int mid, int high) {
    // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
    int N = high - low + 1;
    int b[N]; // 讨论: 为什么我们需要一个临时的数组 b?
    int left = low, right = mid + 1, bIdx = 0;
    while (left <= mid && right <= high) // 归并
        b[bIdx++] = a[left] < a[right] ? a[left++] : a[right++];
    while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
    while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
    for (int k = 0; k < N; k++) a[low + k] = b[k]; // copy back
}