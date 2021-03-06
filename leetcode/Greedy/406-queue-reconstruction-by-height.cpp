//
// Created by 侯正罡 on 2020/1/24.
//
/**
 * 假设有打乱顺序的一群人站成一个队列。
 * 每个人由一个整数对(h, k)表示，
 * 其中h是这个人的身高，
 * k是排在这个人前面且身高大于或等于h的人数。
 * 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}}

输出:
{{5,0}, {7,0}, {5,2}, {6,1}, {4,4}, {7,1}}


来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */



#include <iostream>
#include <list>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        if (people.empty()) return people;
        sort(people.begin(), people.end(),
             [](const vector<int> &o1, const vector<int> &o2) {
                 return o1[0] == o2[0] ? o1[1] > o2[1] : o1[0] < o2[0];
             }
        );
        list<vector<int>> output;
        auto list_begin = begin(output);
        for (auto p = end(people) - 1; p != begin(people)-1; --p) {
            auto temp = list_begin;
            for (int i = 0; i <= (*p)[1]; ++i) ++temp;
            output.insert(temp, *p);
        }
        for (auto &p:people){
            p=output.front();
            output.pop_front();
        }
        return people;
    }
};


TEST(reconstructQueue, 3) { /* NOLINT */
    cout << endl;
    vector<vector<int>> input{{7, 0},
                              {4, 4},
                              {7, 1},
                              {5, 0},
                              {6, 1},
                              {5, 2}};
    vector<vector<int>> answer{{5, 0},
                               {7, 0},
                               {5, 2},
                               {6, 1},
                               {4, 4},
                               {7, 1}};
    vector<vector<int>> output = Solution().reconstructQueue(input);
    EXPECT_EQ(answer, output);
}
