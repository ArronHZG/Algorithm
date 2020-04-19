//
// Created by arron on 19-5-6.
//

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

//翻转数字
//处理0，负号，溢出
//2^31-1=
class Solution {
public:
    int reverse(int x) {
        long output = 0;
        while (x != 0) {
            output = output * 10 + x % 10;
            x /= 10;
            if(output> 2147483647 || output<-2147483648)
                return 0;
        }
        return output;
    }
};


TEST(reverse, 1) {
    cout << endl;
    int input = -1230;
    int answer = -321;
    auto output = Solution().reverse(input);
    EXPECT_EQ(answer, output);
}


TEST(reverse, 2) {
    cout << endl;
    int input = 1534236469;
    int answer = 0;
    auto output = Solution().reverse(input);
    EXPECT_EQ(answer, output);
}


TEST(reverse, 3) {
    cout << endl;
    int input = -2147483412;
    int answer = -2143847412;
    auto output = Solution().reverse(input);
    EXPECT_EQ(answer, output);
}