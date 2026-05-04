#include<iostream>
using namespace std;
template <typename T>
class set {
public:
    set(T* a1, T* a2, int s1 = 0, int s2 = 0);
    void show(T* a3, int s3 = 0);
    int bing(T* a3); 
    int jiao(T* a3);  
    int cha(T* a3);   
private:
    T* arr1, * arr2;
    int size1, size2;
};
template <typename T>
set<T>::set(T* a1, T* a2, int s1, int s2) : arr1(a1), arr2(a2), size1(s1), size2(s2) {
    cout << "请输入集合的元素：" << endl;
    cout << "集合1" << "---" << size1 << "个" << endl;
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }
    cout << "集合2" << "---" << size2 << "个" << endl;
    for (int j = 0; j < size2; ++j) {
        cin >> arr2[j];
    }
}
template <typename T>
void set<T>::show(T* a3, int s3) {
    for (int i = 0; i < s3; i++) {
        cout << " " << a3[i];
    }
    cout << endl;
}
template <typename T>
int set<T>::jiao(T* a3) {
    int s3 = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                a3[s3++] = arr1[i];
            }
        }
    }
    return s3;
}
template <typename T>
int set<T>::bing(T* a3) {
    int s3 = size1;
    for (int i = 0; i < size1; i++) {
        a3[i] = arr1[i];
    }
    for (int j = 0; j < size2; j++) {
        bool found = false;
        for (int i = 0; i < size1; i++) {
            if (arr2[j] == arr1[i]) {
                found = true;
            }
        }
        if (!found) {
            a3[s3++] = arr2[j];
        }
    }
    return s3;
}
template <typename T>
int set<T>::cha(T* a3) {
    int s3 = 0;
    for (int i = 0; i < size1; i++) {
        bool found = false;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                found = true;
            }
        }
        if (!found) {
            a3[s3++] = arr1[i];
        }
    }
    return s3;
}
int main() {
    int a1[5], a2[6], a3[11];
    int s1 = 5, s2 = 6;
    set<int> a(a1, a2, s1, s2);   
    cout << "并集: ";
    int s3 = a.bing(a3);
    a.show(a3, s3);   
    cout << "差集(A-B): ";
    s3 = a.cha(a3);
    a.show(a3, s3);   
    cout << "交集: ";
    s3 = a.jiao(a3);
    a.show(a3, s3);   
    return 0;
}
