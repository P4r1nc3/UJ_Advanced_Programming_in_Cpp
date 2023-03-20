#include<iostream>

using namespace std;

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T>
T *max(T *a, T *b) {
    return ((*a) > (*b)) ? a : b;
}

template<typename T>
T max(T *data, size_t n) {
    T tmp = data[0];
    for (size_t i = 0; i < n; ++i) {
        if (data[i] > tmp) {
            tmp = data[i];
        }
    }

    return tmp;
}

template<>
char *max(char *a, char *b) {
    return (strcmp(a, b) > 0) ? a : b;
}

template<>
const char *max(const char *a, const char *b) {
    return (strcmp(a, b) > 0) ? a : b;
}

template<typename T>
const T *max(T *a, const T *b) {
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    int i = 5;
    int j = 5;

    double x[5] = {1, 2, 4, 0, 3};

    char *p1 = new char[5];
    char *p2 = new char[5];

    strncpy(p1,"testy",5);
    strncpy(p2,"asia",5);

    /// T max(T a, T b)
    auto r1 = std::max(i, j);
    cout << r1 << endl;

    /// T *max(T *a, T *b)
    auto r2 = max(&i, &j);
    cout << *r2 << endl;

    /// T max(T *data, size_t n)
    auto r3 = max(x, 5);
    cout << r3 << endl;

    /// const char *max(const char *a, const char *b)
    auto r4 = max("asia","ania");
    cout << r4 << endl;

    /// char *max(char *a, char *b)
    auto r5 = max(p1,p2);
    cout << r5 << endl;

    /// const T *max(T *a, const T *b)
    auto r6 = max(p1, "asia");
    cout << r6 << endl;

    return 0;
}