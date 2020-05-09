//
// Created by 侯正罡 on 2020/5/9.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    /**
     * 需要定义好 循环不变量
     * 在整个循环过程中保持不变的性质，它必须在以下3种情况下均保持不变，且该性质在循环终止后能证明算法的正确性。
            初始化（循环的定义）
            迭代（第 n 次迭代后，第 n+1 次迭代前）
            结束（循环终止即循环条件判断为 false 时）
     * @param nums
     * @return
     */
//    int removeDuplicatesII(vector<int> &nums) {
//        if (nums.empty()) return 0;
//        int i = 0;          // 相同数的首位置
//        int j = 0;          // 遍历指针
//        int count = 0;      // 相同数的数量
//        while (j < nums.size()) {
//            while (nums[i] == nums[j]) {
//                j++;
//                count++;
//            }
//            i = i + min(count, 2);
//            count = 0;
//            if (j == nums.size()) break;
//            for (int k = 0; k < j - i; k++) {
//                nums[i + k] = nums[j + k];
//            }
//        }
//        return i;
//    }

    int removeDuplicatesII(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int i = 1;
        for(int j = 2; j < n; j++){
            if(nums[j] != nums[i - 1]){
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

TEST(removeDuplicatesII, 1) {
    cout << endl;
    auto start_time = clock();
    vector<int> input = {0, 0, 0, 1, 1, 1, 1, 2, 3, 3, 3};
    int answer = 7;
    auto output = Solution().removeDuplicatesII(input);
    EXPECT_EQ(answer, output);
    auto end_time = clock();
    cout << "time cost:" << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
}

TEST(removeDuplicatesII, 2) {
    cout << endl;
    auto start_time = clock();
    vector<int> input = {1,2,2,3};
    int answer = 3;
    auto output = Solution().removeDuplicatesII(input);
    EXPECT_EQ(answer, output);
    auto end_time = clock();
    cout << "time cost:" << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
}