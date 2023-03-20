#include<vector>
#include <iostream>

using namespace std;

template<typename T, int N = 100, typename R = T *>
class Stack;

template<typename T, int N>
class Stack<T, N, T *> {
    T _rep[N];
    unsigned int _top;
public:
    Stack() : _top(0) {};

    void push(T e) {
        _rep[_top++] = e;
    }

    T pop() {
        return _rep[--_top];
    }
};

template<typename T, int N, typename E>
class Stack {
    E _rep;
public:
    Stack() = default;

    void push(T e) {
        _rep.push_back(e);
    };

    T pop() {
        T top = _rep.back();
        _rep.pop_back();
        return top;
    }
};

int main() {
    Stack<int, 100, int *> s_table;
    Stack<int, 100> s_default;
    Stack<int, 0, vector<int> > s_container;

    s_container.push(100);
    cout << s_container.pop();

    return 0;
}