#include <iostream>
#include <stack>

using namespace std;

template<typename T>
using Stack = stack<T>;

template<typename T>
using value_type = typename Stack<T>::value_type;

template<typename T>
value_type<T> sum(const Stack<T>& s) {
    value_type<T> result{};
    auto temp = s;
    while (!temp.empty()) {
        result += temp.top();
        temp.pop();
    }
    return result;
}

int main() {
    Stack<int> stack;
    for (int i = 0; i <= 5; i++) {
        stack.push(i);
    }

    auto result = sum(stack);
    cout << "Sum: " << result << endl;

    return 0;
}