//
// Created by 侯正罡 on 2020/5/13.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    /**
     * 双指针思想，i为慢指针，指向当前子串开始位置，j为快指针，指向当前判断的字符
        idx[s[j]]记录字符s[j]上次出现的位置
        每次迭代记录字符出现位置
        当字符s[j]上次出现的位置大于当前子串开始位置i时，比较当前子串长度与目前为止所有子串最大长度，取最大，同时将开始位置设为字符s[j]上次出现位置的下一位
        作者：TheoWu
        链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/cji-jian-jie-fa-by-theowu/
        来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     * @param s
     * @return
     */
    int lengthOfLongestSubstring(string s) {
        int res = 0, i = 0, j = 0;
        int cache[128];
        for (auto &c:cache) c = -1;
        while (j < s.size()) {
            if (cache[s[j]] >= i) {
                res = max(res, j - i);
                i = cache[s[j]] + 1;
            }
            cache[s[j]] = j;
            j++;
        }
        return max(res, j - i);
    }
};

TEST(lengthOfLongestSubstring, 1) {
    cout << endl;
    string input = "abcabcbb";
    auto answer = 3;
    auto output = Solution().lengthOfLongestSubstring(input);
    EXPECT_EQ(answer, output);
}