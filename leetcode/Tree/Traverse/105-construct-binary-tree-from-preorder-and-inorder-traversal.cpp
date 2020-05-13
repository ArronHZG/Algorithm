//
// Created by 侯正罡 on 2020/5/13.
//


#include <gtest/gtest.h>
#include "show.h"
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return NULL;
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, int pre_start, int pre_end, vector<int> &inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) return nullptr;
        int flag = preorder[pre_start];
        TreeNode *root = new TreeNode(flag);
        int i = 0;
        while (inorder[in_start + i] != flag) ++i;
        root->left = build(preorder, pre_start + 1, pre_start + i,
                           inorder, in_start, in_start + i - 1);
        root->right = build(preorder, pre_start + i + 1, pre_end,
                            inorder, in_start + i + 1, in_end);
        return root;
    }
};


TEST(buildTree, 1) {
    cout << endl;
    vector<int> preorder = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> inorder = {4, 7, 2, 1, 5, 3, 8, 6};
//    vector<int> preorder = {4, 7};
//    vector<int> inorder = {4, 7};
    auto output = Solution().buildTree(preorder, inorder);
    prettyPrintTree(output);
}