//
// Created by 侯正罡 on 2020/5/21.
//


#include <gtest/gtest.h>
#include "show.h"
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *output = new ListNode();
        while (head != nullptr) {
            auto o = head;
            head = head->next;
            o->next = output->next;
            output->next = o;
        }
        return output->next;
    }
};

TEST(reverseList, 1) {
    cout << endl;
    string input = "[1,2,3,4,5,6]";
    auto head = stringToListNode(input);
    prettyPrintLinkedList(head);
    auto output = Solution().reverseList(head);
    prettyPrintLinkedList(output);
}