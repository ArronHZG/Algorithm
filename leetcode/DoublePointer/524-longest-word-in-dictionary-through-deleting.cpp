//
// Created by 侯正罡 on 2020/1/20.
//

/*
给定一个字符串和一个字符串字典，找到字典里面最长的字符串，
该字符串可以通过删除给定字符串的某些字符来得到。
如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。

示例 1:

输入:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

输出:
"apple"
示例 2:

输入:
s = "abpcplea", d = ["a","b","c"]

输出:
"a"
说明:

所有输入的字符串只包含小写字母。
字典的大小不会超过 1000。
所有输入的字符串长度不会超过 1000。

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <map>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string> &d) {
        string max_str;
        for (auto &str : d) {
            if (isSubsequence(str, s)) {
                if (str.length() > max_str.length() || (str.length() == max_str.length() && str.compare(max_str) < 0))
                    max_str = str;
            }
        }
        return max_str;
    }

    bool isSubsequence(string x, string y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x[j] == y[i])
                j++;
        return j == x.length();
    }
};

TEST(findLongestWord, 1) { /* NOLINT */
    std::cout << std::endl;
    string input = "bab";
    vector<string> d{"ba", "ab", "a", "b"};
    string answer = "ab";
    string output = Solution().findLongestWord(input,d);
    cout<<answer<<endl;
    EXPECT_EQ(answer, output);
}