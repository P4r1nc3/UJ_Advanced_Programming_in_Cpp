#include<iostream>

using namespace std;
template<typename T>
struct sum_traits;

template<>
struct sum_traits<char> {
    typedef int sum_type;
};
template<>
struct sum_traits<int> {
    typedef long int sum_type;
};
template<>
struct sum_traits<float> {
    typedef double sum_type;
};
template<>
struct sum_traits<double> {
    typedef double sum_type;
};

template<typename Traits, typename T>
typename Traits::sum_type sum(T *beg, T *end) {
    typedef typename Traits::sum_type sum_type;
    sum_type total = sum_type();
    while (beg != end) {
        total += *beg;
        beg++;
    }
    return total;
};

template<typename T>
typename sum_traits<T>::sum_type sum(T *beg, T *end) {
    return sum<sum_traits<T>, T>(beg, end);
}

struct char_sum {
    [[maybe_unused]] typedef char sum_type;
};

int main() {

    char name[] = "Test123";
    auto length = strlen(name);
    cout << (int) sum(name, &name[length]) << endl;
    cout << (int) sum<char_sum>(name, &name[length]) << endl;
    cout << (int) sum<char>(name, &name[length]) << endl;

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