#include<iostream>

using namespace std;

template<typename T, typename U>
T convert(U u) {
    return static_cast<T>(u);
}

template<>
int convert<int, double>(double u) {
    return static_cast<int>(u);
}

template<>
double convert<double, int>(int u) {
    return static_cast<double>(u);
}

int main() {

    /// convert<int, double>(double u)
    auto r1 = convert<int>(3.1415);
    cout << r1 << endl;

    /// double convert<double, double>(double u)
    auto r2 = convert<double>(3);
    cout << r2 << endl;

    return 0;
}