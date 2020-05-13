//
// Created by 侯正罡 on 2020/5/9.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    /**
     * islower(char c) 是否为小写字母
        isuppper(char c) 是否为大写字母
        isdigit(char c) 是否为数字
        isalpha(char c) 是否为字母
        isalnum(char c) 是否为字母或者数字
        toupper(char c) 字母小转大
        tolower(char c) 字母大转小
     * @param s
     * @return
     */
    bool isPalindrome(string s) {

        string tmp;
        for (auto c : s) {
            if (islower(c) || isdigit(c)) tmp += c;
            else if (isupper(c)) tmp += tolower(c);
        }
        int right = tmp.size() - 1;
        int left = 0;
        while (left < right) {
            if (tmp[left++] == tmp[right--]);
            else return false;
        }
        return true;
    }
};

TEST(isPalindrome, 1) {
    cout << endl;
    auto start_time = clock();
    string input = "A man, a plan, a canal: Panama";
    int answer = true;
    auto output = Solution().isPalindrome(input);
    EXPECT_EQ(answer, output);
    auto end_time = clock();
    cout << "time cost:" << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

}