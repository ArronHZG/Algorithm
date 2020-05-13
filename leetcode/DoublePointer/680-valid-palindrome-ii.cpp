//
// Created by 侯正罡 on 2020/1/18.
//

/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:

字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。


来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/valid-palindrome-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <iostream>
#include <gtest/gtest.h>
#include <map>

using namespace std;

class Solution {
public:
    bool validPalindromeII(string s) {
        uint low = 0;
        uint high = s.size() - 1;
        bool diff = false;
        while (low < high) {
            if (s[low] == s[high]) {
                low++;
                high--;
            } else {
                return isPalindrome(s, low + 1, high) || isPalindrome(s, low, high - 1);
            }
        }
        return true;
    }

    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};

TEST(validPalindromeII, 1) { /* NOLINT */
    std::cout << std::endl;
    string input = "aba";
    bool answer = true;
    bool output = Solution().validPalindromeII(input);
    EXPECT_EQ(answer, output);
}

TEST(validPalindromeII, 2) { /* NOLINT */
    std::cout << std::endl;
    string input = "abcca";
    bool answer = true;
    bool output = Solution().validPalindromeII(input);
    EXPECT_EQ(answer, output);
}


TEST(validPalindromeII, 3) { /* NOLINT */
    std::cout << std::endl;
    string input = "1234521";
    bool answer = false;
    bool output = Solution().validPalindromeII(input);
    EXPECT_EQ(answer, output);
}
