//
// Created by 侯正罡 on 2020/5/14.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

TEST(canJump, 1) {
    cout << endl;
    vector<int> input = {2, 3, 1, 1, 4};
    auto answer = true;
    auto output = Solution().canJump(input);
    EXPECT_EQ(answer, output);
}