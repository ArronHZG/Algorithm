//
// Created by 侯正罡 on 2020/4/2.
//


#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <cstring>
#include <gtest/gtest.h>


using namespace std;

template<typename T>
void print(vector<T> vec) {
    for (auto a : vec) {
        cout << a << " ";
    }
    cout << endl;
}

template<typename T>
void print(vector<vector<T>> vec) {
    for (const auto &v: vec) {
        print(v);
    }
    cout << endl;
}

class Solution {
public:

    bool check(const string &s, int i, int j) {
        if (j < i) return true;
        if (s[i++] == s[j--]) return check(s, i, j);
        else return false;
    }

    void palindrome(int pos, string &s, vector<vector<string>> &res, vector<string> &his) {
        if (pos >= s.size()) {
            res.push_back(his);
        }
        for (int i = pos; i < s.size(); i++) {
            if (check(s, pos, i)) {
                his.push_back(s.substr(pos, i - pos + 1));
                palindrome(i + 1, s, res, his);
                his.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> his;
        palindrome(0, s, res, his);
        return res;

    }
};

TEST(partition, 1) { /* NOLINT */
    cout << endl;
    string input = "aab";
    vector<vector<string>> answer =
            {{"a",  "a", "b"},
             {"aa", "b"}};
    auto output = Solution().partition(input);
    EXPECT_EQ(answer, output);

}