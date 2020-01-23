//
// Created by 侯正罡 on 2020/1/23.
//

/**
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-overlapping-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;


bool cmp(vector<int> a, vector<int> b) {
    if (a[1] < b[1]) {
        return true;
    } else if (a[1] > b[1]) {
        return false;
    } else {
        return a[0] < b[0];
    }
}

/**
 * 方案1 动态规划 O(n^2)
 * 按照左边界排序
 * 维护一个dp数组,长度为区间总数,记录当前可存在的区间数
 * 例如 [1,2] [2,3] [3,4] [1,4] [2,5] [4,6]
 *   dp[1,2,3,3,3,4]
 * dp[i+1]的值取决于已经存在区间数,
 * 如果区间 j 加上当前i+1区间不冲突,state_1 = 不冲突的区间 j 所存储的dp[j] + 1, j需要寻找
 * 如果区间 i 加上当前i+1区间冲突,则state_2 = dp [i]
 * dp[i+1] = max(state_1,state_2)
 *
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        for (auto &p:intervals) {
            cout << p[0] << "  " << p[1] << endl;
        }
        vector<int> dp(intervals.size());
        dp[0] = 1;
        for (auto i = 1; i != intervals.size(); ++i) {
            int state_1 = 0, state_2 = dp[i - 1];
            for (auto j = i - 1; j >= 0; --j) {
                if (intervals[j][1] <= intervals[i][0]) {
                    state_1 = dp[j] + 1;
                    break;
                }
            }
            dp[i] = max(state_1, state_2);
        }
        for (auto &p:dp) cout << p << endl;
        return int(intervals.size()) - dp[dp.size() - 1];
    }
};


/**
 * 方案2 贪心 O(nlog(n))
 * 按照左边界排序
 * 例如 [1,2] [2,3] [3,4] [1,4] [2,5] [4,6]
 * 如果 i+1 与 i 重叠,跳过
 *
 */
class Solution_2 {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), cmp);
        for (auto &p:intervals) {
            cout << p[0] << "  " << p[1] << endl;
        }
        int count = 0;
        int j = 0;//指向可以存在的最后一个区间
        for (auto i = 1; i != intervals.size(); ++i)
            if (intervals[j][1] <= intervals[i][0]) j = i;
            else ++count;
        return count;
    }
};

/**
 * 贪心优化
 */
class Solution_3 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][1];
        int res = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (left<=intervals[i][0]) {
                left = intervals[i][1];
            } else {
                left = min(left, intervals[i][1]);
                ++res;
            }
        }
        return res;
    }
};


TEST(eraseOverlapIntervals, 2) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input(5, vector<int>(2));
    input[0] = {0, 2};
    input[1] = {1, 3};
    input[2] = {2, 4};
    input[3] = {3, 5};
    input[4] = {4, 6};
    int answer = 2;
    int output = Solution_3().eraseOverlapIntervals(input);
    EXPECT_EQ(answer, output);
}

TEST(eraseOverlapIntervals, 3) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input(4, vector<int>(2));
    input[0] = {1, 2};
    input[1] = {2, 3};
    input[2] = {3, 4};
    input[3] = {1, 3};
    int answer = 1;
    int output = Solution_2().eraseOverlapIntervals(input);
    EXPECT_EQ(answer, output);
}

TEST(eraseOverlapIntervals, 4) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input;
    int answer = 0;
    int output = Solution_2().eraseOverlapIntervals(input);
    EXPECT_EQ(answer, output);
}

