//
// Created by 侯正罡 on 2020/4/20.
//

#include "show.h"
#include <gtest/gtest.h>
#include "TreeNode.h"

class Solution {
public:

    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

TEST(maxDepth, 1) { /* NOLINT */
    cout << endl;
    string input = "[3,9,20,null,null,15,7]";
    auto tree = stringToTreeNode(input);
    prettyPrintTree(tree, "", true);
    auto answer = 3;
    auto output = Solution().maxDepth(tree);
    EXPECT_EQ(answer, output);
}

