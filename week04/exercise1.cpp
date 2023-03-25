#include<iostream>

using namespace std;

template<typename T>
struct sum_traits;

template<>
struct sum_traits<char> {
    [[maybe_unused]] typedef int sum_type;
};
template<>
struct sum_traits<int> {
    [[maybe_unused]] typedef long int sum_type;
};
template<>
struct sum_traits<float> {
    [[maybe_unused]] typedef float sum_type;
};
template<>
struct sum_traits<double> {
    [[maybe_unused]] typedef double sum_type;
};

template<typename T>
typename sum_traits<T>::sum_type sum(T *beg, T *end) {
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_type();
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

    double numbers2[] = {1.1, 2.2, 3.3, 4.5};
    length = 4;
    cout << sum(numbers2, &numbers2[length]) << endl;

    return 0;
}