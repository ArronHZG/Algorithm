//
// Created by arron on 19-5-3.
//

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> vRows;
        vRows.reserve(numRows);
        for (auto i = 0; i < numRows; i++) {
            vRows.emplace_back("");
        }
        int flag = 0;//0 表示压栈 1 表示弹栈
        int vRowsId = 0;
        for (char &letter : s) {
            vRows[vRowsId].push_back(letter);
            if (flag == 0) {
                vRowsId++;
                if (vRowsId == numRows) {
                    flag = 1;
                    vRowsId -= 2;
                }
            } else {
                vRowsId--;
                if (vRowsId == 0) {
                    flag = 0;
                } else if (vRowsId == -1)
                {
                    flag = 0;
                    vRowsId = 1;
                }
            }
        }
        string answer;
        for (auto item :vRows) {
            answer += item;
        }
        return answer;
    }
};


TEST(convert, 1) {
    cout << endl;

    string s = "AB";
    int numRows = 1;
    string answer = "AB";
    auto output = Solution().convert(s, numRows);
    EXPECT_EQ(answer, output);
}


TEST(convert, 2) {
    cout << endl;

    string s = "PAYPALISHIRING";
    int numRows = 4;
    string answer = "PINALSIGYAHRPI";
    auto output = Solution().convert(s, numRows);
    EXPECT_EQ(answer, output);
}

TEST(convert, 3) {
    cout << endl;

    string s = "ABCD";
    int numRows = 2;
    string answer = "ACBD";
    auto output = Solution().convert(s, numRows);
    EXPECT_EQ(answer, output);
}
