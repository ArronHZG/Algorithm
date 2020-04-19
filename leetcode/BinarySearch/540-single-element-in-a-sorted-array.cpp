//
// Created by 侯正罡 on 2020/2/3.
//

/**
给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。

示例 1:

输入: [1,1,2,3,3,4,4,8,8]
输出: 2
示例 2:

输入: [3,3,7,7,10,11,11]
输出: 10
注意: 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/single-element-in-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        return single(nums, 0, nums.size() - 1);

    }

    int single(vector<int> &nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        if (nums[mid - 1] == nums[mid]) {
            if ((mid - 2 - left + 1) % 2 == 1) {
                return single(nums, left, mid - 2);
            } else {
                return single(nums, mid + 1, right);
            }
        } else if (nums[mid] == nums[mid + 1]) {
            if ((mid - 1 - left + 1) % 2 == 1) {
                return single(nums, left, mid - 1);
            } else {
                return single(nums, mid + 2, right);
            }
        } else
            return single(nums, mid, mid);
    }
};

TEST(singleNonDuplicate, 1) { /* NOLINT */
    cout << endl;
    vector<int> input{1, 1, 2, 3, 3, 4, 4, 8, 8};
    auto answer = 2;
    auto output = Solution().singleNonDuplicate(input);
    EXPECT_EQ(answer, output);
}

TEST(singleNonDuplicate, 2) { /* NOLINT */
    cout << endl;
    vector<int> input{3, 3, 7, 7, 10, 11, 11};
    auto answer = 10;
    auto output = Solution().singleNonDuplicate(input);
    EXPECT_EQ(answer, output);
}

TEST(singleNonDuplicate, 3) { /* NOLINT */
    cout << endl;
    vector<int> input{1};
    auto answer = 1;
    auto output = Solution().singleNonDuplicate(input);
    EXPECT_EQ(answer, output);
}

TEST(singleNonDuplicate, 4) { /* NOLINT */
    cout << endl;
    vector<int> input{1, 1, 2};
    auto answer = 2;
    auto output = Solution().singleNonDuplicate(input);
    EXPECT_EQ(answer, output);
}