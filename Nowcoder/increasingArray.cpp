//
// Created by 侯正罡 on 2020/4/22.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:

    long long IncreasingArray(vector<int> &array) {
        // write code here
        long long baseIncrease = 0;
        for (int i = 1; i < array.size(); i++) {
            auto dif = array[i] - array[i - 1];
            if (dif <= 0) {
                baseIncrease += -dif + 1;
            }
        }
        return baseIncrease;
    }
};

TEST(increasingArray, 1) {
    cout << endl;
    vector<int> input = {4, 2, 5};
    int n = 0;
    int answer = 3;
    auto output = Solution().IncreasingArray(input);
    EXPECT_EQ(answer, output);
}