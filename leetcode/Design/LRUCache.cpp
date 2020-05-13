//
// Created by 侯正罡 on 2020/5/13.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class Node {
public:
    int key;
    int val;
    Node *next;
    Node *prev;

    Node() {}

    Node(int k, int v) : key(k), val(v) {}
};

/**
 * 每次从 head 处添加
 *    从 tail 处删除
 */

class DoubleList {
public:
    Node *head;
    Node *tail;
    int size;

    DoubleList() {
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    /**
     * A->    <-B->    <-C
     *
     * head->    <-D->
     * @param node
     */
    void moveToHead(Node *pNode) {
        Node *A = pNode->prev;
        Node *C = pNode->next;
        A->next = C;
        C->prev = A;
        Node *D = head->next;
        head->next = pNode;
        pNode->prev = head;
        pNode->next = D;
        D->prev = pNode;
    }

    /**
     *
     * head->    <-D->
     * @param pNode
     */
    void addNode(Node *pNode) {
        Node *D = head->next;
        head->next = pNode;
        pNode->prev = head;
        pNode->next = D;
        D->prev = pNode;
        size++;
    }

    /**
     * <-E->    <-F->  <-tail
     * @param pNode
     */
    int removeTailNode(Node *pNode) {
        Node *F = tail->prev;
        int tailKey = F->key;
        Node *E = F->prev;
        E->next = tail;
        tail->prev = E;
        size--;
        delete F;
        return tailKey;
    }

    void print() {
        Node *p = head->next;
        while (p != tail) {
            cout << p->key << "|" << p->val <<"  ";
            p=p->next;
        }
        cout << endl;
    }
};

class LRUCache {
public:
    unordered_map<int, Node *> cache;
    DoubleList doubleList;
    int capacity;

    explicit LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        doubleList.moveToHead(cache[key]);
        return cache[key]->val;
    }

    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            Node *node = new Node(key, value);
            cache[key] = node;
            doubleList.addNode(node);
            if (doubleList.size > capacity) {
                int tailKey = doubleList.removeTailNode(node);
                cache.erase(tailKey);
            }

        } else {
            cache[key]->val = value;
            doubleList.moveToHead(cache[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

TEST(LRUCache, 1) {
    cout << endl;
    LRUCache cache = *new LRUCache(2 /* capacity */ );

    cache.put(1, 10);
    cache.doubleList.print();
    cache.put(2, 20);
    cache.doubleList.print();
    cache.get(1);       // returns 1
    cache.doubleList.print();
    cache.put(3, 30);    // evicts key 2
    cache.doubleList.print();

    cache.get(2);       // returns -1 (not found)
    cache.doubleList.print();

    cache.put(1, 100);    // evicts key 1
    cache.doubleList.print();

    cache.get(1);       // returns -1 (not found)
    cache.doubleList.print();

    cache.get(3);       // returns 3
    cache.doubleList.print();

    cache.get(4);       // returns 4
    cache.doubleList.print();

}