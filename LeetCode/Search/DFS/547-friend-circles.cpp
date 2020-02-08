//
// Created by 侯正罡 on 2020/2/8.
//

/**
班上有 N 名学生。其中有些人是朋友，有些则不是。
 他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。
 所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
 你必须输出所有学生中的已知的朋友圈总数。

示例 1:

输入:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
示例 2:

输入:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
注意：

N 在[1,200]的范围内。
对于所有学生，有M[i][i] = 1。
如果有M[i][j] = 1，则有M[j][i] = 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/friend-circles
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
    int N = 0;

    int findCircleNum(vector<vector<int>> &M) {
        int circleNum = 0;
        N = M.size();
        if (0 == N) return 0;
        for (int i = 0; i < N; i++) {
            if (M[i][i] == 1) {
                circleNum++;
                getThePersonCircle(M, i);
            }
        }
        return circleNum;
    }

    void getThePersonCircle(vector<vector<int>> &M, int person) {
        if (M[person][person] == 1) {
            M[person][person] = -1;
            for (int i = 0; i < N; i++) {
                if (M[person][i] == 1) {
                    getThePersonCircle(M, i);
                }
            }
        }
    }
};

TEST(findCircleNum, 1) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input{{1, 1, 0},
                              {1, 1, 0},
                              {0, 0, 1}};
    int answer = 2;
    auto output = Solution().findCircleNum(input);
    EXPECT_EQ(answer, output);
}

TEST(findCircleNum, 2) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input{{1, 0, 0, 1},
                              {0, 1, 1, 0},
                              {0, 1, 1, 1},
                              {1, 0, 1, 1}};
    int answer = 1;
    auto output = Solution().findCircleNum(input);
    EXPECT_EQ(answer, output);
}