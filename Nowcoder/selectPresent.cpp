//
// Created by 侯正罡 on 2020/4/21.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    /**
     *
     * @param pre int整型vector<vector<>> N*M的矩阵，每个元素是这个地板砖上的礼物体积
     * @return int整型
     */
    int selectPresent(vector<vector<int> > &pre) {
        if (pre.empty()) return 0;
        int h = pre.size();
        int w = pre[0].size();

        vector<vector<int>> dp(h, vector<int>(w));
        //初始化第0行
        dp[0][0] = pre[0][0];
        for (int i = 1; i < w; i++)
            dp[0][i] = dp[0][i - 1] + pre[0][i];
        //初始化第0列
        for (int i = 1; i < h; i++)
            dp[i][0] = dp[i - 1][0] + pre[i][0];

        //计算内部值
        for (int i = 1; i < h; i++)
            for (int j = 1; j < w; j++)
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + pre[i][j];

        return dp.back().back();
    }
};

TEST(selectPresent, 1) {
    cout << endl;
    vector<vector<int> > input = {{1, 2, 3},
                                  {1, 2, 4}};
    int answer = 7;
    auto output = Solution().selectPresent(input);
    EXPECT_EQ(answer, output);
}