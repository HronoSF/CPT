#include <iterator>
#include <vector>
#include <algorithm>
#include <thread>
#include <cmath>
#include <iostream>

template<class Iterator>
void merge_sort(Iterator first, Iterator last) {
    if (last - first > 1) {
        Iterator middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}


long merge_sort_consistent(std::vector<int> &vec) {
    auto start = std::chrono::system_clock::now();
    merge_sort(vec.begin(), vec.end());
    auto end = std::chrono::system_clock::now();
    std::chrono::milliseconds elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return elapsed.count();
}