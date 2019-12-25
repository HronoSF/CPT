#include <iostream>
#include <vector>
#include <cstdlib>
#include "MergeSort.h"
#include "resources/matplotlibcpp.h"


namespace plt = matplotlibcpp;

int main() {
    std::vector<long> yGraphicMultiThreading, yGraphicConsistent, xGraphics;
    for (int size = 10; size < 1000000; size *= 5) {
        vector<int> vector(size);
        for (int i = 0; i < size; i++) {
            vector[i] = rand();
        }
        xGraphics.push_back(size);
        yGraphicMultiThreading.push_back(MergeSortInThreads(vector));
        yGraphicConsistent.push_back(MergeSortConsistent(vector));
    }

    plt::named_plot("Merge sort with Multithreading (ms)", xGraphics, yGraphicMultiThreading);
    plt::named_plot("Merge sort Consistent (ms)", xGraphics, yGraphicConsistent );
    plt::legend();
    plt::show();

    return 0;
}

