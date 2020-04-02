//
// Created by 侯正罡 on 2020/4/1.
//

/**

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
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
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        __combinationSum(candidates, target, temp, 0);
        return res;
    }

private:
    void __combinationSum(vector<int> &candidates, int target, vector<int> temp, int start) {
        if (target == 0) {
            auto a = temp;
            res.push_back(a);
        } else {
            for (int i = start; i < candidates.size(); i++) {
                if (i > start && candidates[i - 1] == candidates[i]) {
                    continue;
                }
                if (target >= candidates[i]) {
                    temp.push_back(candidates[i]);
                    __combinationSum(candidates, target - candidates[i], temp, i + 1);
                    temp.pop_back();
                }
            }
        }
    }
};

TEST(combinationSum2, 5) { /* NOLINT */
    cout << endl;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> answer = {{1, 1, 6},
                                  {1, 2, 5},
                                  {1, 7},
                                  {2, 6}};

    auto output = Solution().combinationSum2(candidates, target);
    EXPECT_EQ(answer, output);

}