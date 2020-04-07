//
// Created by 侯正罡 on 2020/4/7.
//

/**
 * A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arithmetic-slices
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 **/


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
     * step1: find arithmetic
     *        N stands for the length of the arithmetic
     * step2:
     *              dp[n] = dp[n-1] + n - 2 (n>3) ;
     *              dp[3] = 1 ;
     *              dp(n) = 1/2 * n**2 - 3/2 * n + 1
     *
     * @param A
     * @return
     */
    int numberOfArithmeticSlices(vector<int> &A) {
        if (A.size() < 3) return 0;
        int sum = 0;
        int n = 0;
        for (int i = 1; i + 1 < A.size(); i++) {
            auto a = A[i] - A[i - 1];
            auto b = A[i + 1] - A[i];
            if (a == b) {
                if (n == 0) n = 3;
                else n += 1;
            } else if (a != b) {
                if (n >= 3) sum += dp(n);
                n = 0;
            }
        }
        if (n >= 3) sum += dp(n);
        return sum;
    }

    int dp(int n) {
        auto a = 0.5 * (n * n - 3 * n + 2);
        return int(a);
    }
};

TEST(numberOfArithmeticSlices, 1) { /* NOLINT */
    cout << endl;
    vector<int> input = {1, 2, 3, 4};
    int answer = 3;
    auto output = Solution().numberOfArithmeticSlices(input);
    EXPECT_EQ(answer, output);
}

TEST(numberOfArithmeticSlices, 2) { /* NOLINT */
    cout << endl;
    vector<int> input = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int answer = 120;
    auto output = Solution().numberOfArithmeticSlices(input);
    EXPECT_EQ(answer, output);
}