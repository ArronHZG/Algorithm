//
// Created by 侯正罡 on 2020/2/8.
//

/**
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

 

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 

示例：

 

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pacific-atlantic-water-flow
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
     * 双路DFS, 找到所有属于左上的点和所有属于右上的点
     * 并集就是解
     * @param matrix
     * @return
     */
    int high = 0;
    int wide = 0;
    vector<vector<int>> sea;
    vector<vector<int>> output;

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        high = matrix.size();
        if (high == 0) return {};
        wide = matrix[0].size();
        if (wide == 0) return {};
        // 初始化visited
        for (int h = 0; h < high; h++) {
            sea.emplace_back();
            for (int w = 0; w < wide; w++)
                sea[h].push_back(0);
        }
        for (int i = 0; i < wide; i++)
            dfs(matrix, 0, i, -1, -1);

        for (int i = 0; i < high; i++)
            dfs(matrix, i, 0, -1, -1);

        for (int i = 0; i < wide; i++)
            dfs(matrix, high - 1, i, 1, -1);

        for (int i = 0; i < high; i++)
            dfs(matrix, i, wide - 1, 1, -1);

//        for (auto &h:sea) {
//            for (auto &w:h) {
//                cout << w << "\t";
//            }
//            cout << endl;
//        }
//        cout << endl;
//        for (auto &h:output) {
//            for (auto &w:h) {
//                cout << w << "\t";
//            }
//            cout << endl;
//        }
        return output;
    }

    void dfs(vector<vector<int>> &matrix, int h, int w, int flag, int value) {
        if (h != -1 && h != high && w != -1 && w != wide && matrix[h][w] >= value) {
            if (sea[h][w] == flag)
                return;
            if (sea[h][w] == -flag) {
                sea[h][w] = flag;
                output.push_back({h, w});
            }
            if (sea[h][w] == 0)
                sea[h][w] = flag;
            dfs(matrix, h - 1, w, flag, matrix[h][w]);
            dfs(matrix, h, w - 1, flag, matrix[h][w]);
            dfs(matrix, h, w + 1, flag, matrix[h][w]);
            dfs(matrix, h + 1, w, flag, matrix[h][w]);
        }
    }
};

TEST(pacificAtlantic, 1) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input{{1, 2, 2, 3, 5},
                              {3, 2, 3, 4, 4},
                              {2, 4, 5, 3, 1},
                              {6, 7, 1, 4, 5},
                              {5, 1, 1, 2, 4}};
    vector<vector<int>> answer{{0, 4},
                               {1, 3},
                               {1, 4},
                               {2, 2},
                               {3, 0},
                               {3, 1},
                               {4, 0}};
    auto output = Solution().pacificAtlantic(input);
    EXPECT_EQ(answer, output);
}

TEST(pacificAtlantic, 2) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input{{3, 3, 3, 3, 3, 3},
                              {3, 0, 3, 3, 0, 3},
                              {3, 3, 3, 3, 3, 3}};
    vector<vector<int>> answer{{0, 4},
                               {1, 3},
                               {1, 4},
                               {2, 2},
                               {3, 0},
                               {3, 1},
                               {4, 0}};
    auto output = Solution().pacificAtlantic(input);
    EXPECT_EQ(answer, output);
}