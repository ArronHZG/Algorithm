//
// Created by 侯正罡 on 2020/5/14.
//


#include <gtest/gtest.h>
#include "show.h"
#include "TreeNode.h"

using namespace std;

class SolutionII {
public:
    void traversal(TreeNode *pNode, vector<int> &res) {
        if (pNode != nullptr) {
            res.push_back(pNode->val);
            traversal(pNode->left, res);
            traversal(pNode->right, res);
        }
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> sta;
        if (root != nullptr) sta.push(root);
        while (!sta.empty()) {
            auto node = sta.top();
            sta.pop();
            res.push_back(node->val);
            if (node->right != nullptr) sta.push(node->right);
            if (node->left != nullptr) sta.push(node->left);
        }
        return res;
    }
};

TEST(preorderTraversal, 1) {
    cout << endl;
    auto tree = stringToTreeNode("[1,null,2,3]");
    prettyPrintTree(tree);
    vector<int> answer = {1, 2, 3};
    auto output = Solution().preorderTraversal(tree);
    EXPECT_EQ(answer, output);
}