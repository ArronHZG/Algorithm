//
// Created by 侯正罡 on 2020/4/1.
//
/**
 * Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
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
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> res;
    vector<int> his;

    vector<string> binaryTreePaths(TreeNode *root) {
        search(root);
        return res;

    }

    void search(TreeNode *root) {
        if (root != nullptr) {
            if (root->right == nullptr && root->left == nullptr) {
                his.push_back(root->val);
                string str = to_string(his[0]);
                for (int i = 1; i < his.size(); i++) {
                    str += "->" + to_string(his[i]);
                }
                res.push_back(str);
                his.pop_back();
            } else {
                his.push_back(root->val);
                search(root->left);
                search(root->right);
                his.pop_back();
            }
        }
    }
};