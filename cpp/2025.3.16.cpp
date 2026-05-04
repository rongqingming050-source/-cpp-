#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(string a, string b) : name(a), sex(b) {}

protected:
    string name, sex;
};

class Student : virtual public Person {
public:
    Student(string a, string b, string c, int d) : Person(a, b), no(c), score(d) {}

protected:
    string no;
    int score;
};

class Employee : virtual public Person {
public:
    Employee(string a, string b, int f) : Person(a, b), salary(f) {}

protected:
    int salary;
};

class Ustudent : public Student {
public:
    Ustudent(string a, string b, string c, int d, string e)
        : Person(a, b), Student(a, b, c, d), major(e) {}

protected:
    string major;
};

class E_Ustudent : public Student, public Employee {
public:
    E_Ustudent(string a, string b, string c, int d, string e, int f)
        : Person(b, c), Student(b, c, a, d), Employee(b, c, f), major(e) {}

    void show() {
        cout << "学号: " << no << endl;
        cout << "姓名: " << name << endl;
        cout << "性别: " << sex << endl;
        cout << "成绩: " << score << endl;
        cout << "专业: " << major << endl;
        cout << "工资: " << salary << endl;
    }

protected:
    string major;
};

int main() {
    E_Ustudent s("2024213889", "zs", "man", 90, "math", 8500);
    s.show();
    return 0;
}

