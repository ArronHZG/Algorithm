//
// Created by 侯正罡 on 2020/1/21.
//
/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <gtest/gtest.h>
#include<queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<> > q;
        for(auto it:nums){
            q.push(it);
            if(q.size()>k) q.pop();
        }
        return q.top();
    }
};


TEST(findKthLargest, 1) { /* NOLINT */
    std::cout << std::endl;
    vector<int> input{3, 2, 1, 5, 6, 4};
    int k = 2;
    int answer = 5;
    int output = Solution().findKthLargest(input, k);
    EXPECT_EQ(answer, output);
}
