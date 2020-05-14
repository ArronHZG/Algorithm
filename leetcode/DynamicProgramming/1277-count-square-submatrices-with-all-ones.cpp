//
// Created by 侯正罡 on 2020/5/14.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int countSquares(vector<int> &nums) {
        return 0;
    }
};

TEST(countSquares, 1) {
    cout << endl;
    vector<int> input = {};
    auto answer = 0;
    auto output = Solution().countSquares(input);
    EXPECT_EQ(answer, output);
}