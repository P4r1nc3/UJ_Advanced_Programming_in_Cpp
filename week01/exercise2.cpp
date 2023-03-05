#include <iostream>

using namespace std;

template<typename T, typename U>
T convert(U u) {
    return (T) u;
}

int main() {
    cout << convert<char>(65) << endl;
    cout << convert<int>('A') << endl;

    return 0;
}