//
// Created by 侯正罡 on 2020/4/12.
//

/**
 * Given two strings text1 and text2, return the length of their longest common subsequence.
A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.
If there is no common subsequence, return 0.
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
#include<algorithm>
#include "show.h"

using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[l1][l2];
    }
};

class Solution2 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();
        vector<int> dp(l2 + 1);
        int last = 0;
        for (int i = 1; i <= l1; ++i, last = 0) {
            for (int j = 1; j <= l2; ++j) {
                auto temp = dp[j];
                if (text1[i - 1] == text2[j - 1]) dp[j] = last + 1;
                else dp[j] = max(dp[j], dp[j - 1]);
                last = temp;
            }
        }
        return dp[l2];
    }
};

TEST(longestCommonSubsequence, 1) { /* NOLINT */
    cout << endl;
    string input1 = "abcde";
    string input2 = "acfge";
    int answer = 3;
    auto output = Solution().longestCommonSubsequence(input1, input2);
    EXPECT_EQ(answer, output);
}

TEST(longestCommonSubsequence, 2) { /* NOLINT */
    cout << endl;
    string input1 = "bsbininm";
    string input2 = "jmjkbkjkv";
    int answer = 1;
    auto output = Solution().longestCommonSubsequence(input1, input2);
    EXPECT_EQ(answer, output);
}