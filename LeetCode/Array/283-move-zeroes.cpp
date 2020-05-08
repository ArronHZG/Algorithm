//
// Created by 侯正罡 on 2020/4/24.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    vector<int> moveZeroes(vector<int> &nums) {
        int index = 0;
        for (auto num:nums)
            if (num != 0)
                nums[index++] = num;
        for (int i = index; i < nums.size(); i++)
            nums[i] = 0;
        return nums;
    }
};

TEST(moveZeroes, 1) {
    cout << endl;
    auto start_time = clock();
    vector<int> input = {0, 1, 0, 3, 12};
    vector<int> answer = {1, 3, 12, 0, 0};
    auto output = Solution().moveZeroes(input);
    EXPECT_EQ(answer, output);
    auto end_time = clock();
    cout << "time cost:" << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
}