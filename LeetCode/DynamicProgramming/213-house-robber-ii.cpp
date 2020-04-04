//
// Created by 侯正罡 on 2020/4/3.
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        else if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);
        else if(n == 3) return max(max(nums[1], nums[0]), nums[2]);

        //最后一家不偷
        vector<int>dp1(n - 1, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[1], nums[0]);
        for(int i = 2; i < n - 1; ++ i)dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);

        //第一家不偷
        vector<int>dp2(n, 0);
        dp2[1] = nums[1];
        dp2[2] = max(nums[2], nums[1]);
        for(int i = 3; i < n; ++ i)dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);

        return max(dp1.back(), dp2.back());
    }
};

TEST(rob, 1) { /* NOLINT */
    cout << endl;
    vector<int> input = {2, 3, 2};
    int answer = 3;
    auto output = Solution().rob(input);
    EXPECT_EQ(answer, output);
}


