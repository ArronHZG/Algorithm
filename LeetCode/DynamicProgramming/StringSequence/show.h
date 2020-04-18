//
// Created by 侯正罡 on 2020/4/5.
//

#ifndef DYNAMICPROGRAMMING_SHOW_H
#define DYNAMICPROGRAMMING_SHOW_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void print(vector<T> vec) {
    for (auto a : vec) {
        cout << a << ' ';
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

#endif //DYNAMICPROGRAMMING_SHOW_H
