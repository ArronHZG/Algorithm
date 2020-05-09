//
// Created by 侯正罡 on 2020/5/9.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.empty())
            return 0;
        int n = 0;
        int j = 0;
        while (j != nums.size()) {
            if (nums[j] == val) {
                n++;
            } else {
                nums[j - n] = nums[j];
            }
            j++;
        }
        return j - n;
    }
};

TEST(removeElement, 1) {
    cout << endl;
    auto start_time = clock();
    vector<int> input = {3, 2, 2, 3,1,2,3,4,5,6,7};
    int n = 3;
    int answer = 2;
    auto output = Solution().removeElement(input, n);
    EXPECT_EQ(answer, output);
    auto end_time = clock();
    cout << "time cost:" << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

}