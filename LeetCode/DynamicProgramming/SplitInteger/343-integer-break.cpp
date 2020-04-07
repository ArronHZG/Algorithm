//
// Created by 侯正罡 on 2020/4/7.
//

/**
 *
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <cstring>
#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    /**
     * dp[n] = max(dp[1]*dp[n-1],...,dp[int(n/2)*dp[n-int(n/2)]]) n>=2
     * @param n
     * @return
     */
    long integerBreak(long n) {
        vector<long> dp(n + 1,1);
        if(n==2) return 1;
        if(n==3) return 2;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            long tmp = 0;
            for (int k = 1; k <= int(i / 2); k++) {
                tmp = max(tmp, dp[k] * dp[i - k]);
            }
            dp[i] = tmp;
        }
        print<long>(dp);
        return dp[n];
    }
};


//class Solution {
//public:
//    /**
//     * dp[n] = max(dp[1]*dp[n-1],...,dp[int(n/2)*dp[n-int(n/2)]]) n>=2
//     * @param n
//     * @return
//     */
//    int integerBreak(int n) {
//        vector<int> dp(n + 1,1);
//        for (int i = 3; i <= n; i++) {
//            int tmp = 0;
//            for (int k = 1; k <= int(i / 2); k++) {
//                auto a = max(k, dp[k]);
//                auto b = max(i - k, dp[i - k]);
//                tmp = max(tmp, a * b);
//            }
//            dp[i] = tmp;
//        }
//        return dp[n];
//    }
//};

TEST(integerBreak, 1) { /* NOLINT */
    cout << endl;
    long input = 10000;
    long answer = 27;
    auto output = Solution().integerBreak(input);
    EXPECT_EQ(answer, output);
}
