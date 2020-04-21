//
// Created by 侯正罡 on 2020/4/21.
//

#ifndef ALGORITHM_MATRIX_H
#define ALGORITHM_MATRIX_H


#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <random>

#define OVERFLOWED 1E-12

class Matrix {
public:
    Matrix(int m, int n);          //构建一个m*n的全零矩阵
    explicit Matrix(int n);        //构建一个n*n的单位矩阵
    Matrix(const Matrix &);        //拷贝构造函数，深拷贝
    Matrix(const double *items, int m, int n);//根据数组拷贝一个矩阵
    ~Matrix();

    static Matrix FromFile(std::string file);

    int getRowNum() const;                //返回矩阵的行数
    int getColNum() const;                //返回矩阵的列数

    Matrix Trans() const;                //将矩阵转置

    double get(int i, int j) const;            //返回矩阵第i行j列元素
    void set(int i, int j, double val);        //设置矩阵第i行j列元素

    Matrix operator+(const Matrix &m);         //两个矩阵相加
    Matrix operator-(const Matrix &m);         //两个矩阵相减
    Matrix operator*(const Matrix &m);         //两个矩阵相乘
    Matrix operator*(double f);                //矩阵乘以常数
    Matrix &operator=(const Matrix &m);

    Matrix Inverse();

    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);

    Matrix relu();

    double *item;        //指向矩阵首元素
    int rowNum;        //矩阵行数
    int colNum;        //矩阵列数

    Matrix softmax();

    int argmax();

    Matrix d_relu();

    Matrix itemMultiply(double d);

    Matrix addrRandom();

    Matrix dotMultiply(Matrix matrix);

private:
    //矩阵初等行变换
    //如果j=-1,则对i扩大multiply倍
    //如果j在取值范围内，则将第i行扩大multiply倍加到j行
    void RowSwap(int i, int j, double multiply);

    //交换两行
    void RowSwap(int i, int j);

    void FlowOver();
};

#endif //ALGORITHM_MATRIX_H
