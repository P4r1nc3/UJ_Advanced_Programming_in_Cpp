#include<iostream>

using namespace std;

template<typename T, int N = 100>
class Stack {
public:
    Stack() = default;
};

template<typename T>
class Stack<T, 666> {
public:
    Stack() = default;
};

template<typename T, int N>
class Stack<T *, N> {
public:
    Stack() = default;
};

template<int N>
class Stack<double, N> {
public:
    Stack() = default;
};

template<int N>
class Stack<int *, N> {
public:
    Stack() = default;
};

template<>
class Stack<double, 666> {
public:
    Stack() = default;
};

template<>
class Stack<double *, 44> {
public:
    Stack() = default;
};

int main() {

    Stack<int, 666> s1;
    cout << typeid(s1).name() << endl;

    Stack<double *, 30> s2;
    cout << typeid(s2).name() << endl;

    Stack<double, 30> s3;
    cout << typeid(s3).name() << endl;

    Stack<int *, 20> s4;
    cout << typeid(s4).name() << endl;

    Stack<double, 666> s5;
    cout << typeid(s5).name() << endl;

    Stack<double *, 44> s6;
    cout << typeid(s6).name() << endl;

    return 0;
}