#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class SequenceGen {
private:
    T _start;
    T _step;
public:
    SequenceGen(T start = T(),T step = 1 ):
            _start(start),_step(step){};

    T operator()() {T tmp=_start; _start+=_step; return tmp;}
};

int main() {
    std::vector<int> numbers(20);
    SequenceGen<int> gen(1, 2);
    std::generate_n(numbers.begin(), numbers.size(), gen);

    auto it = std::find_if(numbers.begin(), numbers.end(), std::bind2nd(std::greater<int>(), 4));
    if (it != numbers.end()) {
        std::cout << "Element greater than 4: " << *it << std::endl;
    } else {
        std::cout << "No element greater than 4 found" << std::endl;
    }

    return 0;
}