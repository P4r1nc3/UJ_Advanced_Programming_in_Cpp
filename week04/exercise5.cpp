#include <list>
#include <iostream>
#include <iterator>


using namespace std;
template<typename Iter>
int perform(Iter i, random_access_iterator_tag) {
    cout << "random-access iterator\n";
    return 1;
}

template<typename Iter>
int perform(Iter i, forward_iterator_tag) {
    cout << "one-directional iterator\n";
    return 2;
}

template<typename Iter>
int perform(Iter i, bidirectional_iterator_tag) {
    cout << "bidirectional iterator\n";
    return 3;
}

template<typename Iter>
inline int operation(Iter i) {
    return perform(i, typename iterator_traits<Iter>::iterator_category());
}


int main() {
    list<int> l;
    operation(l.begin());

    int t[3];
    operation(t);

    return 0;
}