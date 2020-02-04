//
// Created by 侯正罡 on 2020/2/4.
//

/**
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;


/**
 * 二叉查找树（Binary Search Tree），
 * （又：二叉搜索树，二叉排序树）它或者是一棵空树，
 * 或者是具有下列性质的二叉树：
 * 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
 * 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
 * 它的左、右子树也分别为二叉排序树。
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /*
     * 设置区间为左右闭区间
     *
     * 给定一个区间
     * 遍历区间内每一个值, 通过该值划分左右两区间
     * 左区间生成的子树为全部左子树,右区间生成的子树为全部右子树,两两组合为全部二叉搜索数
     *
     */
    vector<TreeNode *> getTree(int begin, int end) {
        vector<TreeNode *> res;
        if (begin > end) {
            res.push_back(nullptr);
            return res;
        }
        for (int i = begin; i <= end; i++) {
            auto leftNode = getTree(begin, i - 1);
            auto rightNode = getTree(i + 1, end);
            for (auto left: leftNode) {
                for (auto right: rightNode) {
                    auto *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode *>();
        }
        return getTree(1, n);
    }
};

void printTree(TreeNode *tree) {
    if (tree) {
        cout << tree->val << " ";
        printTree(tree->left);
        printTree(tree->right);
    } else {
        cout << "  ";
    }
}


TEST(getTree, 1) { /* NOLINT */
    cout << endl;
    int input = 10;
    auto output = Solution().generateTrees(input);
    for (auto tree: output) {
        printTree(tree);
        cout << endl;
    }
}
