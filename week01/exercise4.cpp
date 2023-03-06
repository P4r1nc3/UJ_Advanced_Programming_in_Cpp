#include <iostream>

using namespace std;

template< template<int> class C, int K>
void f(C<K>) {
    cout << K << endl;
}

template<int> class ClassName {};

int main() {
    ClassName<1>  example1;
    ClassName<2>  example2;

    f(example1);
    f(example2);

    return 0;
}