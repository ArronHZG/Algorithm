//
// Created by 侯正罡 on 2020/4/2.
//

/**
 * 37. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.
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


using namespace std;


void print(vector<pair<int, int>> vec) {
    for (auto a : vec) {
        cout << a.first << ' ' << a.second << " | ";
    }
    cout << endl;
}

template<typename T>
void print(vector<T> vec) {
    for (auto a : vec) {
        cout << a << ' ';
    }
    cout << endl;
}

template<typename T>
void print(vector<vector<T>> vec) {
    for (const auto &v: vec) {
        print(v);
    }
    cout << endl;
}

class Solution {
public:
    using Point = pair<int, int>;

    bool check(int row, int col, char value, vector<vector<char>> &board) {
        int grid_row = row / 3;
        int grid_col = col / 3;
        for (int i = grid_row * 3; i < (grid_row + 1) * 3; i++) {
            for (int j = grid_col * 3; j < (grid_col + 1) * 3; j++) {
                if (value == board[i][j])
                    return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (value == board[i][col])
                return false;
        }

        for (int j = 0; j < 9; j++) {
            if (value == board[row][j])
                return false;
        }
        return true;
    }

    Point getNext(int row, int col, vector<vector<char>> &board) {
        Point next = {-1, -1};
        if (row != 9 && col != 9) {
            for (int j = col; j < 9; j++) {
                if (board[row][j] == '.') return make_pair(row, j);
            }
            for (int i = row + 1; i < 9; i++)
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') return make_pair(i, j);
                }
        }
        return next;
    }

    bool dfs(int row, int col, vector<vector<char>> &board, vector<Point> &stack) {
        auto p = getNext(row, col, board);
        if (p.first == -1) {
            return true;
        }
        bool is_check = false;
        for (char c = '1'; c <= '9'; c++) {
            if (check(p.first, p.second, c, board)) {
                board[p.first][p.second] = c;
                stack.emplace_back(p.first, p.second);
                print(stack);
                print<char>(board);
                if (p.second + 1 == 9) {
                    is_check = dfs(p.first + 1, 0, board, stack);
                } else {
                    is_check = dfs(p.first, p.second + 1, board, stack);
                }
            }
        }
        if (!is_check) {
            auto g = stack[stack.size() - 1];
            stack.pop_back();
            board[g.first][g.second] = '.';
        }
        return is_check;
    }

    vector<vector<char>> solveSudoku(vector<vector<char>> &board) {
        vector<Point> stack;
        dfs(0, 0, board, stack);
//        print<char>(board);
        return board;
    }
};
TEST(solveSudoku, 1) { /* NOLINT */
    cout << endl;
    vector<vector<char>> input =
            {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> answer =
            {{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
             {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
             {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
             {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
             {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
             {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
             {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
             {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
             {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};

    auto output = Solution().solveSudoku(input);
    EXPECT_EQ(answer, output);

}

TEST(solveSudoku, 2) { /* NOLINT */
    cout << endl;
    vector<vector<char>>
            input = {{'.', '.', '9', '7', '4', '8', '.', '.', '.'},
                     {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
                     {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
                     {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
                     {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
                     {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
                     {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
                     {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
                     {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};

    vector<vector<char>> answer;
    auto output = Solution().solveSudoku(input);
    EXPECT_EQ(answer, output);

}



