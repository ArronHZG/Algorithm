//
// Created by 侯正罡 on 2020/4/25.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int findTargetSumWays(int n) {
        return 0;
    }
};

TEST(findTargetSumWays, 1) {
    cout << endl;
    vector<int> input = {};
    int n = 0;
    int answer = 0;
    auto output = Solution().findTargetSumWays(n);
    EXPECT_EQ(answer, output);
}