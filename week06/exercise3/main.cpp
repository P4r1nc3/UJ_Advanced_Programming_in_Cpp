#include "checking_policy.h"
#include "stack.h"

int main() {

    Stack<int,1,Abort_on_error_policy,Expandable_new_allocator > s1(1);
    Stack<int,1,Std_exception_on_error_policy,Dynamic_table_allocator > s2(1);

    s1.push(0);
    s1.push(1);
    std::cout << "ok" << std::endl;

    s2.push(0);
    s2.push(1);
    std::cout << "won't run due to error" << std::endl;

    return 0;
}