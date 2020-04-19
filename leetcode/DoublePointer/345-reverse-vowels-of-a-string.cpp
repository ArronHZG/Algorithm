//
// Created by 侯正罡 on 2020/1/18.
//
/*

 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/reverse-vowels-of-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <map>
#include <math.h>
#include<set>

using namespace std;

//
//class Solution {
//public:
//    string reverseVowels(string s) {
//        int low=0,high= s.size() - 1;
//        string tool="aoeiuAOEIU";
//        while(low < high)
//        {
//            while(tool.find(s[low]) == -1 && low < high)
//                ++low;
//            while(tool.find(s[high]) == -1 && low < high)
//                --high;
//            if(low < high)
//                swap(s[low++], s[high--]);
//        }
//        return s;
//    }
//};

class Solution {
public:
    string reverseVowels(string s) {
        set<char> tool {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int low=0;
        int high= s.size() - 1;
        while(low < high)
        {
            while(!(tool.find(s[low]) != tool.end()) && low < high)
                low++;
            while(!(tool.find(s[high]) != tool.end()) && low < high)
                high--;
            swap(s[low++], s[high--]);
        }
        return s;
    }
};


TEST(reverseVowels, 1) { /* NOLINT */
    std::cout << std::endl;
    string input = "lEetcode";
    string answer = "leotcedE";
    string output = Solution().reverseVowels(input);
    EXPECT_EQ(answer, output);
}