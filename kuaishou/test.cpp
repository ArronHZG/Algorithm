//
// Created by 侯正罡 on 2020/4/26.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int test(int n) {
        return 0;
    }
};

TEST(test, 1) {
    cout << endl;
    vector<int> input = {};
    int n = 0;
    int answer = 0;
    auto output = Solution().test(n);
    EXPECT_EQ(answer, output);
}