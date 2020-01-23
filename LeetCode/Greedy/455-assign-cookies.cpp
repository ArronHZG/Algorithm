//
// Created by 侯正罡 on 2020/1/23.
//

/**
 *
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。
 但是，每个孩子最多只能给一块饼干。对每个孩子 i ，都有一个胃口值 gi ，
 这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，
 都有一个尺寸 sj 。
 如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
 你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

注意：

你可以假设胃口值为正。
一个小朋友最多只能拥有一块饼干。

示例 1:

输入: [1,2,3], [1,1]

输出: 1

解释:
你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
所以你应该输出1。
示例 2:

输入: [1,2], [1,2,3]

输出: 2

解释:
你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
你拥有的饼干数量和尺寸都足以让所有孩子满足。
所以你应该输出2.


一个孩子只有满足和不满足的情况
大于等于胃口的饼干可以满足,小于不满足

Step1 给孩子和饼干都排序
Step2 分别维护一个index
Step3 策略：如果当前饼干可以满足胃口，则count 和 两个index加一，否则饼干的index加一(更大的饼干)

 */
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &appetite, vector<int> &cookie) {
        int count = 0;
        sort(appetite.begin(), appetite.end());
        sort(cookie.begin(), cookie.end());
        auto p_appetite = appetite.begin();
        auto p_cookie = cookie.begin();
        while (p_appetite != appetite.end() && p_cookie != cookie.end()) {
            if (*p_cookie >= *p_appetite) {
                ++p_cookie;
                ++p_appetite;
                ++count;
            } else ++p_cookie;
        }
        return count;
    }
};


TEST(findContentChildren, 3) { /* NOLINT */
    cout << endl;
    vector<int> input{1, 2, 3, 4};
    vector<int> cookie{2, 2};
    int answer = 2;
    int output = Solution().findContentChildren(input, cookie);
    EXPECT_EQ(answer, output);
}
