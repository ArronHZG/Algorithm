//
// Created by 侯正罡 on 2020/4/26.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    void DFS(int v, int sum, int pos_n, int neg_n, int &res) {
        if (pos_n == 0 && neg_n == 0) {
            res += 1;
            return;
        }
        if (sum >= 0 && pos_n > 0) {
            DFS(1, sum + 1, pos_n - 1, neg_n, res);
        }
        if (sum > 0 && neg_n > 0) {
            DFS(-1, sum - 1, pos_n, neg_n - 1, res);
        }
    }

    int howManySort(int n) {
        int res = 0;
        DFS(1, 1, n - 1, n, res);
        return res;
    }

};

TEST(adsfdgfhg, 1) {
    cout << endl;
    int n = 3;
    int answer = 2;
    auto output = Solution().howManySort(n);
    EXPECT_EQ(answer, output);
}