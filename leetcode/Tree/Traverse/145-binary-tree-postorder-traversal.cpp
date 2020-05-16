//
// Created by 侯正罡 on 2020/5/16.
//


#include <gtest/gtest.h>
#include "show.h"
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) return {};
        stack<TreeNode *> stk;
        stk.push(root);
        vector<int> res;
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            if (node == nullptr) {
                stk.pop();
                res.push_back(stk.top()->val);
                stk.pop();
                continue;
            }
            stk.push(nullptr);
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
        return res;
    }
};

TEST(postorderTraversal, 1) {
    cout << endl;
    auto tree = stringToTreeNode("[1,null,2,3]");
    prettyPrintTree(tree);
    vector<int> answer = {3, 2, 1};
    auto output = Solution().postorderTraversal(tree);
    EXPECT_EQ(answer, output);
}