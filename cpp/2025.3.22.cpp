#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    int len;

public:
    String() : str(), len(0) {
        str = new char[1];
        str[0] = '\0';
    }
    String(const char* s) {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    String(const String& other) {
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }
    ~String() {
        delete[] str;
    }
    void set(const char* s) {
        delete[] str;
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    void print() const {
        std::cout << str << std::endl;
    }
    int length() const {
        return len;
    }
    void remove(char c) {
        int newLen = 0;
        for (int i = 0; i < len; ++i) {
            if (str[i] != c) {
                str[newLen++] = str[i];
            }
        }
        str[newLen] = '\0';
        len = newLen;
    }
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            len = other.len;
            str = new char[len + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }
    String operator+(const String& other) const {
        String newString;
        newString.len = len + other.len;
        newString.str = new char[newString.len + 1];
        strcpy(newString.str, str);
        strcat(newString.str, other.str);
        return newString;
    }
};
int main() {
    String s1("Hello");
    String s2("World");
    s1.print();
    s2.print();
    String s3 = s1 + s2;
    s3.print();
    s1.remove('l');
    s1.print();
    if (s1 == s2) {
        std::cout << "s1 and s2 are equal" << std::endl;
    } else {
        std::cout << "s1 and s2 are not equal" << std::endl;
    }
    return 0;
}
