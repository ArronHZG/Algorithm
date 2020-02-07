//
// Created by 侯正罡 on 2020/2/6.
//
/**
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    using Node = pair<int, int>;
    map<int, vector<int>> sqrtMap;

    /**
     *
     * 判断队列第一个该数是否为完全平方数,如果是结束,如果不是,得到小于数的所有完全平方数加入队列
     * @param n
     * @return
     */
    int numSquares(int n) {

        queue<Node> channel;

        channel.emplace(n, 1);
        while (!channel.empty()) {
            auto node = channel.front();
            channel.pop();
            if (isSquareNumber(node.first)) {
                return node.second;
            } else {
                auto sqrtList = getSqrtList(node.first);
                for (auto sq: sqrtList) {
                    channel.emplace(node.first - sq, node.second + 1);
                }
            }
        }
        return 0;
    }

    bool isSquareNumber(int n) {
        int sq = floor(sqrt(n));
        return sq * sq == n;
    };

    vector<int> getSqrtList(int n) {
        if (sqrtMap.find(n) != sqrtMap.end()) {
            return sqrtMap[n];
        } else {
            int sq = floor(sqrt(n));
            vector<int> sqList;
            for (int i = sq; i >= 1; --i) {
                sqList.push_back(i * i);
            }
            sqrtMap.insert(pair<int, vector<int>>(n,sqList));
            return sqList;
        }
    }
};

TEST(numSquares, 1) { /* NOLINT */
    cout << endl;
    int input = 7168;
    int answer = 4;
    auto output = Solution().numSquares(input);
    EXPECT_EQ(answer, output);
}
