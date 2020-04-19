//
// Created by 侯正罡 on 2020/2/7.
//
/**
 * 给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/max-area-of-island
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
    /**
     * 深度遍历每个为1的node,置为-1,并且面积+1
     * @param grid
     * @return
     */
    int high = 0, wide = 0;
    int curArea;

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        high = grid.size();
        if (0 == high) return 0;
        wide = grid[0].size();
        if (0 == wide) return 0;

        int maxArea = 0;
        for (int i = 0; i < high; i++) {
            for (int j = 0; j < wide; j++) {
                if (grid[i][j] == 1) {
                    curArea = 0;
                    getArea(grid, i, j);
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        return maxArea;
    }

    void getArea(vector<vector<int>> &grid, int h, int w) {
        if (h != -1 && h != high && w != -1 && w != wide && grid[h][w] == 1) {
            grid[h][w] = -1;
            curArea++;
//            cout<<h<< " "<<w<< " area "<<curArea<<endl;
            getArea(grid, h - 1, w);
            getArea(grid, h, w - 1);
            getArea(grid, h, w + 1);
            getArea(grid, h + 1, w);
        }
    }
};

TEST(maxAreaOfIsland, 1) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    int answer = 6;
    auto output = Solution().maxAreaOfIsland(input);
    EXPECT_EQ(answer, output);
}

TEST(maxAreaOfIsland, 2) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input{{1, 1, 0, 1, 1},
                              {1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1},
                              {1, 1, 0, 1, 1}};
    int answer = 3;
    auto output = Solution().maxAreaOfIsland(input);
    EXPECT_EQ(answer, output);
}

