#include <iostream>
#include <vector>
#include "Iterator.h"
#include "MergeSort.h"

int main() {
    my_iterator<int> itr(std::cout, 2);
    std::vector<int> vec;

    for (int i = 9; i >= 0; i--) {
        std::cout << i << std::endl;
        vec.push_back(i);
    }

    auto pointer = vec.begin();

    while (pointer != vec.end()) {
        *itr = *pointer;
        itr++;
        pointer++;
    }
    std::cout << *vec.begin() << " " << *vec.end() << std::endl;
    merge_sort(vec.begin(), vec.end());

    for (int x: vec)
        std::cout << x;
    return 0;
}