#include <iostream>
#include <set>

using namespace std;
template<typename Iter>
void reversePrint(Iter a, Iter b) {
    while (a != b) {
        cout << *a << " ";
        ++a;
    }
}

int main() {
    set<int, std::greater<>> s;

    s.insert(3);
    s.insert(5);
    s.insert(7);
    s.insert(11);

    reversePrint(s.begin(), s.end());

    return 0;
}