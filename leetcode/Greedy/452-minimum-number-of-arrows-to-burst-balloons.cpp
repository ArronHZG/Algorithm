//
// Created by 侯正罡 on 2020/1/24.
//
/**
 * 在二维空间中有许多球形的气球。
 * 对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
 * 由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了
 * 。开始坐标总是小于结束坐标。平面内最多存在104个气球。

一支弓箭可以沿着x轴从不同点完全垂直地射出。
 在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。
 可以射出的弓箭的数量没有限制。
 弓箭一旦被射出之后，可以无限地前进。
 我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

Example:

输入:
[[10,16], [2,8], [1,6], [7,12]]

输出:
2

解释:
对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <iostream>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    /**
     * 按照结尾排序
     * 第一箭射第一个气球结尾,顺便射中重叠的气球
     * 第二箭重复上次过程,知道所有气球被射爆
     * 注意区间为闭区间
     * @param points
     * @return
     */
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(),
             [](const vector<int> &o1, const vector<int> &o2) {
                 return (o1[1] < o2[1]);
             });
        int left = points[0][1];
        int arrows = 1;
        for (int i = 1; i != points.size(); ++i) {
            if (points[i][0] > left) {
                ++arrows;
                left = points[i][1];
            }
        }
        return arrows;
    }
};

TEST(findMinArrowShots, 4) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input(4, vector<int>(2));
    input[0] = {1, 2};
    input[1] = {2, 3};
    input[2] = {3, 4};
    input[3] = {1, 3};
    int answer = 2;
    int output = Solution().findMinArrowShots(input);
    EXPECT_EQ(answer, output);
}


TEST(findMinArrowShots, 1) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input{{9, 12},
                              {1, 10},
                              {4, 11},
                              {8, 12},
                              {3, 9},
                              {6, 9},
                              {6, 7}};
    int answer = 2;
    int output = Solution().findMinArrowShots(input);
    EXPECT_EQ(answer, output);
}

