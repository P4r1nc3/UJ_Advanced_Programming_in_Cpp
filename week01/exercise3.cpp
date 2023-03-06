#include <iostream>

using namespace std;

template<size_t N, typename T>
T dot_product(T *a, T *b) {
    T total = 0.0;
    for (size_t i = 0; i < N; ++i) {
        total += a[i] * b[i];
    }

    return total;
}

int main() {
    int vector1[] = {1, 2, 3};
    int vector2[] = {4, 5, 6};

    cout << "Dot product: " << dot_product<3>(vector1,vector2) << endl;

    return 0;
}