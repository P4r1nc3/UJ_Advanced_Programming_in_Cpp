#include<vector>
#include<iostream>

using namespace std;

template<typename T>
class has_value_type {
    typedef char one;
    typedef struct {
        char c[2];
    } two;

    template<typename U>
    static one test(typename U::value_type);

    template<typename U>
    static two test(...);

public:
    enum {
        check = (sizeof(test<T>(0)) == sizeof(one))
    };
};


class X {
};

int main() {

    cout << has_value_type<int>::check << endl;
    cout << has_value_type<X>::check << endl;
    cout << has_value_type<std::vector<double> >::check << endl;

    return 0;
}