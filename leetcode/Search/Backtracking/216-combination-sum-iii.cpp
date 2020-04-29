//
// Created by 侯正罡 on 2020/4/1.
//
/**
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <gtest/gtest.h>
#include <show.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> result = {};
    vector<int> his = {};

    vector<vector<int>> combinationSum3(int n, int k) {
        _combinationSum3(0, 0, n, k);
        return result;
    }

    void _combinationSum3(int depth, int pos, int n, int k) {
        if (depth == k) {
            if (n == 0) {
                result.push_back(his);
            }
        } else {
            for (int i = pos + 1; i <= n / (k - depth); i++) {
                his.push_back(i);
                _combinationSum3(depth + 1, i, n - i, k);
                his.pop_back();
            }
        }
    }
};


TEST(combinationSum3,1) { /* NOLINT */
    cout << endl;
    int k = 3;
    int n = 12;
    vector<vector<int> > answer =
            {
                    {1, 2, 6},
                    {1, 3, 5},
                    {2, 3, 4}
            };

    auto so = Solution();
    auto output = so.combinationSum3(n, k);
    print<int>(output);
    print<int>(so.result);
}
