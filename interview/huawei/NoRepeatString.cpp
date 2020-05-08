//
// Created by 侯正罡 on 2020/4/29.
//


#include <gtest/gtest.h>
#include "show.h"

using namespace std;


void DFS(int index, string basic, vector<int> used, string input, set<string> &memo) {
    used[index]--;
    basic += input[index];
    if (basic.size() == input.size()) {
        memo.insert(basic);
        return;
    }
    for (int i = 0; i < used.size(); i++) {
        if (used[i] > 0) {
            DFS(i, basic, used, input, memo);
        }
    }
}

void noRepeatString(string input) {
    if (input.empty()) {
        cout << 0 << endl;
        return;
    }
    set<string> memo;
    sort(input.begin(), input.end());
    vector<int> used(input.size(), 1);
    DFS(0, "", used, input, memo);

    for (int i = 1; i < input.size(); i++) {
        if (input[i] != input[i - 1]) {
            vector<int> used(input.size(), 1);
            DFS(i, "", used, input, memo);
        }
    }
    cout << memo.size() << endl;
}

TEST(NoRepeatString, 1) {
    cout << endl;
    string input = "aab";
    noRepeatString(input);
}