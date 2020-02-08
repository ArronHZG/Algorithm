//
// Created by 侯正罡 on 2020/2/8.
//

/**
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int high = 0, wide = 0;

    void solve(vector<vector<char>> &board) {
        high = board.size();
        if (high == 0) return;
        wide = board[0].size();
        vector<int> highCoordinate{0, high - 1};
        vector<int> wideCoordinate{0, wide - 1};

        for (auto i:highCoordinate) {
            for (int j = 0; j < wide; j++) {
                getArea(board, i, j);
            }
        }
        for (auto j:wideCoordinate) {
            for (int i = 0; i < high; i++) {
                getArea(board, i, j);
            }
        }
        for (int i = 0; i < high; i++) {
            for (int j = 0; j < wide; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void getArea(vector<vector<char>> &grid, int h, int w) {
        if (h != -1 && h != high && w != -1 && w != wide && grid[h][w] == 'O') {
            grid[h][w] = '#';
            cout << h << " " << w << " " << grid[h][w] << endl;
            getArea(grid, h - 1, w);
            getArea(grid, h, w - 1);
            getArea(grid, h, w + 1);
            getArea(grid, h + 1, w);
        }
    }
};


TEST(solve, 1) { /* NOLINT */
    cout << endl;
    vector<vector<char>> input{{'X', 'X', 'X', 'X'},
                               {'X', 'O', 'O', 'X'},
                               {'X', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'X'}};
    vector<vector<char>> answer{{'X', 'X', 'X', 'X'},
                                {'X', 'X', 'X', 'X'},
                                {'X', 'X', 'X', 'X'},
                                {'X', 'O', 'X', 'X'}};
    Solution().solve(input);
    EXPECT_EQ(answer, input);
}

TEST(solve, 2) { /* NOLINT */
    cout << endl;
    vector<vector<char>> input{{'X', 'O', 'X', 'O', 'X', 'O'},
                               {'O', 'X', 'O', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'O', 'X', 'O'},
                               {'O', 'X', 'O', 'X', 'O', 'X'}};

    vector<vector<char>> answer{{'X', 'O', 'X', 'O', 'X', 'O'},
                                {'O', 'X', 'X', 'X', 'X', 'X'},
                                {'X', 'X', 'X', 'X', 'X', 'O'},
                                {'O', 'X', 'O', 'X', 'O', 'X'}};
    Solution().solve(input);
    EXPECT_EQ(answer, input);
}



