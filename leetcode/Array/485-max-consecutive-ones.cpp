//
// Created by 侯正罡 on 2020/4/24.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int maxOne = 0, cur = 0;
        for (int x : nums) {
            cur = x == 0 ? 0 : cur + 1;
            if (cur != 0 && cur > maxOne)
                maxOne = cur;
        }
        return maxOne;
    }
};

TEST(findMaxConsecutiveOnes, 1) {
    cout << endl;
    vector<int> input = {1, 1, 0, 1, 1, 1};
    int answer = 3;
    auto output = Solution().findMaxConsecutiveOnes(input);
    EXPECT_EQ(answer, output);
}