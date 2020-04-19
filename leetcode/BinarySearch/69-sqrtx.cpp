//
// Created by 侯正罡 on 2020/2/3.
//

/**
 *
 * 实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
     由于返回类型是整数，小数部分将被舍去。

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        long right = x;
        long middle = right / 2;
        while (true) {
            if (middle * middle <= x) {
                if ((middle + 1) * (middle + 1) > x)
                    return middle;
                else
                    middle = middle + (right - middle) / 2;
            } else {
                right = middle;
                middle = middle / 2;
            }
        }
    }
};

//class Solution {
//public:
//    int mySqrt(int x) {
//        // 照顾 0
//        long left = 0;
//        // 照顾 1
//        long right = x / 2 + 1;
//        while (left < right) {
//            long middle = left + (right - left + 1) / 2;
//            long square = middle * middle;
//            if (square <= x) {
//                left = middle;
//            } else {
//                right = middle - 1;
//            }
//        }
//        return (int) left;
//    }
//};


TEST(mySqrt, 1) { /* NOLINT */
    cout << endl;
    auto input = 8;
    auto answer = 2;
    auto output = Solution().mySqrt(input);
    EXPECT_EQ(answer, output);
}

TEST(mySqrt, 2) { /* NOLINT */
    cout << endl;
    auto input = 1;
    auto answer = 1;
    auto output = Solution().mySqrt(input);
    EXPECT_EQ(answer, output);
}

TEST(mySqrt, 3) { /* NOLINT */
    cout << endl;
    auto input = 35;
    auto answer = 5;
    auto output = Solution().mySqrt(input);
    EXPECT_EQ(answer, output);
}