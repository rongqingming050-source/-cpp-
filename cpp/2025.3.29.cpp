#include <iostream>
using namespace std;
const int N = 3; // 定义矩阵大小为3×3
class Matrix {
private:
    int data[N][N]; // 存储矩阵数据的二维数组
public:
    Matrix() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                data[i][j] = 0;
            }
        }
    }
    void setValue(int row, int col, int value) {
        if (row >= 0 && row < N && col >= 0 && col < N) {
            data[row][col] = value;
        }
    }
    int getValue(int row, int col) const {
        if (row >= 0 && row < N && col >= 0 && col < N) {
            return data[row][col];
        }
        return 0;
    }
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    void print() const {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }
};
int main() {
    Matrix mat1, mat2;
    mat1.setValue(0, 0, 1); mat1.setValue(0, 1, 2); mat1.setValue(0, 2, 3);
    mat1.setValue(1, 0, 4); mat1.setValue(1, 1, 5); mat1.setValue(1, 2, 6);
    mat1.setValue(2, 0, 7); mat1.setValue(2, 1, 8); mat1.setValue(2, 2, 9);
    mat2.setValue(0, 0, 9); mat2.setValue(0, 1, 8); mat2.setValue(0, 2, 7);
    mat2.setValue(1, 0, 6); mat2.setValue(1, 1, 5); mat2.setValue(1, 2, 4);
    mat2.setValue(2, 0, 3); mat2.setValue(2, 1, 2); mat2.setValue(2, 2, 1);
    cout << "矩阵1:" << endl;
    mat1.print();
    cout << "\n矩阵2:" << endl;
    mat2.print();
    Matrix sum = mat1 + mat2;
    cout << "\n矩阵加法结果:" << endl;
    sum.print();
    Matrix diff = mat1 - mat2;
    cout << "\n矩阵减法结果:" << endl;
    diff.print();
    Matrix product = mat1 * mat2;
    cout << "\n矩阵乘法结果:" << endl;
    product.print();
    return 0;
}
