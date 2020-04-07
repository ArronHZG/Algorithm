//
// Created by 侯正罡 on 2020/4/7.
//

/**
 *
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

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
#include "show.h"

using namespace std;

class NumArray {
public:
    vector<int> sums;

    NumArray(vector<int> &nums) {
        sums.push_back(0);
        if (nums.empty()) return;
        sums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            sums.push_back(sums[i] + nums[i]);
        }
        print<int>(sums);
    }

    int sumRange(int i, int j) {
        if (j + 1 < 0 || j + 1 >= sums.size() || i < 0 || i >= sums.size() || i > j) return 0;
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

TEST(climbStairs, 1) { /* NOLINT */
    cout << endl;
    vector<int> input = {-2, 0, 3, -5, 2, -1};
    int i = 1;
    int j = 2;
    int answer = 3;
    auto num_array = NumArray(input);
    auto output = num_array.sumRange(i, j);
    EXPECT_EQ(answer, output);
}
