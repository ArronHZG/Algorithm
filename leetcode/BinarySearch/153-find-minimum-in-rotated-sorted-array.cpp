//
// Created by 侯正罡 on 2020/2/3.
//

/**
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        // initializing left and right pointers.
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        if (len == 1 || nums[right] > nums[0]) {
            return nums[0];
        }
        while (right >= left) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }
            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
};

TEST(findMinimumInRotatedSortedArray, 1) { /* NOLINT */
    cout << endl;
    vector<int> input = {3, 4, 5, 1, 2};
    auto answer = 1;
    auto output = Solution().findMin(input);
    EXPECT_EQ(answer, output);
}

TEST(findMinimumInRotatedSortedArray, 2) { /* NOLINT */
    cout << endl;
    vector<int> input = {4, 5, 6, 7, 0, 1, 2};
    auto answer = 0;
    auto output = Solution().findMin(input);
    EXPECT_EQ(answer, output);
}

TEST(findMinimumInRotatedSortedArray, 3) { /* NOLINT */
    cout << endl;
    vector<int> input = {0, 1, 2};
    auto answer = 0;
    auto output = Solution().findMin(input);
    EXPECT_EQ(answer, output);
}

TEST(findMinimumInRotatedSortedArray, 4) { /* NOLINT */
    cout << endl;
    vector<int> input = {1};
    auto answer = 1;
    auto output = Solution().findMin(input);
    EXPECT_EQ(answer, output);
}

TEST(findMinimumInRotatedSortedArray, 5) { /* NOLINT */
    cout << endl;
    vector<int> input = {2, 1};
    auto answer = 1;
    auto output = Solution().findMin(input);
    EXPECT_EQ(answer, output);
}

TEST(findMinimumInRotatedSortedArray, 6) { /* NOLINT */
    cout << endl;
    vector<int> input = {3, 1, 2};
    auto answer = 1;
    auto output = Solution().findMin(input);
    EXPECT_EQ(answer, output);
}

TEST(findMinimumInRotatedSortedArray, 7) { /* NOLINT */
    cout << endl;
    vector<int> input = {5, 1, 2, 3, 4};
    auto answer = 1;
    auto output = Solution().findMin(input);
    EXPECT_EQ(answer, output);
}