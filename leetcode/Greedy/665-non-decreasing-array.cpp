//
// Created by 侯正罡 on 2020/2/2.
//

/**
 *
给定一个长度为 n 的整数数组，你的任务是判断在最多改变 1 个元素的情况下，该数组能否变成一个非递减数列。
我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，满足 array[i] <= array[i + 1]。
示例 1:

输入: [4,2,3]
输出: True
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
示例 2:

输入: [4,2,1]
输出: False
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
说明:  n 的范围为 [1, 10,000]。



来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/non-decreasing-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */
#include <iostream>
#include <list>
#include <vector>
#include <gtest/gtest.h>


using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int n = 0;
        int sz = nums.size();
        for (int i = 0; i < sz - 1; i++) {
            int a = nums[i];
            int b = nums[i + 1];
            if (a > b) {
                n++;
                if (n > 1) return false;
                if (i - 1 > -1 && nums[i - 1] > b && i + 2 < sz && a > nums[i + 2])
                    return false;
            }
        }
        return true;
    }
};

TEST(checkPossibility, 1) { /* NOLINT */
    cout << endl;
    vector<int> input{4, 2, 3};
    auto answer = true;
    auto output = Solution().checkPossibility(input);
    EXPECT_EQ(answer, output);
}


TEST(checkPossibility, 2) { /* NOLINT */
    cout << endl;
    vector<int> input{4, 3, 2};
    auto answer = false;
    auto output = Solution().checkPossibility(input);
    EXPECT_EQ(answer, output);
}

TEST(checkPossibility, 3) { /* NOLINT */
    cout << endl;
    vector<int> input{3, 4, 2, 3};
    auto answer = false;
    auto output = Solution().checkPossibility(input);
    EXPECT_EQ(answer, output);
}

TEST(checkPossibility, 4) { /* NOLINT */
    cout << endl;
    vector<int> input{2,3,3,2,4};
    auto answer = true;
    auto output = Solution().checkPossibility(input);
    EXPECT_EQ(answer, output);
}