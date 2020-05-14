//
// Created by 侯正罡 on 2020/5/14.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix.back().empty()) return 0;
        int rows = matrix.size(), columns = matrix.back().size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};

TEST(countSquares, 1) {
    cout << endl;
    vector<vector<int>> input = {{1, 0, 1, 0, 0},
                                 {1, 0, 1, 1, 1},
                                 {1, 1, 1, 1, 1},
                                 {1, 0, 0, 1, 0}};
    auto answer = 15;
    auto output = Solution().countSquares(input);
    EXPECT_EQ(answer, output);
}