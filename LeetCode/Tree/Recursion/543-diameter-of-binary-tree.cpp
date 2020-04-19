
//
// Created by 侯正罡 on 2020/4/20.
//
#include <gtest/gtest.h>
#include "TreeNode.h"


class Solution {
public:

    int diameterOfBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return diameterOfBinaryTree(root->left) + diameterOfBinaryTree(root->right) + 1;
    }
};

TEST(diameterOfBinaryTree, 1) { /* NOLINT */
    cout << endl;
    string input = "[3,9,20,null,null,15,7]";
    auto tree = stringToTreeNode(input);
    prettyPrintTree(tree, "", true);
    auto answer = 4;
    auto output = Solution().diameterOfBinaryTree(tree);
    EXPECT_EQ(answer, output);
}


