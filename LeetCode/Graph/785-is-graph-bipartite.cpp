//
// Created by 侯正罡 on 2020/4/20.
//
#include <gtest/gtest.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool dfs(const vector<vector<int>> &graph, vector<int> &cols, int i, int col) {
        cols[i] = col;
        for (auto j : graph[i]) {
            if (cols[j] == cols[i]) return false;
            if (cols[j] == 0 && !dfs(graph, cols, j, -col)) return false;
        }
        return true;
    }

    /**
     * cols: 0未着色, -1 A集合, 1 B集合
     * @param graph
     * @return
     */
    bool isBipartite(vector<vector<int>> &graph) {
        int N = graph.size();
        vector<int> cols(N, 0);
        for (int i = 0; i < N; ++i) {
            if (cols[i] == 0 && !dfs(graph, cols, i, 1)) {
                return false;
            }
        }
        return true;
    }
};

TEST(isBipartite, 1) { /* NOLINT */
    cout << endl;
    vector<vector<int>> graph = {{1, 3},
                                 {0, 2},
                                 {1, 3},
                                 {0, 2}};
    auto answer = true;
    auto output = Solution().isBipartite(graph);
    EXPECT_EQ(answer, output);
}

