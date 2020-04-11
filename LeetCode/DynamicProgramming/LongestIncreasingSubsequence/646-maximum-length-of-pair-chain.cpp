//
// Created by 侯正罡 on 2020/4/12.
//

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
#include<algorithm>
#include "show.h"

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

    }
};

TEST(findLongestChain, 1) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input = {{1, 2}, {3, 6}, {4, 5}};
    int answer = 2;
    auto output = Solution().findLongestChain(input);
    EXPECT_EQ(answer, output);
}