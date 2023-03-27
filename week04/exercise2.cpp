#include<iostream>

using namespace std;

template<typename T>
struct sum_traits;

template<>
struct sum_traits<char> {
    typedef int sum_type;

    [[maybe_unused]] static sum_type zero() { return 0; }
};

template<>
struct sum_traits<int> {
    typedef int sum_type;

    [[maybe_unused]] static sum_type zero() { return 0; }
};

template<>
struct sum_traits<float> {
    typedef double sum_type;

    [[maybe_unused]] static sum_type zero() { return 0.0; }
};

template<>
struct sum_traits<double> {
    typedef double sum_type;

    [[maybe_unused]] static sum_type zero() { return 0.0; }
};

template<typename T>
typename sum_traits<T>::sum_type sum(T *beg, T *end) {
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_traits<T>::zero();
    while (beg != end) {
        total += *beg;
        beg++;
    }
    return total;
}

int main() {

    char name[] = "Test123";
    auto length = strlen(name);
    cout << sum(name, &name[length]) << endl;

    int numbers[] = {1, 2, 3, 4};
    length = 4;
    cout << sum(numbers, &numbers[length]) << endl;

    float numbers2[] = {1.1, 2.2, 3.3, 4.5};
    length = 4;
    cout << sum(numbers2, &numbers2[length]) << endl;

    double numbers3[] = {1.1, 2.2, 3.3, 4.5};
    length = 4;
    cout << sum(numbers3, &numbers3[length]) << endl;

    return 0;
}