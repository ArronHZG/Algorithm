//
// Created by 侯正罡 on 2020/4/29.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        vector<pair<string, int>> memo;
        int left = 0;
        int right = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                left = i;
            }
            if (s[i] == ']') {
                int times = stoi(s.substr(right + 1, left - right - 1));
                string k = s.substr(left + 1, i - left - 1);
                cout << times << k << endl;
                memo.emplace_back(k, times);
                right = i;
            }
        }
        string k = s.substr(right + 1);
        if (!k.empty()) memo.emplace_back(k, 1);
        string res;
        for (const auto &m: memo) {
            for (int i = 0; i < m.second; i++) {
                for (auto c:m.first) {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};

TEST(decodeString, 1) {
    cout << endl;
    string input = "3[a2[c]]ef";
    string answer = "accaccaccef";
    auto output = Solution().decodeString(input);
    EXPECT_EQ(answer, output);
}