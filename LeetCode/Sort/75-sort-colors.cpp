//
// Created by 侯正罡 on 2020/1/23.
//

/*
 *
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，
 原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    荷兰三色旗问题解
    */
    void sortColors(vector<int>& nums) {
        // 对于所有 idx < p0 : nums[idx < p0] = 0
        // curr 是当前考虑元素的下标
        // 对于所有 idx > p2 : nums[idx > p2] = 2
        uint p0 = 0;
        uint curr = 0;
        uint p2 = nums.size() - 1;

        while (curr <= p2) {
            if (nums[curr] == 0) {
                swap(nums[curr++], nums[p0++]);
            }
            else if (nums[curr] == 2) {
                swap(nums[curr], nums[p2--]);
            }
            else curr++;
        }
    }
};

TEST(sortColors, 1) { /* NOLINT */
    std::cout << std::endl;
    vector<int> input{2,0,2,1,1,0};
    vector<int> answer{0,0,1,1,2,2};
    Solution().sortColors(input);
    EXPECT_EQ(answer, input);
}
