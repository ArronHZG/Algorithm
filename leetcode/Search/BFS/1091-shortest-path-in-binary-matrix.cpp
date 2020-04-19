//
// Created by 侯正罡 on 2020/2/5.
//

/**
 * 在一个 N × N 的方形网格中，每个单元格有两种状态：空（0）或者阻塞（1）。

一条从左上角到右下角、长度为 k 的畅通路径，由满足下述条件的单元格 C_1, C_2, ..., C_k 组成：

相邻单元格 C_i 和 C_{i+1} 在八个方向之一上连通（此时，C_i 和 C_{i+1} 不同且共享边或角）
C_1 位于 (0, 0)（即，值为 grid[0][0]）
C_k 位于 (N-1, N-1)（即，值为 grid[N-1][N-1]）
如果 C_i 位于 (r, c)，则 grid[r][c] 为空（即，grid[r][c] == 0）
返回这条从左上角到右下角的最短畅通路径的长度。如果不存在这样的路径，返回 -1 。

 

示例 1：

输入：[[0,1],
     [1,0]]

输出：2

示例 2：

输入：[[0,0,0],
      [1,1,0],
      [1,1,0]]

输出：4

 

提示：

1 <= grid.length == grid[0].length <= 100
grid[i][j] 为 0 或 1

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/shortest-path-in-binary-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <queue>
#include <gtest/gtest.h>

using namespace std;


//class Solution {
//public:
//    //存行数和列数索引
//    using Point = pair<int, int>;
//
//    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
//        auto len = grid.size();
//        if (grid[0][0] == 1 || grid[len - 1][len - 1] == 1) return -1;
//        //这里grid和visit合并，0表示没有访问过,>0表示访问过的距离或者有障碍
//        grid[0][0] = 1;
//        queue<Point> path;
//        path.emplace(0, 0);
//        while (!path.empty()) {
//            auto u = path.front();
//            path.pop();
//            int nx = u.first, ny = u.second;
//            for (int i = -1; i <= 1; i++)
//                for (int j = -1; j <= 1; j++) {
//                    int x = nx + i, y = ny + j;
//                    if (x < 0 || x > len - 1 || y < 0 || y > len - 1 || grid[x][y])
//                        continue;
//                    grid[x][y] = grid[nx][ny] + 1;
//                    path.emplace(x, y);
//                }
//        }
//        return grid[len - 1][len - 1] == 0 ? -1 : grid[len - 1][len - 1];
//    }
//};

class Solution {
public:
    using Point = pair<int, int>;

    int shortestPathBinaryMatrix(vector<vector<int>> &input) {
        int N = input.size();
        if (1 == input[0][0] || 1 == input[N - 1][N - 1]) {
            return -1;
        }

        //初始点
        input[0][0] = 1;
        //该点生产队列
        queue<Point> path;
        path.emplace(0, 0);
        while (!path.empty()) {
            auto point = path.front();
            path.pop();
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    auto x = point.first + i;
                    auto y = point.second + j;
                    //行越界
                    if (x < 0 || x == N) continue;
                    //列越界
                    if (y < 0 || y == N) continue;
                    //访问过, 或者处于阻塞
                    if (input[x][y] > 0) continue;
                    input[x][y] = input[point.first][point.second] + 1;
                    path.emplace(x, y);
                }
            }
        }
        return input[N - 1][N - 1] == 0 ? -1 : input[N - 1][N - 1];
    }
};

TEST(shortestPathBinaryMatrix, 1) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input{{0, 1},
                              {1, 0}};
    int answer = 2;
    auto output = Solution().shortestPathBinaryMatrix(input);
    EXPECT_EQ(answer, output);
}

TEST(shortestPathBinaryMatrix, 2) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input{{0, 0, 0},
                              {1, 1, 0},
                              {1, 1, 0}};
    int answer = 4;
    auto output = Solution().shortestPathBinaryMatrix(input);
    EXPECT_EQ(answer, output);
}