//
// Created by 侯正罡 on 2020/4/12.
//

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
#include<algorithm>
#include "show.h"

using namespace std;

class SolutionDP {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        // 排序
        sort(pairs.begin(), pairs.end(), [&](const vector<int> &A, const vector<int> &B) {
            if (A[0] != B[0]) return A[0] < B[0];
            return A[1] < B[1];
        });

        // DP
        const int n = pairs.size();
        vector<int> dp(n, 1);
        int res = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) { // 能拼接
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};


class Solution {
public:
    /**
     * 按照结尾排序, 去除不能在链中的的部分
     * @param pairs
     * @return
     */
    int findLongestChain(vector<vector<int>> &pairs) {
        // 排序：按照结束时间
        sort(pairs.begin(), pairs.end(), [&](const vector<int> &A, const vector<int> &B) {
            return A[1] < B[1];
        });

        int res = 1;
        int maxEnd = pairs[0][1];
        for (int i = 1; i < pairs.size(); ++i) {
            auto &curr = pairs[i];
            if (curr[0] > maxEnd) { // 不相交
                ++res;
                maxEnd = curr[1];
            }
        }
        return res;
    }
};

TEST(findLongestChain, 1) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input = {{1, 2},
                                 {3, 6},
                                 {4, 5}};
    int answer = 2;
    auto output = Solution().findLongestChain(input);
    EXPECT_EQ(answer, output);
}