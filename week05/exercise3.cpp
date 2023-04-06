#include<vector>
#include<iostream>

using namespace std;

template<typename T, typename U>
class Is_convertible {
    typedef char first;
    typedef struct {
        char c[2];
    } second;

    static first test(U);

    static second test(...);

    static T makeT();

public:
    enum {
        check = sizeof(test(makeT())) == sizeof(first),
        same_type = false
    };
};

template<typename T>
class Is_convertible<T, T> {
public:
    enum {
        check = true,
        same_type = true
    };
};

int main() {

    cout << Is_convertible<int, double>::check << endl;
    cout << Is_convertible<double, int>::check << endl;

    cout << Is_convertible<double, int>::same_type << endl;

    cout << Is_convertible<size_t, unsigned int>::same_type << endl;
    cout << Is_convertible<std::vector<double>::value_type, double>::same_type << endl;

    cout << Is_convertible<std::vector<double>::iterator, double *>::same_type << endl;

    return 0;
}