//
// Created by 侯正罡 on 2020/4/19.
//

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "show.h"
#include "TreeNode.h"


using namespace std;

int main() {
    cout << "hello" << endl;
    vector<int> dp(10, 1);
    print<int>(dp);
    string list = "[1,2,3,4,5]";
    TreeNode *tree = stringToTreeNode(list);
    cout << "tree" << endl;
    prettyPrintTree(tree, "", true);
    return 0;
}

//TEST(someting, 1) {
//    cout << endl;
//    vector<int> dp(10, 1);
//    cout << "gtest" << endl;
//}