//
// Created by arron on 2019/4/24.
//
#include <iostream>
#include <gtest/gtest.h>

void binSearch(std::array<int, 10> array, int num, int *pInt);

TEST(binSearch, binSearch)
{
    std::array<int,10> array = {1,2,4,6,78,90,100,102,122,300};
    int findNum = 100;
    int i = 0;
    binSearch(array,findNum,&i);
    EXPECT_EQ(findNum,array[i]);
}
void binSearch(std::array<int, 10> array, int num, int *pInt) {

}
