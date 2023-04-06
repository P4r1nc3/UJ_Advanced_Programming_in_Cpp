#include<vector>
#include<iostream>

using namespace std;

template<typename T>
class Is_class {

    typedef char first;
    typedef struct {
        char c[2];
    } second;

    template<typename U>
    static first test(int U::*);

    template<typename U>
    static second test(...);

public:
    enum {
        check = (sizeof(test<T>(nullptr)) == sizeof(first))
    };
};

class X {
};

int main() {

    cout << Is_class<int>::check << endl;
    cout << Is_class<X>::check << endl;
    cout << Is_class<std::vector<double> >::check << endl;

    return 0;
}