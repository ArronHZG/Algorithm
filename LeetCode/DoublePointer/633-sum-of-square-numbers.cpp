//
// Created by 侯正罡 on 2020/1/18.
//
/**
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c。

示例1:

输入: 5
输出: True
解释: 1 * 1 + 2 * 2 = 5
 

示例2:

输入: 3
输出: False


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-square-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
    bool merge(int c) {
        long low = 0, high = long(sqrt(c));
        while (low <= high) {
            long sum = low * low + high * high;
            if (sum == c) {
                return true;
            } else if (sum < c)
                ++low;
            else
                --high;
        }
        return false;

    }
};

TEST(judgeSquareSum, 1) { /* NOLINT */
    std::cout << std::endl;
    int input = 5;
    bool answer = true;
    bool output = Solution().merge(input);
    EXPECT_EQ(answer, output);
}

TEST(judgeSquareSum, 2) { /* NOLINT */
    std::cout << std::endl;
    int input = 9;
    bool answer = true;
    bool output = Solution().merge(input);
    EXPECT_EQ(answer, output);
}

TEST(judgeSquareSum, 3) { /* NOLINT */
    std::cout << std::endl;
    int input = 2;
    bool answer = true;
    bool output = Solution().merge(input);
    EXPECT_EQ(answer, output);
}

TEST(judgeSquareSum, 4) { /* NOLINT */
    std::cout << std::endl;
    int input = 1;
    bool answer = true;
    bool output = Solution().merge(input);
    EXPECT_EQ(answer, output);
}


TEST(judgeSquareSum, 10000) { /* NOLINT */
    std::cout << std::endl;
    int input = 100000;
    bool answer = true;
    bool output = Solution().merge(input);
    EXPECT_EQ(answer, output);
}