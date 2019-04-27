//
// Created by arron on 2019/4/27.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto root = new ListNode(0);
        auto p = root;
        auto q = p;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                p->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                p->val += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(p->val / 10);
            p->val = (p->val % 10);
            q = p;
            p = p->next;
        }
        if(!q->next->val) {
            delete (q->next);
            q->next = nullptr;
        }
        return root;
    }
};

TEST(addTwoNumbers, 1) {
    cout << endl;
    vector<int> v1{3, 4};
    vector<int> v2{4, 6};
    auto *l1 = new ListNode(2);
    for (auto num:v1) {
        auto *node = new ListNode(num);
        node->next = l1->next;
        l1->next = node;
    }
    auto p = l1;
    while (p != nullptr) {
        cout << p->val << endl;
        p = p->next;
    }

    auto *l2 = new ListNode(5);
    for (auto num:v2) {
        auto *node = new ListNode(num);
        node->next = l2->next;
        l2->next = node;
    }
    p = l2;
    while (p != nullptr) {
        cout << p->val << endl;
        p = p->next;
    }
    p = Solution().addTwoNumbers(l1, l2);

    while (p != nullptr) {
        cout << p->val << endl;
        p = p->next;
    }
}
