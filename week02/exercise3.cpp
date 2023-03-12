#include <list>
#include <iostream>

using namespace std;

template <typename Iterator, typename T>
T accumulate(Iterator first, Iterator last, T init) {
    for (; first != last; ++first) {
        init += *first;
    }
    return init;
}

int main() {

    list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    cout << accumulate(list.begin(), list.end(), 0) << endl;

    return 0;
}