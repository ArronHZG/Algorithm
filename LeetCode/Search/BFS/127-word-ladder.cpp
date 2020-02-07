//
// Created by 侯正罡 on 2020/2/6.
//

/**
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <gtest/gtest.h>

using namespace std;

//
//class Solution {
//public:
//
//    /**
//       * 整个问题抽象为无向图
//       * 每个单词为一个节点,每个节点都有对应的领接单词(AdjacencyWord),领接单词就是变化一次后的单词list
//       * 然后利用BFS搜索图,直到构建出最短路径
//       * 注意处理图中,环的存在,需要构建一个visited表
//       * @param beginWord
//       * @param endWord
//       * @param wordList
//       * @return
//       */
//    int ladderLength(const string &beginWord, string endWord, vector<string> &wordList) {
//        unordered_set<string> wordDict{wordList.begin(), wordList.end()};
//        unordered_set<string> visited;
//        visited.insert(beginWord);
//        queue<pair<string, int>> que;
//        que.emplace(beginWord, 1);
//        while (!que.empty()) {
//            auto current = que.front();
//            que.pop();
//            for (int i = 0; i < current.first.size(); i++) {
//                for (auto ch = 'a'; ch <= 'z'; ch++) {
//                    auto temp = current.first;
//                    temp[i] = ch;
//                    //判断是否为结果
//                    //判断是否在Dict中
//                    //判断是否访问过
//                    if (temp == endWord)
//                        return current.second + 1;
//                    else if (wordDict.find(temp) != wordDict.end()) {
//                        if (visited.find(temp) == visited.end()) {
//                            cout << current.first << " ->  " << temp << endl;
//                            visited.insert(temp);
//                            que.push(pair<string, int>(temp, current.second + 1));
//                        }
//                    }
//                }
//            }
//        }
//        return 0;
//    }
//};

class Solution {
public:

    /**
       * 整个问题抽象为无向图
       * 每个单词为一个节点,每个节点都有对应的领接单词(AdjacencyWord),领接单词就是变化一次后的单词list
       * 然后利用BFS搜索图,直到构建出最短路径
       * 注意处理图中,环的存在,需要构建一个visited表
       * @param beginWord
       * @param endWord
       * @param wordList
       * @return
       */
    int ladderLength(const string &beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> wordDict{wordList.begin(), wordList.end()};
        if (wordDict.find(endWord) == wordDict.end()) return 0;

        unordered_map<string, int> beginVisited;
        unordered_map<string, int> endVisited;
        queue<pair<string, int>> beginQue;
        queue<pair<string, int>> endQue;
        beginVisited.insert(make_pair(beginWord, 1));
        endVisited.insert(make_pair(endWord, 1));
        beginQue.emplace(beginWord, 1);
        endQue.emplace(endWord, 1);

        while (!beginQue.empty() && !endQue.empty()) {
            if (!beginQue.empty()) {
                auto current = beginQue.front();
                beginQue.pop();
                for (int i = 0; i < current.first.size(); i++) {
                    for (auto ch = 'a'; ch <= 'z'; ch++) {
                        auto temp = current.first;
                        temp[i] = ch;
                        //判断是否在Dict中
                        //判断是否为结果
                        //判断是否访问过
                        if (wordDict.find(temp) != wordDict.end()) {
                            if (endVisited.find(temp) != endVisited.end()) {
                                return current.second + endVisited[temp];
                            } else if (beginVisited.find(temp) == beginVisited.end()) {
                                cout << "begin  " << current.first << " ->  " << temp << endl;
                                beginVisited.insert(pair<string, int>(temp, current.second + 1));
                                beginQue.push(pair<string, int>(temp, current.second + 1));
                            }
                        }
                    }
                }
            }
            if (!endQue.empty()) {
                auto current = endQue.front();
                endQue.pop();
                for (int i = 0; i < current.first.size(); i++) {
                    for (auto ch = 'a'; ch <= 'z'; ch++) {
                        auto temp = current.first;
                        temp[i] = ch;
                        //判断是否在Dict中
                        //判断是否为结果
                        //判断是否访问过
                        if (wordDict.find(temp) != wordDict.end()) {
                            if (beginVisited.find(temp) != beginVisited.end()) {
                                return current.second + beginVisited[temp];
                            } else if (endVisited.find(temp) == endVisited.end()) {
                                cout << "end  " << current.first << " ->  " << temp << endl;
                                endVisited.insert(pair<string, int>(temp, current.second + 1));
                                endQue.push(pair<string, int>(temp, current.second + 1));
                            }
                        }
                    }
                }
            }
        }

        return 0;
    }
};

TEST(ladderLength, 1) { /* NOLINT */
    cout << endl;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int answer = 5;
    auto output = Solution().ladderLength(beginWord, endWord, wordList);
    EXPECT_EQ(answer, output);
}

TEST(ladderLength, 2) { /* NOLINT */
    cout << endl;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    int answer = 0;
    auto output = Solution().ladderLength(beginWord, endWord, wordList);
    EXPECT_EQ(answer, output);
}