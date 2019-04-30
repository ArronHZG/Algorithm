//
// Created by arron on 2019/4/29.
//
#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> queue;
        queue.emplace_back("/");
        auto i = path.begin() + 1;
        while (i != path.end()) {
            if (*i == '/') {
                if (*(queue.end() - 1) != "/") {
                    queue.emplace_back("/");
                }
                i++;
            } else {
                auto p = i;
                while (*p != '/' && p != path.end()) p++;//*p=='/'
                string word(i, p);
                if (word == ".");
                else if (word == ".." && queue.size() >= 3) {
                    queue.pop_back();
                    queue.pop_back();
                } else if (word != "..") {
                    queue.push_back(word);
                }
                i = p;
            }
        }
        //判断结尾是否为/，但是如果字符串只有一个 / 就不删
        if (*(queue.end() - 1) == "/" && queue.end() - 1 != queue.begin()) queue.pop_back();
        string output;
        for (auto &s:queue) {
            output.append(s);
        }
        return output;
    }
};

TEST(simplifyPath, 1) {
    cout << endl;
    string input = "/a//b////c/d//././/../";
    string answer = "/a/b/c";
    string output = Solution().simplifyPath(input);
    EXPECT_EQ(answer, output);
}

TEST(simplifyPath, 2) {
    cout << endl;
    string input = "/../../";
    string answer = "/";
    string output = Solution().simplifyPath(input);
    EXPECT_EQ(answer, output);
}