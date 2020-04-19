//
// Created by 侯正罡 on 2020/2/2.
//

/**
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，
同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度
的列表。

示例 1:

输入: S = "ababcbacadefegdehijhklij"
输出: [9,7,8]
解释:
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
注意:

S的长度在[1, 500]之间。
S只包含小写字母'a'到'z'。

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    /**
     * 用小写字母维护一个vector记录每个字母最后出现的位置
     *
     *
     * 思路
     * 策略就是不断地选择从最左边起最小的区间。可以从第一个字母开始分析，
     * 假设第一个字母是 'a'，那么第一个区间一定包含最后一次出现的 'a'。
     * 但第一个出现的 'a' 和最后一个出现的 'a' 之间可能还有其他字母，这些字母会让区间变大。
     * 举个例子，在 "abccaddbeffe" 字符串中，第一个最小的区间是 "abccaddb"。
     * 通过以上的分析，我们可以得出一个算法：对于遇到的每一个字母，去找这个字母最后一次出现的位置，用来更新当前的最小区间。
     * 算法
     * 定义数组 last[char] 来表示字符 char 最后一次出现的下标。
     * 定义 anchor 和 end 来表示当前区间的首尾。
     * 如果遇到的字符最后一次出现的位置下标大于 end，
     * 就让 end=last[c] 来拓展当前的区间。
     * 当遍历到了当前区间的末尾时(即 anchor==end )，
     * 把当前区间加入答案，同时将 anchor 设为 i+1 去找下一个区间。
     *
     * @param S
     * @return
     */
    vector<int> partitionLabels(string S) {
        int N = S.size();
        vector<int> last(26, -1);
        for (int i = 0; i < N; ++i) {
            last[indexOfChar(S[i])] = i;
        }
        vector<int> res;
        int anchor = 0;
        while (anchor < N) {
            int end = last[indexOfChar(S[anchor])];
            for (int j = anchor + 1; j < end; ++j) {
                end = max(end, last[indexOfChar(S[j])]);
            }
            res.push_back(end - anchor + 1);
            anchor = end + 1;
        }
        return res;
    }

    int indexOfChar(char c) {
        return c - 'a';
    }
};

TEST(partitionLabels, 2) { /* NOLINT */
    cout << endl;
    string input = "ababcbacadefegdehijhklij";
    vector<int> answer{9,7,8};
    auto output = Solution().partitionLabels(input);
    EXPECT_EQ(answer, output);
}