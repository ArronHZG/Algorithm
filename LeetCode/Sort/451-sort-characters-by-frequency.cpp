//
// Created by 侯正罡 on 2020/1/22.
//
/*
 * 给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:

输入:
"tree"

输出:
"eert"

解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
示例 2:

输入:
"cccaaa"

输出:
"cccaaa"

解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
示例 3:

输入:
"Aabb"

输出:
"bbAa"

解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-characters-by-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        using E = pair<int, char>;
        unordered_map<char, int> count_map;
        priority_queue<E> min_heap;
        vector<E> res;
        string str;
        for (auto &c: s) ++count_map[c];
        for (auto &r : count_map) {
            min_heap.push(E(r.second, r.first));
        }
        while (!min_heap.empty()) {
            res.push_back(min_heap.top());
            min_heap.pop();
        }
        for (auto &r:res) {
//            for (int i = 0; i < r.first; ++i) {
//                str+=r.second;
//            }
            str.append(r.first, r.second);

        }
        return str;
    }
};

TEST(frequencySort, 1) { /* NOLINT */
    cout << endl;
    string input = "eert";
    string answer = "eetr";
    string output = Solution().frequencySort(input);
    EXPECT_EQ(answer, output);
}

TEST(frequencySort, 2) { /* NOLINT */
    cout << endl;
    string input = "cccaaa";
    string answer = "cccaaa";
    string output = Solution().frequencySort(input);
    EXPECT_EQ(answer, output);
}


TEST(frequencySort, 3) { /* NOLINT */
    cout << endl;
    string input = "Aabb";
    string answer = "bbaA";
    string output = Solution().frequencySort(input);
    EXPECT_EQ(answer, output);
}
