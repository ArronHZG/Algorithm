//
// Created by 侯正罡 on 2020/4/29.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int maxArea = 0;
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix.back().size();
        for (int i = 0; i < m; i++) {
            vector<int> heights(n);
            for (int j = 0; j < n; j++) {
                for (int k = i; k >= 0; k--) {
                    if (matrix[k][j] == '1') heights[j]++;
                    else break;
                }
            }
            maxArea = max(maxArea, this->largestRectangleArea(heights));
        }
        return maxArea;
    }

private:
    int largestRectangleArea(vector<int> &heights) {
        int maxArea = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int cur = st.top();
                st.pop();
                int left = st.top() + 1;
                int right = i - 1;
                maxArea = max(maxArea, (right - left + 1) * heights[cur]);
            }
            st.push(i);
        }
        return maxArea;
    }

};

TEST(maximalRectangle, 1) {
    cout << endl;
    vector<vector<char>> input = {{'1', '0', '1', '0', '0'},
                                  {'1', '0', '1', '1', '1'},
                                  {'1', '1', '1', '1', '1'},
                                  {'1', '0', '0', '1', '0'}};
    int answer = 6;
    auto output = Solution().maximalRectangle(input);
    EXPECT_EQ(answer, output);
}