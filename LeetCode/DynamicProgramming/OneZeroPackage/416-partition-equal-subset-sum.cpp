//
// Created by 侯正罡 on 2020/4/25.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    /*
     * 背包的变种
     *
     * dp<int>[i][j] 前i个数, sum_i<=j 的最大值
     * dp<int>[j]    前i个数求和 <=j 的最大值
     *
     * dp<bool>[j]    前i个数部分求和为j   比 2 慢
     */
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int half_sum = sum / 2;
        vector<int> dp(half_sum + 1);
        for (auto num:nums) {
            for (int j = half_sum; j >= num; j--) {
                dp[j] = max(dp[j], dp[j - num] + num);
            }
        }
        return dp.back() == half_sum;
    }

    bool canPartition2(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int half_sum = sum / 2;
        vector<bool> dp(half_sum + 1);
        dp[0] = true;
        for (auto num:nums) {
            for (int j = half_sum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
            print<bool>(dp);
        }
        return dp.back();
    }
};

TEST(canPartition, 1) {
    cout << endl;
    vector<int> input = {1, 5, 11, 5};
    int answer = true;
    auto output = Solution().canPartition(input);
    EXPECT_EQ(answer, output);
}