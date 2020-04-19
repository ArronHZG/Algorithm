//
// Created by 侯正罡 on 2020/4/19.
//

#ifndef ALGORITHM_TREENODE_H
#define ALGORITHM_TREENODE_H

#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


string treeNodeToString(TreeNode *root);

void trimLeftTrailingSpacesForTree(string &input);

void trimRightTrailingSpacesForTree(string &input);

TreeNode *stringToTreeNode(string input);

void prettyPrintTree(TreeNode *node, const string &prefix = "", bool isLeft = true);

#endif

