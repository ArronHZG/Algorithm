//
// Created by 侯正罡 on 2020/2/7.
//

/**
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
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

    int numIslands(vector<vector<char>> &grid) {
        high = grid.size();
        if (0 == high) return 0;
        wide = grid[0].size();
        if (0 == wide) return 0;

        int num = 0;
        for (int i = 0; i < high; i++) {
            for (int j = 0; j < wide; j++) {
                if (grid[i][j] == '1') {
                    num++;
                    islands(grid, i, j);
                }
            }
        }
        return num;
    }


    void islands(vector<vector<char>> &grid, int h, int w) {
        if (h != -1 && h != high && w != -1 && w != wide && grid[h][w] == '1') {
            grid[h][w] = '-';
            islands(grid, h - 1, w);
            islands(grid, h, w - 1);
            islands(grid, h, w + 1);
            islands(grid, h + 1, w);
        }
    }
};

TEST(numIslands, 1) { /* NOLINT */
    cout << endl;
    vector<vector<char>> input{{'1', '0'},
                               {'1', '0'}};
    int answer = 1;
    auto output = Solution().numIslands(input);
    EXPECT_EQ(answer, output);
}