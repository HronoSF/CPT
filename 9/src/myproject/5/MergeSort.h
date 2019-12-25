#include <iostream>
#include <typeinfo>
#include <algorithm>

template<class Iterator>
void merge_sort(Iterator first, Iterator last) {
    if (last - first > 1) {
        Iterator middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}