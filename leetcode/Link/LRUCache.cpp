//
// Created by 侯正罡 on 2020/4/25.
//

/**
 *
    来源：力扣（leetcode）
    链接：https://leetcode-cn.com/problems/lru-cache
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <gtest/gtest.h>
#include "show.h"

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {

    }

    int get(int key) {

    }

    void put(int key, int value) {

    }
};

TEST(LRUCache, 1) {
    cout << endl;
    vector<int> input = {};
    int capacity = 2;
    int answer = 0;

    // Your LRUCache object will be instantiated and called as such:
    LRUCache *cache = new LRUCache(capacity);
    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);       // 返回  1
    cache->put(3, 3);    // 该操作会使得密钥 2 作废
    cache->get(2);       // 返回 -1 (未找到)
    cache->put(4, 4);    // 该操作会使得密钥 1 作废
    cache->get(1);       // 返回 -1 (未找到)
    cache->get(3);       // 返回  3
    cache->get(4);       // 返回  4
}