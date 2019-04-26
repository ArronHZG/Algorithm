////
//// Created by arron on 2019/4/24.
////
//#include <iostream>
//#include <array>
//#include <gtest/gtest.h>
//
//const int N = 100;
//const int M = 4;
//
//TEST(farmer, farmer) {
//    std::array<bool, M> state = {false, false, false, false};
//    std::array<std::array<bool, M>, 16> all_state = {};
//
//    for (auto &i:all_state) i = state;
//
//
//    std::array<bool, M> visited{};
//    for (auto &i:visited) i = true;
//
//    std::array<unsigned int, N> path{};
//    for (auto &i:path) i = 0;
//
//    state[3] = false;//0011
//    state[6] = false;//0110
//    state[7] = false;//0111
//    state[8] = false;//1000
//    state[9] = false;//1001
//    state[12] = false;//1100
//
//    //目标是1111
//    //初始值是0000
//    //如果有农夫，狐狸和鸡，鸡和米在一边没问题
//    //否则狐狸和鸡不能同在一边，鸡和米不能同在一边
//    //所以限定状态为：
//    state[0b0011] = false;
//    state[0b0110] = false;
//    state[0b0111] = false;
//    state[0b1100] = false;
//    state[0b1001] = false;
//    state[0b1000] = false;
//
//
//    findPath(state, visited, path, 0u, 0u, 0u, 0u, 0u);
//
//    return 0;
//
//}
//
////void printPath(int count, std::array<unsigned int, N> &path) {
////    static int cnt = 0;
////    std::cout << "Solution " << cnt++ << ":" << std::endl;
////    for (unsigned int i = 0; i < count; i++) {
////        unsigned int a = path[i] & 8u >> 3u;
////        unsigned int b = path[i] & 4u >> 2u;
////        unsigned int c = path[i] & 2u >> 1u;
////        unsigned int d = path[i] & 1u;
////        std::cout << a << b << c << d << std::endl;
////    }
////}
////
////void findPath(std::array<bool, M> &state,
////              std::array<bool, M> &visited,
////              std::array<unsigned int, N> &path,
////              unsigned int count,
////              unsigned int f,//表示农夫
////              unsigned int w,//表示狐狸
////              unsigned int s,//表示鸡
////              unsigned int v//表示米
////) {
////    //如果全过去了，tmp就会变成15，然后输出路径
////    unsigned int tmp = (f<<3u) + (w<<2u) + (s<<1u) + v;
////    if (tmp == 15) {
////        path[count++] = 15;
////        printPath(count, path);
////    }
////    if (state[tmp] && !visited[tmp])//valid state and has not been visited
////    {
////        visited[tmp] = true;
////        path[count++] = tmp;
////        findPath(state, visited, path, count, (~f) & 1u, w, s, v);
////        findPath(state, visited, path, count, (~f) & 1u, (~w) & 1u, s, v);
////        findPath(state, visited, path, count, (~f) & 1u, w, (~s) & 1u, v);
////        findPath(state, visited, path, count, (~f) & 1u, w, s, (~v) & 1u);
////        visited[tmp] = false;
////    }
////}
////
////int main() {    //Set state.
//
////}