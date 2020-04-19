//
// Created by 侯正罡 on 2020/3/31.
//

/**
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/word-search
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
#include <gtest/gtest.h>
#include <cstring>

using namespace std;

class Solution {
public:

    bool DFS(vector<vector<char>> &board, const string &word, int pos,
             pair<int, int> coo) {
        vector<pair<int, int>> move = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        if (pos == word.size()) {
            return true;
        }
        if (coo.first < 0 || coo.first == board.size() || coo.second < 0 || coo.second == board[0].size()) {
            return false;
        }
        if (board[coo.first][coo.second] == word[pos]) {
            char tmp = board[coo.first][coo.second];
            board[coo.first][coo.second] = 0; // 避免该位重复使用
            for (pair<int, int> m:move) {
                cout << m.first << " " << m.second << endl;
                pair<int, int> k = {coo.first + m.first, coo.second + m.second};
                cout << k.first << " " << k.second << endl;
                if (DFS(board, word, pos + 1, k)) {
                    return true;
                }
            }
            board[coo.first][coo.second] = tmp;
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (DFS(board, word, 0, {row, col})) {
                    return true;
                }
            }
        }
        return false;

    }
};

TEST(exist, 1) { /* NOLINT */
    cout << endl;
    vector<vector<char>> input = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    auto answer = true;
    auto output = Solution().exist(input, word);
    EXPECT_EQ(answer, output);
}


TEST(exist, 2) { /* NOLINT */
    cout << endl;
    vector<pair<int, int>> move = {{1,  0},
                                   {0,  1},
                                   {-1, 0},
                                   {0,  -1}};
    for (pair<int, int> m:move) {
        cout << m.first << " " << m.second << endl;
    }

}