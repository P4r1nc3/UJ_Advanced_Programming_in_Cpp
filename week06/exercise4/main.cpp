#include "checking_policy.h"
#include "stack.h"

int main() {

    Stack<int,2,Std_exception_on_error_policy,Dynamic_table_allocator > s(2);
    s.resize(4);

    s.push(1);
    s.push(2);
    s.push(3);

    return 0;
}
