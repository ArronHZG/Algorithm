//
// Created by arron on 19-4-26.
//
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> dirt;
        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
            if (dirt.find(x) == dirt.end()) {
                dirt[nums[i]] = i;
            } else {
                return vector<int>{dirt[x], i};
            }
        }
        return vector<int>();
    }
};

TEST(twoNum, 1) {
    std::cout << std::endl;
    vector<int> input = {2, 7, 11, 15};
    int target = 9;
    vector<int> answer = {0, 1};
    vector<int> output = Solution().twoSum(input, target);
    EXPECT_EQ(answer, output);
}