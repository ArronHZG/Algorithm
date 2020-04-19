//
// Created by 侯正罡 on 2020/4/1.
//

/**
 * Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/subsets
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
#include <cstring>
#include <gtest/gtest.h>


using namespace std;

template<typename T>
void print(vector<T> vec) {
    for (auto a : vec) {
        cout << a << " ";
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
    void doDFS(int pos, vector<int> &num, vector<vector<int>> &res, vector<int> &his) {
        res.push_back(his);
        for (int i = pos; i < num.size(); i++) {
            his.push_back(num[i]);
//            print(his);
            doDFS(i + 1, num, res, his);
            his.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> his;
        doDFS(0, nums, res, his);
        return res;

    }
};

TEST(subsets, 1) { /* NOLINT */
    cout << endl;
    vector<int> input = {1, 2, 3};
    vector<vector<int>> answer =
            {{},
             {1},
             {1, 2},
             {1, 2, 3},
             {1, 3},
             {2},
             {2, 3},
             {3}};

    auto output = Solution().subsets(input);
    EXPECT_EQ(answer, output);

}