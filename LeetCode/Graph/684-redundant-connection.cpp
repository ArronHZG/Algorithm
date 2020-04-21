//
// Created by 侯正罡 on 2020/4/21.
//
#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "show.h"

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        //节点数小于等于边数
        int n = edges.size();
        // 维护一个vector, 表示每一个节点的父节点, 节点从1开始计数
        vector<int> upNode(n + 1);
        // 初始化父节点就是其本身, 表示目前存在n颗树
        for (int i = 0; i < n; i++)
            upNode[i] = i;
        for (int j = 0; j < n; j++) {
            // 找到边上两个节点所在树的根节点
            int set1 = find(edges[j][0], upNode);
            int set2 = find(edges[j][1], upNode);
            if (set1 == set2)  // 两颗树根节点相同，说明出现环，返回答案
                return edges[j];
            else    // 合并为一棵树,
                upNode[set1] = set2;
        }
        return {0, 0};
    }

    // 查找路径并返回代表节点，实际上就是给定当前节点，返回该节点所在集合的代表节点
    // 之前这里写的压缩路径，引起歧义，因为结果没更新到vector里，所以这里改成路径查找比较合适
    // 感谢各位老哥的提议
    int find(int num, vector<int> &dsu) {
        while (dsu[num] != num)
            num = dsu[num];
        return num;
    }
};


TEST(findRedundantConnection, 1) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input = {{1, 2},
                                 {1, 3},
                                 {2, 3}};
    vector<int> answer = {2,
                          3};
    auto output = Solution().findRedundantConnection(input);
    EXPECT_EQ(answer, output);
}