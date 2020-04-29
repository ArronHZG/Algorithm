//
// Created by 侯正罡 on 2020/4/29.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    string decoder(int n, string str) {
        if (n == 0) return str;
        while (n != 0) {
            for (int i = 1; i <= str.size(); i++) {
                if (str[i] < str[i - 1]) {
                    str = str.substr(0, i - 1) + str.substr(i,str.size()-i);
                    n--;
                    break;
                }
            }
        }
        return str;
    }
};

TEST(decoder, 1) {
    cout << endl;
    string input = "bacaa";
    int n = 1;
    string answer = "acaa";
    auto output = Solution().decoder(n, input);
    EXPECT_EQ(answer, output);
}