//
// Created by 侯正罡 on 2020/5/13.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        if (nums.size() == 1 || nums[left] < nums[right])
            return nums[left];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        return nums[left];
    }
};


TEST(findMinII, 1) { /* NOLINT */
    cout << endl;
    vector<int> input = {10, 1, 10, 10, 10};
    auto answer = 10;
    auto output = Solution().findMinII(input);
    EXPECT_EQ(answer, output);
}