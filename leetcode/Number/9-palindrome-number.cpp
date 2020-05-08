//
// Created by 侯正罡 on 2020/4/29.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    /**
     *   特殊情况：
        如上所述，当 x < 0 时，x 不是回文数。
        同样地，如果数字的最后一位是 0，为了使该数字为回文，
        则其第一位数字也应该是 0, 只有 0 满足这一属性
     * @param x
     * @return
     */
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber/10;
    }
};

TEST(isPalindrome, 1) {
    cout << endl;
    int n = 12321;
    bool answer = true;
    auto output = Solution().isPalindrome(n);
    EXPECT_EQ(answer, output);
}