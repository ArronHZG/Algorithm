//
// Created by 侯正罡 on 2020/4/26.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int arrange(long long m, long long n) {
        n = max(m - n, n);
        int a = 1;
        for (int i = m; i > n; i--) {
            a *= i;
        }
        for (int i = m - n; i > 0; i--) {
            a /= i;
        }
        return a % 3;
    }
};

TEST(arrange, 1) {
    cout << endl;
    vector<int> input = {};
    int n = 3;
    int m = 5;
    int answer = 0;
    auto output = Solution().arrange(m, n);
    EXPECT_EQ(answer, output);
}