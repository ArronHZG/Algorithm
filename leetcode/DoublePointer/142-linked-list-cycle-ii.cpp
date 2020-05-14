//
// Created by 侯正罡 on 2020/5/14.
//


#include <gtest/gtest.h>
#include "show.h"
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

TEST(detectCycle, 1) {
    cout << endl;
    string input = "[1,2,3,4,5,6]";
    auto head = stringToListNode(input);
    prettyPrintLinkedList(head);
    int i = 2;
    auto p = head;
    auto q = head;
    while (p->next != nullptr) {
        if (i-- == 0) q = p;
        p = p->next;
    }
    p->next = q;
    auto output = Solution().detectCycle(head);
    EXPECT_EQ(q, output);
    cout << q->val << endl;
}