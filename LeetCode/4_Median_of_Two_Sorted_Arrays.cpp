//
// Created by arron on 19-5-3.
//

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
//    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
//        if (nums1.size() > nums2.size()) {
//            auto temp = nums1;
//            nums1 = nums2;
//            nums2 = temp;
//        }
//        int middleNums = (nums1.size() + nums2.size()) / 2;
//        int midRight = 0 ;
//        int midLeft = 0 ;
//        for (auto i = middleNums - nums1.size(); i <= middleNums; i++) {
//            if(nums2[i]>=nums1[middleNums-i]) {
//                //大中取小
//                if(middleNums - i + 1 <= nums1.size()-1){
//                    midLeft = min(nums1[i], nums2[middleNums - i + 1]);
//                } else {
//                    midLeft = nums1[i];
//                }
//                //小中取大
//                if(middleNums - i + 1 <= nums1.size()-1){
//                    midRight = max(nums1[i-1], nums2[middleNums - i + 1]);
//                } else {
//                    midRight = nums1[i];
//                }
//            }
//        }
//
//        if ((nums1.size() + nums2.size()) % 2 == 0) {
//            return (tempNums[middleNums] + tempNums[middleNums - 1]) / 2.0;
//        } else {
//            return double(tempNums[middleNums]);
//        }
//
//    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        auto begin1 = nums1.begin();
        auto end1 = nums1.end();
        auto begin2 = nums2.begin();
        auto end2 = nums2.end();
        vector<int> tempNums;
        int middleNums = (nums1.size() + nums2.size()) / 2;

        while (tempNums.size() <= middleNums) {
            while (begin1 != end1 && begin2 != end2 && tempNums.size() <= middleNums) {
                if (*begin1 <= *begin2) {
                    tempNums.push_back(*begin1);
                    begin1++;
                } else {
                    tempNums.push_back(*begin2);
                    begin2++;
                }
            }
            while (begin1 == end1 && tempNums.size() <= middleNums) {
                tempNums.push_back(*begin2);
                begin2++;
            }
            while (begin2 == end2 && tempNums.size() <= middleNums) {
                tempNums.push_back(*begin1);
                begin1++;
            }
        }
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            return (tempNums[middleNums] + tempNums[middleNums - 1]) / 2.0;
        } else {
            return double(tempNums[middleNums]);
        }
    }
};

TEST(findMedianSortedArrays, 1) {
    cout << endl;

    vector<int> nums1{1, 3};
    vector<int> nums2{2};
    double answer = 2.0;
    auto output = Solution().findMedianSortedArrays(nums1, nums2);
    EXPECT_EQ(answer, output);
}

TEST(findMedianSortedArrays, 2) {

    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};
    double answer = 2.5;
    auto output = Solution().findMedianSortedArrays(nums1, nums2);
    EXPECT_EQ(answer, output);
}