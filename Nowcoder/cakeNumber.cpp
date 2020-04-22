//
// Created by 侯正罡 on 2020/4/21.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:

    int cakeNumber(int n) {
        int cake = 1;
        for (int i = 1; i < n; i++) {
            cake = (cake + 1) * 3 / 2;
        }
        return cake;
    }
};

TEST(cakeNumber, 1) {
    cout << endl;
    vector<int> a = {};
    vector<int> b = {};
    int n = 4;
    int answer = 10;
    auto output = Solution().cakeNumber(n);
    EXPECT_EQ(answer, output);
}