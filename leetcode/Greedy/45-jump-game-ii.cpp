//
// Created by 侯正罡 on 2020/5/14.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i<=maxPos) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

TEST(jump, 1) {
    cout << endl;
    vector<int> input = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
    auto answer = 2;
    auto output = Solution().jump(input);
    EXPECT_EQ(answer, output);
}