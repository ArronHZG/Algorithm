//
// Created by 侯正罡 on 2020/4/1.
//
/**
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/combination-sum
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

    vector<vector<int>> res;
    vector<int> his;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        DFS(candidates, target, 0);
        return res;
    }

    void DFS(vector<int> &candidates, int target, int pos) {
        int stack_sum = sum(his);
        if (stack_sum == target) {
            auto tmp = his;
            res.push_back(tmp);
        } else if (stack_sum < target) {
            for (int i = pos; i < candidates.size(); i++) {
                his.push_back(candidates[i]);
                DFS(candidates, target, i);
                his.pop_back();
            }
        }
    }

    int sum(vector<int> &stack) {
        int sum = 0;
        for (auto i:stack) {
            sum += i;
            cout << i << " ";
        }
        cout << endl;
        return sum;
    }
};

TEST(combinationSum, 1) { /* NOLINT */
    cout << endl;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> answer = {{2, 2, 3},
                                  {7}};

    auto output = Solution().combinationSum(candidates, target);
    EXPECT_EQ(answer, output);

}