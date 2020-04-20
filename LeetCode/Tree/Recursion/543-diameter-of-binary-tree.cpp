
//
// Created by 侯正罡 on 2020/4/20.
//
#include <gtest/gtest.h>
#include "TreeNode.h"


class Solution {
public:

    int maxDepth(TreeNode *root, int &dia) {
        if (root == nullptr) {
            return 0;
        }
        int l = maxDepth(root->left, dia);
        int r = maxDepth(root->right, dia);
        dia = max(dia, l + r);
        return max(l, r) + 1;
    }


    int diameterOfBinaryTree(TreeNode *root) {
        int dia = 0;
        maxDepth(root, dia);
        return dia;
    }
};

TEST(diameterOfBinaryTree, 1) { /* NOLINT */
    cout << endl;
    string input = "[3,9,20,null,null,15,7]";
    auto tree = stringToTreeNode(input);
    prettyPrintTree(tree, "", true);
    auto answer = 3;
    auto output = Solution().diameterOfBinaryTree(tree);
    EXPECT_EQ(answer, output);
}


