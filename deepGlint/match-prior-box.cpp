//
// Created by 侯正罡 on 2020/4/21.
//

/**
我们用左上角坐标(x,y)和宽高(w,h)来表达一个矩形(x,y,w,h)。

假设在一个幕布上有一组等间距，密集排列的相同大小的先验矩形框，幕布最左上角的矩形框是(0, 0, w, h)。这组先验矩形框的横纵间距分别是s, t，即第(i,j)个框的坐标是 (s*i, t*j, w, h)。假设幕布的宽度是P, 高度是Q，我们只考虑不超出幕布的先验框，即满足s*i+w<=P且t*j+h<=Q。

我们定义两个矩形相交当且仅当它们交集的面积大于0(只有边相交的不算)。

给定k个目标矩形框，请你求出与这些目标框相交（与任何一个目标框相交都可以)的先验框的总数量（不计重复，每个先验矩形框只计算一次）。注意目标矩形框有可能会大于幕布的范围。

[题目背景:常用目标检测算法中Anchor Box与待检测目标框的对应关系计算]

Input Format

第一行有7个正整数，前四个数规定了先验框的宽度, 高度和横纵间距：w, h, s, t，第五个数是目标框的数量k，第六个数是幕布的宽度P，第七个数是幕布的高度Q。

接下来有k行，每一个行有四个整数，表示一个目标框的X, Y, W, H。

Constraints

1<=P, Q<=1000

1<=w, h, s, t <= 100

0<= X <= P-1

0<= Y <= Q-1

1<=W,H<=500

对于40%的测试样例

k=1

对于80%的测试样例

1 <= k <= 1000

对于所有100%的测试样例

1 <= k <= 100000

Output Format

输出一个整数，表示与所给的一组目标框相交的先验框的总数量。

Sample Input 0

1 1 1 1 1 13 10
9 4 1 1
Sample Output 0

1
Sample Input 1

2 3 3 2 1 11 15
4 7 17 13
Sample Output 1

12
 */

#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "show.h"

using namespace std;


class Solution {
public:
    int w, h, s, t, k, P, Q;
    vector<vector<int>> anchors;

    Solution(int w, int h, int s, int t, int k, int P, int Q) :
            w(w),
            h(h),
            s(s),
            t(t),
            k(k),
            P(P),
            Q(Q) {
        for (int i = 0; (i * s) + w <= P; i++) {
            for (int j = 0; (j * t) + h <= Q; j++) {
                vector<int> temp = {i * s, j * t, 0};
                anchors.push_back(temp);
            }
        }
    };

    bool intersection(vector<int> anchor, vector<int> box) {
        vector<vector<int>> points;
        points.push_back({anchor[0], anchor[1]});
        points.push_back({anchor[0], anchor[1] + h - 1});
        points.push_back({anchor[0] + w - 1, anchor[1]});
        points.push_back({anchor[0] + w - 1, anchor[1] + h - 1});
        for (auto point:points) {
            if (box[0] <= point[0] && box[0] + box[2] - 1 >= point[0]
                && box[1] <= point[1] && box[1] + box[3] - 1 >= point[1]) {
                return true;
            }
        }
        return false;
    }

    int match(vector<vector<int>> &boxs) {
        int intersection_num = 0;
        for (auto anchor: anchors) {
            for (const auto &box: boxs) {
                if (anchor[2] == 0 && intersection(anchor, box)) {
                    anchor[2] = 1;
                    intersection_num++;
                }
            }
        }
        return intersection_num;
    }
};

TEST(match, 1) { /* NOLINT */
    cout << endl;
    //    第一行有7个正整数，前四个数规定了先验框的宽度, 高度和横纵间距：w, h, s, t，第五个数是目标框的数量k，第六个数是幕布的宽度P，第七个数是幕布的高度Q。
    int w = 2, h = 3, s = 3, t = 2, k = 2, P = 11, Q = 15;
    vector<vector<int>> boxs = {{4, 7, 17, 13},
                                {8, 2, 2,  7}};

    int answer = 15;
    auto output = Solution(w, h, s, t, k, P, Q).match(boxs);
    EXPECT_EQ(answer, output);
}


//int main() {
//    int w, h, s, t, k, P, Q;
//    cin >> w >> h >> s >> t >> k >> P >> Q;
//    vector<vector<int>> boxs;
//    while (k--) {
//        int x, y, bw, bh;
//        cin >> x >> y >> bw >> bh;
//        boxs.push_back({x, y, bw, bh});
//    }
//    int output = Solution(w, h, s, t, k, P, Q).match(boxs);
//    cout << output << endl;
//    return 0;
//}