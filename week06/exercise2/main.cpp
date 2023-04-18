#include"stack.h"

int main() {

    /// no checking policy

    auto stack1 = Stack<int, 5>();
    stack1.pop();
    std::cout << "ok" << std::endl;

    /// abort on error policy

    auto stack2 = Stack<int, 5, Std_exception_on_error_policy>();
    stack2.pop();
    std::cout << "won't run because of error" << std::endl;

    return 0;
}