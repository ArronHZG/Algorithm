//
// Created by 侯正罡 on 2020/4/21.
//
#include <gtest/gtest.h>
#include "show.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    void sequenceSum(int n, int min_len) {
        for (int k = min_len; k <= 100; k++) {
            double a1 = 0.5 * (2.0 * n / k + 1 - k);
            int start = int(a1);
            if (start < 0) break;
            if (start == a1) {
                for (int i = 0; i < k-1; i++) {
                    cout << start + i << " ";
                }
                cout << start + k-1;
                return;
            }
        }
        cout << "No";
    };
};

TEST(sequenceSum, 1) {
    cout << endl;
    int n = 18;
    int k = 5;
    Solution().sequenceSum(n, k);
}

//int main() {
//    int a, b;
//    cin >> a >> b;
//    Solution().sequenceSum(a, b);
//    return 0;
//}
