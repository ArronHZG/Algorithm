//
// Created by 侯正罡 on 2020/4/24.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c)
            return nums;
        vector<vector<int>> res(r, vector<int>(c));
        int index = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = nums[index / n][index % n];
                index++;
            }
        }
        return res;
    }
};

TEST(matrixReshape, 1) {
    cout << endl;
    vector<vector<int>> input = {{1, 2},
                                 {3, 4}};
    int r = 1;
    int c = 4;
    vector<vector<int>> answer = {{1, 2, 3, 4}};;
    auto output = Solution().matrixReshape(input, r, c);
    EXPECT_EQ(answer, output);
}