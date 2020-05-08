//
// Created by 侯正罡 on 2020/4/29.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int maxArea = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        print<int>(heights);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int cur = st.top();
                st.pop();
                int left = st.top() + 1;
                int right = i - 1;
//                cout<<"left "<<left<<" right "<<right<<endl;
                maxArea = max(maxArea, (right - left + 1) * heights[cur]);
//                cout<<" h "<< heights[cur]<<" l "<<right - left + 1<<" area " << (right - left + 1) * heights[cur]<<endl;
            }
            st.push(i);
        }
        return maxArea;
    }
};

TEST(largestRectangleArea, 1) {
    cout << endl;
    vector<int> input = {2,1,5,6,2,3};
    int answer = 10;
    auto output = Solution().largestRectangleArea(input);
    EXPECT_EQ(answer, output);
}