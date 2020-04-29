//
// Created by 侯正罡 on 2020/4/26.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    vector<string> splitString(string str, char s, int n, int m) {
        vector<string> splitStr;
        vector<string> res;
        int begin = 0;
        for (int i = 0; i < str.size(); i++) {
            if (s == str[i]) {
                splitStr.push_back(str.substr(begin, i - begin));
                begin = i + 1;
            }
        }
        splitStr.push_back(str.substr(begin, str.size() - begin));

        int sum_size = splitStr[0].size();
        begin = 0;
        for (int i = 1; i < splitStr.size(); i++) {
            int size = splitStr[i].size();
            if (size + sum_size + 1 < m) {
                sum_size += size + 1;
            } else {
                string tmp;
                while (begin < i) {
                    tmp += splitStr[begin++] + s;
                }
                tmp.pop_back();
                res.push_back(tmp);
                sum_size = size;
            }
        }
        for (int i = begin; i < splitStr.size(); i++) {
            res.push_back(splitStr[i]);
        }
        return res;
    }
};

TEST(splitString, 1) {
    cout << endl;
    string input = "abc/def/hijk";
    char s = '/';
    int n = 3;
    int m = 5;
    vector<string> answer = {"abc", "def", "hijk"};
    auto output = Solution().splitString(input, s, n, m);
    for (int i = 0; i < output.size() - 1; i++) {
        cout << output[i] << " ";
    }
    cout << output.back() << endl;
}