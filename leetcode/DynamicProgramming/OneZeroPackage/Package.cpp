//
// Created by 侯正罡 on 2020/4/25.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:

    int Package(int maxWeight, vector<vector<int>> goods) {
        int n = goods.size();
        vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1));
        for (int i = 1; i <= n; i++) {
            int w = goods[i - 1][0];
            int v = goods[i - 1][1];
            for (int j = 1; j <= maxWeight; j++) {
                if (w > j) {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
                }
            }
        }
        print<int>(dp);
        return dp.back().back();
    }

    int Package2(int maxWeight, vector<vector<int>> goods) {
        int n = goods.size();
        vector<int> dp(maxWeight + 1);
        for (auto good:goods) {
            int w = good[0];
            int v = good[1];
            for (int j = maxWeight; j >= w; j--) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
            print<int>(dp);
        }

        return dp.back();
    }
};

TEST(Package, 1) {
    cout << endl;
    vector<vector<int>> input = {{4, 6},
                                 {2, 3},
                                 {4, 3},
                                 {1, 2},
                                 {3, 4}};
    int weight = 1;
    int answer = 18;
    auto output = Solution().Package(weight, input);
    output = Solution().Package2(weight, input);
    EXPECT_EQ(answer, output);
}