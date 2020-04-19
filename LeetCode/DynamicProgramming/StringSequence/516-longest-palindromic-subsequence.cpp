//
// Created by 侯正罡 on 2020/4/19.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <gtest/gtest.h>
#include<algorithm>
#include "show.h"

using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};


TEST(longestPalindromeSubseq, 1) { /* NOLINT */
    cout << endl;
    string input1 = "abcda";
    int answer = 3;
    auto output = Solution().longestPalindromeSubseq(input1);
    EXPECT_EQ(answer, output);
}