#include <iostream>

using namespace std;

template<typename T>
T maksimum(T a, T b) {
    return a < b ? b : a;
}

int main() {
    int x = 5, y = 20;
    cout << "Maksimum (" << x << ", " << y << ") = " << maksimum(x, y) << endl;

    double p = 3.1415, q = 1.41;
    cout << "Maksimum (" << p << ", " << q << ") = " << maksimum(p, q) << endl;

    string s1 = "Hello", s2 = "World";
    cout << "Maksimum (" << s1 << ", " << s2 << ") = " << maksimum(s1, s2) << endl;

    return 0;
}
