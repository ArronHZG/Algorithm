//
// Created by 侯正罡 on 2020/4/21.
//


#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "show.h"
#include "Matrix.h"

using namespace std;


class Attach {
public:

    Matrix w1, w2, z, x;
    Matrix x_source;
    int N = 0;

    Attach(int N, int M, Matrix &w1, Matrix &w2, Matrix x) :
            w1(w1),
            w2(w2),
            N(N),
            z(Matrix(M, 1)),
            x(x), x_source(x) {};

    /**
     * input: x
     * a = w1*x
     * z = ReLU(a)
     * b = w2*z
     * f = softmax(b)
     * label = argmax(f)
     */
    Matrix forward(Matrix &matrix) {
        auto a = w1 * matrix;
//        cout << a << endl;
        z = a.relu();
//        cout << z << endl;
        auto b = w2 * z;
//        cout << b << endl;
        auto f = b.softmax();
        return f;

    }

    /**
     *
     * dL/dx = dL/df * df/db * db/dz * dz/da * da/dx
     *
     * L = -cross-entropy(f_,f)  f_ is ground-truth, f is output feature.
     * f = softmax(b)
     * dL/df * df/db  = f_ - f (10,1)
     * https://blog.csdn.net/chaipp0607/article/details/101946040
     *
     * db/dz = w2  (10,4)
     *
     * dz/da = 1 if z>0 else 0 (4,1)
     *
     * da/dx = w1 (4,8)
     */
    Matrix backward(Matrix target, Matrix feature, double loss) {
        auto dz = z.d_relu();
        auto dl = target - feature;
        auto dl_T = dl.Trans();
        auto dl_ = dl_T * w2;
        dl_ = dl_.dotMultiply(dz);
        auto dL = dl_ * w1;
        dL = dL.itemMultiply(loss);
        return dL;
    }

    int eval(Matrix matrix) {
        auto f = forward(matrix);
        auto label = f.argmax();
        return label;
    }

    int try_change(Matrix matrix, int l) {
        for (int i = 0; i < x.colNum * x.rowNum; i++) {
            auto temp_x = x_source;
            temp_x.item[i] = x.item[i];
            auto label = eval(temp_x);
            if (l != label) {
                return label;
            }
        }
        return l;
    }

    void update(double lr, Matrix dL) {
        auto d = dL.itemMultiply(lr).Trans();
        x = x - d;
    }

    double CrossEntropy(Matrix target, Matrix feature) {
        double sum = 0;
        for (int i = 0; i < target.colNum * target.rowNum; i++) {
            sum -= target.item[i] * log(feature.item[i]);
        }
        return sum / target.colNum * target.rowNum;
    }

    int attach() {
        auto target = forward(x);
        auto label_feature = target;
        x = x.addrRandom();
        auto label = eval(x);
        for (int i = 0; i < 100000; i++) {
            label_feature = forward(x);
            auto loss = CrossEntropy(target, label_feature);
            auto dL = backward(target, label_feature, loss);
            auto l = try_change(x, label);
            cout << "i " << i << " loss: " << loss << " label:" << l << endl;
//            cout << x << endl;
            if (l != label) {
                break;
            }
        }
        cout << x << endl;
        return 0;
    }

    int compare(Matrix &x) {
        double max = 0;
        int index = 0;
        for (int i = 0; i < x.rowNum * x.colNum; i++) {
            auto tmp = abs(x.item[i]) - x.item[i];
            if (tmp > max) {
                max = tmp;
                index = i;
            }
        }
        return index;
    }
};


TEST(attack, 1) { /* NOLINT */
    cout << endl;
    int N = 8;
    int M = 4;
    //第一行是两个整数N，M。代表输入向量的维度为N，第一个隐藏层的节点数为M。
    //第二行有N个整数，以空格隔开。即为输入的向量。
    double input[8] = {-4, -71, -56, -41, 85, -19, -56, -3};
    //第三行有M*N个浮点数，以空格隔开。即第一个全连接层的网络参数W1。其中第(i-1)*N+1到第i*N个浮点数是第一个全连接层第i个节点的权重参数。
    double w1[32] = {0.00719, 0.01590, -0.01121, -0.02345, 0.00777, 0.01680, 0.01642, -0.01437, 0.04963, -0.02698,
                     -0.03168, -0.02930, 0.00784, -0.03372, -0.01824, 0.01997, -0.01687, -0.02018, -0.00434,
                     -0.00647, -0.01860, -0.01780, -0.01345, 0.03369, 0.00142, -0.00109, -0.02072, 0.00518, -0.02600,
                     -0.01217, -0.00510, -0.00254};
    //第四行有10*M个浮点数，以空格隔开。即第二个全连接层的网络参数W2。其中第(i-1)*M+1到第i*M个浮点数是第二个全连接层第i个节点的权重参数。
    double w2[40] = {-0.00372, 0.06219, 0.00260, 0.06550, -0.02418, -0.02375, 0.00115, 0.00132, 0.00280, -0.01428,
                     0.02612, -0.03527, -0.02926, -0.02194, -0.04160, 0.03126, 0.01071, 0.02239, 0.00883, 0.03610,
                     0.00117, 0.00429, -0.05671, 0.00374, 0.03496, 0.03749, 0.03426, 0.01259, 0.01202, -0.00021,
                     -0.04738, -0.02131, 0.02525, 0.04419, -0.01626, 0.04310, -0.01328, -0.00932, -0.03152,
                     0.06103};

    auto m_input = Matrix(input, N, 1);
    auto m_w1 = Matrix(w1, M, N);
    auto m_w2 = Matrix(w2, 10, M);

    auto att = Attach(N, M, m_w1, m_w2, m_input);
    auto label = att.eval(m_input);
    att.attach();
    auto i = att.compare(m_input);
    cout << "label " << label;
    cout << " index" << i << " " << att.x.item[i] << endl;

    m_input.set(0, 0, -77);
    auto att2 = Attach(N, M, m_w1, m_w2, m_input);
    auto label2 = att2.eval(m_input);
    cout << label2 << endl;
}

//int main() {
//    int M, N;
//    //第一行是两个整数N，M。代表输入向量的维度为N，第一个隐藏层的节点数为M。
//    cin >> N >> M;
//    //第二行有N个整数，以空格隔开。即为输入的向量。
//    double input[N];
//    for (int i = 0; i < N; i++) cin >> input[i];
//    //第三行有M*N个浮点数，以空格隔开。即第一个全连接层的网络参数W1。其中第(i-1)*N+1到第i*N个浮点数是第一个全连接层第i个节点的权重参数。
//    double w1[M * N];
//    for (int i = 0; i < M * N; i++) cin >> w1[i];
//    //第四行有10*M个浮点数，以空格隔开。即第二个全连接层的网络参数W2。其中第(i-1)*M+1到第i*M个浮点数是第二个全连接层第i个节点的权重参数。
//    double w2[M * 10];
//    for (int i = 0; i < M * 10; i++) cin >> w2[i];
//
//    auto m_input = Matrix(input, N, 1);
//    auto m_w1 = Matrix(w1, M, N);
//    auto m_w2 = Matrix(w1, 10, M);
//
//    cout << i << " " << m_input[i][0] << endl;
//
//    return 0;
//}