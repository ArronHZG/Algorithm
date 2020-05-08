//
// Created by 侯正罡 on 2020/4/3.
//
/**
 * You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
#include <show.h>


using namespace std;

class Solution {
public:
    /**
     * dp[i]=dp[i−1]+dp[i−2]
     * @param n
     * @return
     */
    int getSum(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= 1000000007;
        }
        int sum = 0;
        vector<int> dp2(n + 1);
        dp2[1] = 1;
        dp2[2] = 3;
        for (int i = 3; i <= n; i++) {
            dp2[i] = dp2[i - 1] + 0.5 * (i - 1) * i;
        }

        print<int>(dp);
        print<int>(dp2);
        for (int i = 1; i <= n; i++) {
            sum += dp2[n + 1 - i] * dp[i] % 1000000007;
            sum %= 1000000007;
        }
        return sum;
    }
};

TEST(getSum, 1) { /* NOLINT */
    cout << endl;
    int input = 4;
    int answer = 461485937;
    auto output = Solution().getSum(input);
    EXPECT_EQ(answer, output);
}
