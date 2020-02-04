//
// Created by 侯正罡 on 2020/2/4.
//

/**
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/different-ways-to-add-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

//class Solution {
//private:
//    //备忘录，避免重复计算区间值
//    map<pair<int, int>, vector<int>> m;
//public:
//    vector<int> diffWaysToCompute(string input) {
//        // 区间设置为[left,right)
//        return ways(input, 0, input.size());
//    }
//
//    vector<int> ways(const string &input, int left, int right) {
//        //重复区间，返回避免重复计算
//        if (m.find(make_pair(left, right)) != m.end()) {
//            cout << "left:" << left << "  right:" << right << "  result:";
//            for (auto i : m[make_pair(left, right)]) {
//                cout << i << "  ";
//            }
//            cout << endl;
//            return m[make_pair(left, right)];
//        }
//
//        vector<int> res;
//
//        for (int i = left; i < right; ++i) {
//            if (input[i] == '-' || input[i] == '+' || input[i] == '*') {
//                //划分区间
//                vector<int> l = ways(input, left, i);
//                vector<int> r = ways(input, i + 1, right);
//                //每两个数字进行计算，最后计算成一个数字
//                for (auto vl:l)
//                    for (auto vr:r)
//                        res.push_back(ops(input[i], vl, vr));
//            }
//        }
//        //纯数字：表示区间内只有一个数字了
//        if (res.empty())
//            res.push_back(stoi(input.substr(left, right - left)));
//        m[make_pair(left, right)] = res;
//        cout << "left:" << left << "  right:" << right << "  result:";
//        for (auto i : res) {
//            cout << i << "  ";
//        }
//        cout << endl;
//        return res;
//    }
//
//    int ops(char op, int l, int r) {
//        switch (op) {
//            case '+':
//                return l + r;
//            case '-':
//                return l - r;
//            case '*':
//                return l * r;
//            default:
//                return 0;
//        }
//    }
//};
//


class Solution {
public:
    //存储区间
    using Section = pair<int, int>;
    //备忘录，避免重复计算区间值
    map<Section, vector<int>> memo;

    /*
     * 按照 每一个符号 将字符串划分为左右两个区间
     * 递归划分
     * 区间定义为左闭右开 [left,right)
     * 每一个区间存储这个区间内可能存在的结果, 保存在字典中
     */
    vector<int> diffWaysToCompute(const string &input) {
        return ways(input, Section(0, input.size()));
    }

    vector<int> ways(const string &input, Section sec) {
        //如果存在该区间的结果之间返回
        if (memo.find(sec) != memo.end()) {
            return memo[sec];
        }
        vector<int> result;
        //按照 每一个符号 将字符串划分为左右两个区间
        for (auto i = sec.first; i < sec.second; ++i) {
            //判断为字符
            if (input[i] == '-' || input[i] == '+' || input[i] == '*') {
                auto left_values = ways(input, Section(sec.first, i));
                auto right_values = ways(input, Section(i + 1, sec.second));
                for(auto lv :left_values)
                    for(auto rv: right_values)
                        result.push_back(caculate(input[i],lv,rv));
            }
        }
        if (result.empty()) {
            result.push_back(stoi(input.substr(sec.first, sec.second-sec.first)));
        }
        return result;
    }

    int caculate(char op, int l, int r) {
        switch (op) {
            case '+' :
                return l+r;
            case '-' :
                return l-r;
            case '*' :
                return l*r;
            default:
                return 0;
        }
    }
};

TEST(diffWaysToCompute, 1) { /* NOLINT */
    cout << endl;
    string input = "2*3-4*5";
    vector<int> answer{-34, -10, -14, -10, 10};
    auto output = Solution().diffWaysToCompute(input);
    EXPECT_EQ(answer, output);
}