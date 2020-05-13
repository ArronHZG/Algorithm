//
// Created by 侯正罡 on 2020/1/18.
//
/**
给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        if (numbers.size() < 2) return {-1, -1};
        int low = 0;
        int high = numbers.size() - 1; //需要在[low...high] 中寻找
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
                return {low + 1, high + 1};
            else if (sum < target)
                ++low;
            else
                --high;
        }
        return {-1, -1};
    }
};

TEST(twoSum, 1) { /* NOLINT */
    std::cout << std::endl;
    vector<int> input = {2, 7, 11, 15};
    int target = 9;
    vector<int> answer = {1, 2};
    vector<int> output = Solution().twoSum(input, target);
    EXPECT_EQ(answer, output);
}