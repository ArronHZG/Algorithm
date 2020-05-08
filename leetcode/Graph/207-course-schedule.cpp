//
// Created by 侯正罡 on 2020/4/20.
//

/**
 * 方法一：入度表（广度优先遍历）
算法流程：
统计课程安排图中每个节点的入度，生成 入度表 indegrees。
借助一个队列 queue，将所有入度为 00 的节点入队。
当 queue 非空时，依次将队首节点出队，在课程安排图中删除此节点 pre：
并不是真正从邻接表中删除此节点 pre，而是将此节点对应所有邻接节点 cur 的入度 -1−1，即 indegrees[cur] -= 1。
当入度 -1−1后邻接节点 cur 的入度为 00，说明 cur 所有的前驱节点已经被 “删除”，此时将 cur 入队。
在每次 pre 出队时，执行 numCourses--；
若整个课程安排图是有向无环图（即可以安排），则所有节点一定都入队并出队过，即完成拓扑排序。换个角度说，若课程安排图中存在环，一定有节点的入度始终不为 00。
因此，拓扑排序出队次数等于课程个数，返回 numCourses == 0 判断课程是否可以成功安排。
复杂度分析：
时间复杂度 O(N + M)O(N+M)： 遍历一个图需要访问所有节点和所有临边，NN 和 MM 分别为节点数量和临边数量；
空间复杂度 O(N + M)O(N+M)： 为建立邻接表所需额外空间，adjacency 长度为 NN ，并存储 MM 条临边的数据。

作者：jyd
链接：https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/
来源：力扣（leetcode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "show.h"

using namespace std;

class Solution {
public:
    /**
     *
     *
     * @param numCourses
     * @param prerequisites
     * @return
     */
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adjacency(numCourses, vector<int>());
        //Get the indegree and adjacency of every course.
        for (auto pre:prerequisites) {
            indegree[pre[0]] += pre.size() - 1;
            for (int i = 1; i < pre.size(); i++) {
                adjacency[pre[i]].push_back(pre[0]);
            }
        }
        print<int>(indegree);
        cout << endl;
        print<int>(adjacency);
        cout << endl;

        queue<int> q;
        int count = 0;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            count++;
            for (auto j: adjacency[i]) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    q.push(j);
                } else if (indegree[j] < 0) {
                    return false;
                }
            }
            print<int>(indegree);
        }
        return count == numCourses;
    }
};

TEST(canFinish, 1) { /* NOLINT */
    cout << endl;
    int num = 6;
    vector<vector<int>> input = {{2, 1},
                                 {3, 2},
                                 {4, 1, 2},
                                 {5, 4, 3}};
    auto answer = true;
    auto output = Solution().canFinish(num, input);
    EXPECT_EQ(answer, output);
}


TEST(canFinish, 2) { /* NOLINT */
    cout << endl;
    int num = 2;
    vector<vector<int>> input = {{0, 1},
                                 {1, 0}};
    auto answer = false;
    auto output = Solution().canFinish(num, input);
    EXPECT_EQ(answer, output);
}


TEST(canFinish, 3) { /* NOLINT */
    cout << endl;
    int num = 3;
    vector<vector<int>> input = {{2, 1},
                                 {2, 0}};
    auto answer = true;
    auto output = Solution().canFinish(num, input);
    EXPECT_EQ(answer, output);
}

TEST(canFinish, 4) { /* NOLINT */
    cout << endl;
    int num = 3;
    vector<vector<int>> input = {{1, 0},
                                 {1, 2},
                                 {0, 1}};
    auto answer = false;
    auto output = Solution().canFinish(num, input);
    EXPECT_EQ(answer, output);
}