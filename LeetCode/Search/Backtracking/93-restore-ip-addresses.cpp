//
// Created by 侯正罡 on 2020/3/31.
//

/**
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


 对IP合法性要求：

每段位数在1-3之间（在取前面段的时候要判断剩余位数是否能满足后面的最大/最小位数要求),最大不能超过255；
一共4段，代表树最多有4层；
当每段长度>1时，第一位不能是'0'；

作者：mecury
链接：https://leetcode-cn.com/problems/restore-ip-addresses/solution/c-hui-su-bao-han-ipdi-zhi-he-fa-xing-pan-duan-tiao/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
#include <cstring>

using namespace std;

class Solution {
public:
    void doIp(vector<string> &res, const string &s, vector<string> &ips, int pos, int depth) {
        if (depth == 4) {
            if (pos == s.size()) {
                string res_str = ips[0] + "." + ips[1] + "." + ips[2] + "." + ips[3];
                res.push_back(res_str);
            }
        } else {
            for (int i = 1; i <= 3; i++) {
                if (pos + i > s.size()) {
                    return;
                }
                auto b = s.substr(pos, i);
                if (b[0] == '0' and b.size() > 1) {
                    return;
                }
                auto d = stoi(b);
                if (d <= 255) {
                    ips.push_back(b);
                    for (const auto &item:ips) {
                        cout << item << " ";
                    }
                    cout << endl;
                    cout << " d " << d << " depth " << depth << " pos " << pos + i << endl;
                    doIp(res, s, ips, pos + i, depth + 1);
                    ips.pop_back();
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> ips;
        doIp(res, s, ips, 0, 0);
        return res;
    }
};


TEST(restoreIpAddresses, 1) { /* NOLINT */
    cout << endl;
    string input = "25525511135";
    vector<string> answer = {"255.255.11.135", "255.255.111.35"};
    auto output = Solution().restoreIpAddresses(input);
    EXPECT_EQ(answer, output);
}

TEST(restoreIpAddresses, 2) { /* NOLINT */
    cout << endl;
    string input = "0000";
    vector<string> answer = {"0.0.0.0"};
    auto output = Solution().restoreIpAddresses(input);
    EXPECT_EQ(answer, output);
}

TEST(restoreIpAddresses, 3) { /* NOLINT */
    cout << endl;
    string input = "1111";
    vector<string> answer = {"1.1.1.1"};
    auto output = Solution().restoreIpAddresses(input);
    EXPECT_EQ(answer, output);
}

TEST(restoreIpAddresses, 4) { /* NOLINT */
    cout << endl;
    string input = "010010";
    vector<string> answer = {"0.10.0.10", "0.100.1.0"};
    auto output = Solution().restoreIpAddresses(input);
    EXPECT_EQ(answer, output);
}

TEST(restoreIpAddresses, 5) { /* NOLINT */
    cout << endl;
    string input = "279245587303";
    vector<string> answer = {};
    auto output = Solution().restoreIpAddresses(input);
    EXPECT_EQ(answer, output);
}