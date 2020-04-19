//
// Created by 侯正罡 on 2020/4/19.
//
#ifndef ALGORITHM_LISTNODE_H
#define ALGORITHM_LISTNODE_H

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <utility>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

void trimLeftTrailingSpaces(string &input);

void trimRightTrailingSpaces(string &input);

vector<int> stringToIntegerVector(string input);

ListNode *stringToListNode(string input);

void prettyPrintLinkedList(ListNode *node);

#endif
