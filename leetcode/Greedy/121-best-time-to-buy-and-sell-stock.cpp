//
// Created by 侯正罡 on 2020/1/24.
//
/**
 * easy
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。


来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <iostream>
#include <list>
#include <vector>
#include <gtest/gtest.h>


using namespace std;


class Solution {
public:
    /**
     只要记录前面的最小价格，将这个最小价格作为买入价格，然后将当前的价格作为售出价格，查看当前收益是不是最大收益。
     */
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        int so_far_min = prices[0], profit = 0;
        for (auto i = prices.begin() + 1; i != prices.end(); ++i) {
            so_far_min = min(so_far_min, *i);
            profit = max(profit, *i - so_far_min);
        }
        return profit;
    }
};


TEST(maxProfit, 1) { /* NOLINT */
    cout << endl;
    vector<int> input{7, 1, 5, 3, 6, 4};
    int answer = 5;
    int output = Solution().maxProfit(input);
    EXPECT_EQ(answer, output);
}


TEST(maxProfit, 2) { /* NOLINT */
    cout << endl;
    vector<int> input{1, 2, 3, 4, 5};
    int answer = 4;
    int output = Solution().maxProfit(input);
    EXPECT_EQ(answer, output);
}