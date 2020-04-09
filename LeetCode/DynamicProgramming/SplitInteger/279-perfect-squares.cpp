//
// Created by 侯正罡 on 2020/2/6.
//
/**
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <gtest/gtest.h>
#include "show.h"


using namespace std;

class Solution {
public:
    /**
     * dp[n] = min(dp[n-1]+1, dp[n-4]+1,...dp[n-k^2]+1) k^2<=n
     * @param n
     * @return
     */
    int numSquares(int n) {
        vector<int> dp(n + 1);
        int k = int(sqrt(n));
        vector<int> sqrt_vector;
        for (int i = 1; i <= k; i++) {
            sqrt_vector.push_back(i * i);
        }
        for (int i = 1; i <= n; i++) {
            int tmp = 100;
            for (auto sq:sqrt_vector) {
                if (sq <= i) {
                    tmp = min(tmp, dp[i - sq] + 1);
                } else {
                    break;
                }
            }
            dp[i] = tmp;
        }
        print<int>(dp);
        return dp[n];
    }
};


//class Solution {
//public:
//    using Node = pair<int, int>;
//    /**
//     * dp[n] = min(dp[n-1]+1, dp[n-4]+1,...dp[n-k^2]+1) k^2<=n
//     * @param n
//     * @return
//     */
//    int numSquares(int n) {
//        vector<int> dp(n + 1);
//        for (int i = 1; i <= n; i++) {
//            int K = int(sqrt(i));
//            int tmp = 100;
//            for (int k = 1; k <= K; k++) {
//                tmp = min(tmp, dp[i-k*k] + 1);
//            }
//            dp[i] = tmp;
//        }
//        print<int>(dp);
//        return dp[n];
//    }
//};

TEST(numSquares, 1) { /* NOLINT */
    cout << endl;
    int input = 18;
    int answer = 2;
    auto output = Solution().numSquares(input);
    EXPECT_EQ(answer, output);
}
