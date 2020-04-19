//
// Created by 侯正罡 on 2020/4/20.
//

#include "show.h"
#include <gtest/gtest.h>
#include "TreeNode.h"

class Solution {
private:
    bool isBalancedTreeHelper(TreeNode *root, int &height) {
        if (root == nullptr) {
            height = 0;
            return true;
        }
        int left = 0;
        int right = 0;
        if (isBalancedTreeHelper(root->left, left) &&
            isBalancedTreeHelper(root->right, right) &&
            abs(left - right) < 2) {
            height = max(left, right) + 1;
            return true;
        } else
            return false;
    }

public:
    bool isBalanced(TreeNode *root) {
        int height;
        return isBalancedTreeHelper(root, height);
    }
};

TEST(isBalanced, 1) { /* NOLINT */
    cout << endl;
    string input = "[3,9,20,null,null,15,7]";
    auto tree = stringToTreeNode(input);
    prettyPrintTree(tree);
    auto answer = true;
    auto output = Solution().isBalanced(tree);
    EXPECT_EQ(answer, output);
}




