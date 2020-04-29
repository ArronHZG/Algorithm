//
// Created by 侯正罡 on 2020/4/29.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int findWay(int coins, int N, int R, vector<vector<vector<int>>> ways) {
        int minDis = 1000000;
        deque<vector<int>> dq;
        for (const auto &way:ways[1]) {
            vector<int> node = {way[0], way[1], coins - way[2]};
            print<int>(node);
            if (node[2] >= 0) {
                dq.push_back(node);
                if (node[0] == N) {
                    return node[1];
                }
            }
        }
        while (!dq.empty()) {
            auto tmp = dq.front();
            dq.pop_front();
            for (const auto &way:ways[tmp[0]]) {
                vector<int> node = {way[0], way[1] + tmp[1], tmp[2] - way[2]};
                if (node[2] >= 0) {
                    print<int>(node);
                    dq.push_back(node);
                    if (node[0] == N) {
                        minDis = min(minDis, node[1]);
                    }
                }
            }
        }
        if (minDis == 1000000)
            return -1;
        return minDis;
    }
};

TEST(findWay, 1) {
    cout << endl;
    int coins = 5;
    int N = 6;
    int R = 7;
    vector<vector<vector<int>>> ways(N + 1);
    ways[1].push_back({2, 2, 4});
    ways[1].push_back({3, 4, 1});
    ways[2].push_back({4, 3, 3});
    ways[3].push_back({4, 2, 4});
    ways[3].push_back({5, 2, 0});
    ways[4].push_back({6, 2, 1});
    ways[5].push_back({4, 3, 2});
    auto answer = Solution().findWay(coins, N, R, ways);
    cout << answer << endl;
}