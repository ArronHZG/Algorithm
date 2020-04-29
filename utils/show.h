//
// Created by 侯正罡 on 2020/4/5.
//

#ifndef ALGORITHM_SHOW_H
#define ALGORITHM_SHOW_H

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>


using namespace std;

template<typename T>
void print(vector<T> vec) {
    for (auto a : vec) {
        cout.setf(ios_base::left, ios_base::adjustfield); //使用右对齐
        cout.width(4);
        cout << a;
    }
    cout << endl;
}

template<typename T>
void print(vector<vector<T>> vec) {
    for (const auto &v: vec) {
        print(v);
    }
    cout << endl;
}

#endif
