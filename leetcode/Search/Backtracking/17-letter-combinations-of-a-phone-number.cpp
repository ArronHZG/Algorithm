//
// Created by 侯正罡 on 2020/3/31.
//
/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<string> phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> combinations;

    void doCombinations(string digits, string str, int i) {
        if (digits.size() == i) {
            combinations.push_back(str);
        } else {
            auto s = phone[digits[i] - '2'];
            for (char j : s) {
                str.push_back(j);
                doCombinations(digits, str, i + 1);
                str.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return combinations;
        }
        doCombinations(digits, "", 0);
        return combinations;
    }
};

TEST(letterCombinations, 1) { /* NOLINT */
    cout << endl;
    string input = "23";
    vector<string> answer = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    auto output = Solution().letterCombinations(input);
    EXPECT_EQ(answer, output);
}