#include <iostream>
using namespace std;

template <typename T>
class Compare {
public:
    Compare(T a, T b);
    T max();
private:
    T x, y;
};

template <typename T>
Compare<T>::Compare(T a, T b) {
    x = a;  // 修正拼写错误：aiy → a, y
    y = b;
}

template <typename T>
T Compare<T>::max() {
    return (x > y ? x : y);
}

int main() {
    Compare<int> com1(3, 7);
    Compare<double> com2(12.34, 56.78);
    Compare<char> com3('a', 'x');

    cout << "其中的最大值是：" << com1.max() << endl;    // 输出 7
    cout << "其中的最大值是：" << com2.max() << endl;    // 输出 56.78
    cout << "其中的最大值是：" << com3.max() << endl;    // 输出 x

    return 0;
}
