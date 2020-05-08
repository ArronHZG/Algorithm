//
// Created by 侯正罡 on 2020/4/22.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:

    /**
     *
     * state = 0 : =
     * state = 1 : >
     * state = 2 : <
     * @param num
     * @param deep
     * @param state
     * @param res
     * @param n
     * @param k
     * @return
     */
    void fun(int num, int deep, int state, int upNum, long long &res, int &n) {
//        cout << "num " << num << " deep " << deep << " state " << " upNum " << upNum << endl;
        if (deep == 1) {
            if (num > upNum && state == 1) {
                return;
            }
            cout << num << endl;
            res++;
            res %= long(pow(10, 9) + 7);
            return;
        }
        for (int i = 1; i < num; i++) {
            if (i > upNum && state == 1) {
                return;
            }
            if (i == upNum) state = 0;
            if (i > upNum) state = 1;
            if (i < upNum) state = 2;
            cout << i << " ";
            fun(num - i, deep - 1, state, i, res, n);
        }
    }

    long long splitNum(int n, int m) {
        long long res = 0;
        for (int i = 1; i < n; i++) {
            cout << endl;
            cout << i << " ";
            fun(n - i, m - 1, 0, i, res, n);
        }
        return res;
    }
};

//int main() {
//    int n, m;
//    while (cin >> n >> m) {
//        auto output = Solution().splitNum(n, m);
//        cout << output << endl;
//    }
//    return 0;
//}


TEST(splitNum, 1) {
    cout << endl;
    int n = 6;
    int m = 4;
    int answer = 5;
    auto output = Solution().splitNum(n, m);
    EXPECT_EQ(answer, output);
}