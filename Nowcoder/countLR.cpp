//
// Created by 侯正罡 on 2020/4/21.
//

#include <gtest/gtest.h>
#include "show.h"
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 计算有多少对符合条件的数对
     * @param a int整型vector 数组a
     * @param b int整型vector 数组b
     * @return int整型
     */
    int countLR(vector<int> &a, vector<int> &b) {
        // write code here
        int n = a.size();
        int res = 0;
        vector<int> sum_a(n + 1);
        for (int i = 1; i <= n; i++) {
            sum_a[i] = a[i - 1] + sum_a[i - 1];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (sum_a[j + 1] - sum_a[i] == b[i] + b[j]) {
                    res++;
                }
            }
        }
        return res;
    }
};

TEST(countLR, 1) {
    cout << endl;
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {2, 1, 4, 5};
    auto output = Solution().countLR(a, b);
    cout << output << endl;
}