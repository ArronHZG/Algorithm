//
// Created by 侯正罡 on 2020/5/9.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int i = 0;
        int j = 0;
        while (j != nums.size()) {
            if (nums[j] == nums[i]) {
                j++;
            } else {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

TEST(removeDuplicates, 1) {
    cout << endl;
    auto start_time = clock();
    vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int answer = 5;
    auto output = Solution().removeDuplicates(input);
    EXPECT_EQ(answer, output);
    auto end_time = clock();
    cout << "time cost:" << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

}