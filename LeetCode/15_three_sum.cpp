//
// Created by arron on 19-4-26.
//
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <map>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        stack<vector<int>> tempOutput;
        for (auto pa = nums.begin(); pa != nums.end(); pa++) {
            set<int> b_s, c_s;
            for (auto pc = pa + 1; pc != nums.end(); pc++) {
                int b = -(*pa + *pc);
                if(c_s.find(b)!=c_s.end()&&b_s.find(b)==b_s.end()) {
                    tempOutput.push(vector<int>{*pa, b, *pc});
                    b_s.insert(b);
                }
                c_s.insert(*pc);
            }
            while(pa != nums.end()&& *pa ==*(pa+1)) {
                pa++;
            }
            while (!tempOutput.empty()) {
                output.push_back(tempOutput.top());
                tempOutput.pop();
            }
        }
        return output;
    }

    vector<vector<int>> threeSum2(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<=2) return res;
        make_heap(nums.begin(), nums.end());
        sort_heap(nums.begin(), nums.end());
        for (int i=0;i<nums.size()-2;i++)
        {
            if (i==0||nums[i]!=nums[i-1])
            {
                int sum=-nums[i];
                int l=i+1,r=nums.size()-1;
                while (l<r)
                {
                    if (nums[l]+nums[r]==sum)
                    {
                        res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                        while (l<r&&nums[l]==nums[l+1])l++;
                        while (l<r&&nums[r]==nums[r-1])r--;
                        l++,r--;
                    }
                    else if (nums[l]+nums[r]<sum)
                        l++;
                    else r--;
                }
            }
        }
        return res;
    }
};



TEST(threeSum, 1) {
    std::cout << std::endl;
    vector<int> input = {3, 0, -2, -1, 1, 2};
    vector<vector<int>> answer = {{-2, -1, 3},
                                  {-2, 0,  2},
                                  {-1, 0,  1}};
    vector<vector<int>> output = Solution().threeSum(input);
    EXPECT_EQ(answer, output);
}

TEST(threeSum, 2) {
    cout << endl;
    vector<int> input = {-6, 3, 3, 3, 3, 3};
    vector<vector<int>> answer = {{-6, 3, 3}};
    vector<vector<int>> output = Solution().threeSum(input);
    EXPECT_EQ(answer, output);
}
