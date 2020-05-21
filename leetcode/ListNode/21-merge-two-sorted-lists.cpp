//
// Created by 侯正罡 on 2020/5/21.
//


#include <gtest/gtest.h>
#include "show.h"
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        auto *res = new ListNode();
        auto p = res;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        p->next = l1 == nullptr ? l2 : l1;
        return res->next;
    }
};

TEST(mergeTwoLists, 1) {
    cout << endl;
    string input = "[1,2,4,6,7,8]";
    auto head = stringToListNode(input);
    prettyPrintLinkedList(head);
    string input2 = "[1,3,4]";
    auto head2 = stringToListNode(input2);
    prettyPrintLinkedList(head2);
    auto output = Solution().mergeTwoLists(head, head2);
    prettyPrintLinkedList(output);
}