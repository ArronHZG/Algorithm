//
// Created by arron on 2019/5/2.
//
#include <iostream>
#include <list>
#include <gtest/gtest.h>


using namespace std;


class Node {
private:
    // 节点内区块信息
    int area[9];
    // 该节点位于的搜索深度
    int depth;
    // 该节点的父节点
    Node *parent;

    // 获取节点区块内 0 的位置
    int getZeroLocation();

public:
    // 构造
    Node(int *area);

    Node(int *area, int depth, Node *parent);

    // getter
    int *getArea();

    int getDepth();

    Node *getParent();

    // 比较两个节点的区块信息是否相同
    bool equal(Node *);

    // 某个方向是否可扩展
    bool topExtendable();

    bool bottomExtendable();

    bool leftExtendable();

    bool rightExtendable();

    // 获取向某个方向扩展而得到的子节点
    Node *topExtend();

    Node *bottomExtend();

    Node *leftExtend();

    Node *rightExtend();

    // 估价函数
    int evaluation(Node *);

    // 是否在列表中
    bool inList(list<Node *> *);
};


Node::Node(int *area) {
    for (int i = 0; i < 9; i++)
        this->area[i] = area[i];
    this->depth = 0;
    this->parent = nullptr;
}

Node::Node(int *area, int depth, Node *parent) {
    for (int i = 0; i < 9; i++)
        this->area[i] = area[i];
    this->depth = depth;
    this->parent = parent;
}

int *Node::getArea() {
    return this->area;
}

int Node::getDepth() {
    return this->depth;
}

Node *Node::getParent() {
    return this->parent;
}

bool Node::equal(Node *another) {
    for (int i = 0; i < 9; i++) {
        if (this->area[i] != another->area[i]) return false;
    }
    return true;
}

int Node::getZeroLocation() {
    for (int i = 0; i < 9; i++) {
        if (this->area[i] == 0) return i;
    }
    return -1;
}

bool Node::topExtendable() {
    return this->getZeroLocation() / 3 > 0;
}

bool Node::bottomExtendable() {
    return this->getZeroLocation() / 3 < 2;
}

bool Node::leftExtendable() {
    return this->getZeroLocation() % 3 > 0;
}

bool Node::rightExtendable() {
    return this->getZeroLocation() % 3 < 2;
}

Node *Node::topExtend() {
    int area[9];
    for (int i = 0; i < 9; i++) area[i] = this->area[i];

    int zero = this->getZeroLocation();
    int row = zero / 3;
    int col = zero % 3;

    int temp = area[zero];
    area[zero] = area[(row - 1) * 3 + col];
    area[(row - 1) * 3 + col] = temp;

    Node *node = new Node(area, this->depth + 1, this);

    return node;
}

Node *Node::bottomExtend() {
    int area[9];
    for (int i = 0; i < 9; i++) area[i] = this->area[i];

    int zero = this->getZeroLocation();
    int row = zero / 3;
    int col = zero % 3;

    int temp = area[zero];
    area[zero] = area[(row + 1) * 3 + col];
    area[(row + 1) * 3 + col] = temp;

    Node *node = new Node(area, this->depth + 1, this);

    return node;
}

Node *Node::leftExtend() {
    int area[9];
    for (int i = 0; i < 9; i++) area[i] = this->area[i];

    int zero = this->getZeroLocation();
    int row = zero / 3;
    int col = zero % 3;

    int temp = area[zero];
    area[zero] = area[row * 3 + (col - 1)];
    area[row * 3 + (col - 1)] = temp;

    Node *node = new Node(area, this->depth + 1, this);

    return node;
}

Node *Node::rightExtend() {
    int area[9];
    for (int i = 0; i < 9; i++) area[i] = this->area[i];

    int zero = this->getZeroLocation();
    int row = zero / 3;
    int col = zero % 3;

    int temp = area[zero];
    area[zero] = area[row * 3 + (col + 1)];
    area[row * 3 + (col + 1)] = temp;

    Node *node = new Node(area, this->depth + 1, this);

    return node;
}

int Node::evaluation(Node *endNode) {
    int n = 0;
    for (int i = 0; i < 9; i++) {
        if (this->area[i] != endNode->getArea()[i]) n++;
    }
    return this->depth + n;
}

bool Node::inList(list<Node *> *l) {
    bool find = false;
    for (Node *node: *l) {
        if (this->equal(node)) {
            find = true;
            break;
        }
    }
    return find;
}

int eightNumber() {

    // 输入初始节点
    int inputs[9] = {2, 8, 3, 1, 0, 4, 7, 6, 5};

    // 定义初始节点和结束节点
    Node *startNode = new Node(inputs);
    Node *endNode = new Node(new int[9]{1, 2, 3, 8, 0, 4, 7, 6, 5});

    // 输出一哈结束节点
    cout << endl << "结束节点: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << endNode->getArea()[i * 3 + j] << " ";
        cout << endl;
    }
    cout << endl;

    // 定义open表和closed表
    list<Node *> open, closed;

    // 将初始节点推入open表
    open.push_back(startNode);

    // 定义成功状态
    bool success = false;

    // 开始查找
    while (!open.empty()) {
        // 取出open表第一个元素
        Node *move = open.front();
        open.pop_front();

        // 如果搜索深度超过了设定值，则跳出并判断失败
        bool jump = false;
        for (Node *node : open) {
            if (node->getDepth() > 18) {
                jump = true;
                break;
            }
        }
        if (jump) break;

        // 将其移入closed表
        closed.push_back(move);

        // 如果其与结束节点相同，则查找成功并结束
        if (move->equal(endNode)) {
            success = true;
            break;
        }

        // 将节点扩展并且加入open表
        if (move->topExtendable()) {
            Node *ex = move->topExtend();
            if (!ex->inList(&open) && !ex->inList(&closed)) open.push_back(ex);
        }
        if (move->bottomExtendable()) {
            Node *ex = move->bottomExtend();
            if (!ex->inList(&open) && !ex->inList(&closed)) open.push_back(ex);
        }
        if (move->leftExtendable()) {
            Node *ex = move->leftExtend();
            if (!ex->inList(&open) && !ex->inList(&closed)) open.push_back(ex);
        }
        if (move->rightExtendable()) {
            Node *ex = move->rightExtend();
            if (!ex->inList(&open) && !ex->inList(&closed)) open.push_back(ex);
        }

        // 将open表排序
        open.sort([=](Node *a, Node *b) -> bool {
            return a->evaluation(endNode) < b->evaluation(endNode);
        });
    }

    if (success) {
        // 统计步骤数量并输出结果
        int count = 0;
        Node *result = closed.back();
        list<Node *> l;
        while (result) {
            l.push_back(result);
            count++;
            result = result->getParent();
        }
        cout << "搜索成功!" << endl << "步骤数(加上起止): " << count << endl;
        cout << "详细步骤: " << endl;
        while (!l.empty()) {
            Node *front = l.back();
            l.pop_back();
            for (int i = 0; i < 9; i++) cout << front->getArea()[i] << " ";
            cout << endl;
        }
    } else {
        cout << "搜索失败!在指定搜索深度内没能完成搜索!" << endl;
    }

    return 0;

}


TEST(eightNumber, eightNumber) {
//从初始状态开始搜索
    eightNumber();
}