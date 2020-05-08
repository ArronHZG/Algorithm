//
// Created by 侯正罡 on 2020/4/29.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    string addStrings1(string num1, string num2) {
        string res;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            auto n1 = i >= 0 ? num1[i] - '0' : 0;
            auto n2 = j >= 0 ? num2[j] - '0' : 0;
            i--, j--;
            auto tmp = n1 + n2 + carry;
            carry = tmp / 10;
            tmp = tmp % 10;
//            cout << n1 << " " << n2 << endl;
            ostringstream resStream;
            resStream << tmp << res;
            res = resStream.str();
        }
        if (carry) {
            ostringstream resStream;
            resStream << "1" << res;
            res = resStream.str();
        }
        return res;
    }


    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string result;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            auto n1 = i >= 0 ? num1[i] - '0' : 0;
            auto n2 = j >= 0 ? num2[j] - '0' : 0;
            i--, j--;
            auto sum = n1 + n2 + carry;
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }
        if (carry == 1) {
            result.push_back('1');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

TEST(addStrings, 1) {
    cout << endl;
    string str1 = "51";
    string str2 = "955";
    string answer = "1006";
    auto output = Solution().addStrings(str1, str2);
    EXPECT_EQ(answer, output);
}