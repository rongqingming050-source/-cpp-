#include <iostream>
using namespace std;

const int M = 2;
const int N = 3;

class Matrix {
public:
    Matrix() {
        // 初始化矩阵为0
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                a[i][j] = 0;
            }
        }
    }

    // 矩阵相加
    friend Matrix operator+(Matrix &x, Matrix &y) {
        Matrix result;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                result.a[i][j] = x.a[i][j] + y.a[i][j];
            }
        }
        return result;
    }

    // 输入运算符重载（>>）
    friend istream &operator>>(istream &in, Matrix &x) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                in >> x.a[i][j];
            }
        }
        return in;
    }

    // 输出运算符重载（<<）
    friend ostream &operator<<(ostream &out, Matrix &x) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                out << x.a[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

private:
    double a[M][N];
};

int main() {
    Matrix m1, m2;
    
    cout << "请输入第一个矩阵(2行3列):" << endl;
    cin >> m1;
    
    cout << "请输入第二个矩阵(2行3列):" << endl;
    cin >> m2;
    
    cout << "\n矩阵1:\n" << m1;
    cout << "矩阵2:\n" << m2;
    
    Matrix m3 = m1 + m2;
    cout << "矩阵相加结果:\n" << m3;
    
    return 0;
}
