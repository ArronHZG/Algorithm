//
// Created by arron on 2019/6/13.
//

/* 1.热身：给一个带环的链，用尽量小的额外空间
 * （1）找出交点
 * （2）求出环的长度
 */
#include <iostream>

struct node {
    node* next;
    int val;
};

node* get_intersect(node* head) {
    auto p_fast = head;
    auto p_slow = head;

    while(p_fast->next)

}


int get_length(node* head) {
}