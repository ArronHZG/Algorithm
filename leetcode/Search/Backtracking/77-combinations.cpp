//
// Created by 侯正罡 on 2020/4/1.
//

/**
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/combinations
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
    vector<vector<int>> result;
    vector<int> his;

    void DFS(int depth, int pos, int n, int k) {
        if (depth == k) {
            result.push_back(his);
        } else {
            for (int i = pos + 1; i <= n; i++) {
                his.push_back(i);
                for (auto j:his) {
                    cout << j << " ";
                }
                cout << endl;
                DFS(depth + 1, i, n, k);
                his.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        for (int i = 1; i <= n; i++) {
            his.push_back(i);
            DFS(1, i, n, k);
            his.pop_back();
        }
        return result;
    }
};


TEST(combine, 1) { /* NOLINT */
    cout << endl;
    int k = 2;
    int n = 4;
    vector<vector<int>> answer =
            {{2, 4},
             {3, 4},
             {2, 3},
             {1, 2},
             {1, 3},
             {1, 4}};

    auto output = Solution().combine(n, k);
    EXPECT_EQ(answer, output);

}