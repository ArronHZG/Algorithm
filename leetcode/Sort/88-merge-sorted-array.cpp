//
// Created by 侯正罡 on 2020/1/19.
//
/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 需要从尾开始遍历，否则在 nums1 上归并得到的值会覆盖还未进行归并比较的值。
 */

#include <iostream>
#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    /**
     *     从后向前比较
     * @param nums1
     * @param m
     * @param nums2
     * @param n
     * @return
     */
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

        // two get pointers for nums1 and nums2
        int p1 = m - 1; //指向第一个数组最后一个
        int p2 = n - 1; //指向第二个数组最后一个
        // set pointer for nums1
        int p = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] < nums2[p2]) {
                nums1[p--] = nums2[p2--];
            } else {
                nums1[p--] = nums1[p1--];
            }
        }
        while (p2 >= 0) {
            nums1[p--] = nums2[p2--];
        }
    }
};

TEST(merge, 1) { /* NOLINT */
    std::cout << std::endl;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{1, 2, 3};
    int m = 3;
    int n = 3;
    vector<int> answer{1, 1, 2, 2, 3, 3};
    Solution().merge(nums1, m, nums2, n);
    EXPECT_EQ(answer, nums1);
}

TEST(merge, 2) { /* NOLINT */
    std::cout << std::endl;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    int m = 3;
    int n = 3;
    vector<int> answer{1, 2, 2, 3, 5, 6};
    Solution().merge(nums1, m, nums2, n);
    EXPECT_EQ(answer, nums1);
}

TEST(merge, 3) { /* NOLINT */
    std::cout << std::endl;
    vector<int> nums1{0};
    vector<int> nums2{1};
    int m = 0;
    int n = 1;
    vector<int> answer{1};
    Solution().merge(nums1, m, nums2, n);
    EXPECT_EQ(answer, nums1);
}

TEST(merge, 4) { /* NOLINT */
    std::cout << std::endl;
    vector<int> nums1{1};
    vector<int> nums2{0};
    int m = 1;
    int n = 0;
    vector<int> answer{1};
    Solution().merge(nums1, m, nums2, n);
    EXPECT_EQ(answer, nums1);
}