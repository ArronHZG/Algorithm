//
// Created by 侯正罡 on 2020/5/15.
//


#include <gtest/gtest.h>
#include "show.h"
#include "TreeNode.h"

using namespace std;

class SolutionII {
public:
    void traversal(TreeNode *pNode, vector<int> &res) {
        if (pNode != nullptr) {
            traversal(pNode->left, res);
            res.push_back(pNode->val);
            traversal(pNode->right, res);
        }
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> sta;
        while (root || !sta.empty()) {
            while (root) {
                sta.push(root);
                root = root->left;
            }
            auto top = sta.top();
            sta.pop();
            res.push_back(top->val);
            if (top->right != nullptr) root = top->right;
        }
        return res;
    }
};

TEST(inorderTraversal, 1) {
    cout << endl;
    auto tree = stringToTreeNode("[1,null,2,3]");
    prettyPrintTree(tree);
    vector<int> answer = {1, 3, 2};
    auto output = Solution().inorderTraversal(tree);
    EXPECT_EQ(answer, output);
    EXPECT_EQ(answer, output);
}