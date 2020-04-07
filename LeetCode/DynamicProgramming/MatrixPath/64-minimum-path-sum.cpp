//
// Created by 侯正罡 on 2020/4/4.
//

/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
#include "../FibonacciSequence/show.h"


using namespace std;

class Solution {
public:
    /**
     * dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j]
     *
     * dp can be replace by grid
     */
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        //gird.size() = m x n
        auto m = grid.size();
        auto n = grid[0].size();
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        print(grid);
        return grid[m - 1][n - 1];
    }
};

TEST(minPathSum, 1) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input = {{1, 3, 1},
                                 {1, 5, 1},
                                 {4, 2, 1}};
    int answer = 7;
    auto output = Solution().minPathSum(input);
    EXPECT_EQ(answer, output);
}