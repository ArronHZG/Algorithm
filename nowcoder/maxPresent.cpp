//
// Created by 侯正罡 on 2020/4/22.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:

    int maxPresent(vector<int> &presentVec) {
        int sum = accumulate(presentVec.begin(), presentVec.end(), 0);
        int half_sum = sum / 2;
        vector<int> dp(half_sum + 1);
        for (int pre : presentVec)
            for (int j = half_sum; j >= pre; j--) {
                dp[j] = max(dp[j], dp[j - pre] + pre);
                print<int>(dp);
            }
        return sum - 2 * dp[sum / 2];
    }
};

TEST(maxPresent, 1) {
    cout << endl;
    vector<int> input = {1, 2, 3, 4};
    int n = 0;
    int answer = 1;
    auto output = Solution().maxPresent(input);
    EXPECT_EQ(answer, output);
}