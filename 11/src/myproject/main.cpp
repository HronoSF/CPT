#include <vector>
#include <cstdlib>

#include "resources/matplotlibcpp.h"
#include "resources/MergeSortThreaded.h"
#include "resources/MergeSort.h"

namespace plt = matplotlibcpp;

int main() {
    std::vector<long> yGraphicMultiThreading, yGraphicConsistent, xGraphics;

    for (int size = 10; size < 10000000; size *= 10) {

        std::vector<int> vector(size);

        for (int i = 0; i < size; i++) {
            vector[i] = rand();
        }

        xGraphics.push_back(size);
        yGraphicMultiThreading.push_back(merge_sort_in_threads(vector));
        yGraphicConsistent.push_back(merge_sort_consistent(vector));
    }

    plt::named_plot("Merge sort with Multithreading (ms)", xGraphics, yGraphicMultiThreading);
    plt::named_plot("Merge sort Consistent (ms)", xGraphics, yGraphicConsistent);
    plt::xlabel("Count of elements in array");
    plt::ylabel("Time to sort in ms");
    plt::legend();
    plt::show();

    return 0;
}
