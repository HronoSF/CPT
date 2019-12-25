#pragma once

#include <iterator>
#include <vector>
#include <algorithm>
#include <thread>
#include <math.h>
#include <iostream>



using namespace std;
using namespace std::chrono;

int threadCount = std::thread::hardware_concurrency();
int maxDepth = floor(log(threadCount) / log(2));

void MergeSortInThreads(std::vector<int>::iterator first, std::vector<int>::iterator last, int depth) {
    if (last - first > 1) {

        auto middle = first + (last - first) / 2;

        if (depth < maxDepth) {
            thread t1 = thread(MergeSortInThreads, first, middle, depth + 1);
            thread t2 = thread(MergeSortInThreads, middle, last, depth + 1);
            t1.join();
            t2.join();
        } else {
            MergeSortInThreads(first, middle, depth + 1);
            MergeSortInThreads(middle, last, depth + 1);
        }
        std::inplace_merge(first, middle, last);
    }
}

void MergeSortConsistent(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    if (last - first > 1) {

        auto middle = first + (last - first) / 2;

        MergeSortConsistent(first, middle);
        MergeSortConsistent(middle, last);

        std::inplace_merge(first, middle, last);
    }
}

long MergeSortInThreads(std::vector<int> &vec) {
    auto start = system_clock::now();
    MergeSortInThreads(vec.begin(), vec.end(), 1);
    auto end = system_clock::now();
    milliseconds elapsed = duration_cast<milliseconds>(end - start);
    return elapsed.count();
}

long MergeSortConsistent(std::vector<int> &vec) {
    auto start = system_clock::now();
    MergeSortConsistent(vec.begin(), vec.end());
    auto end = system_clock::now();
    milliseconds elapsed = duration_cast<milliseconds>(end - start);
    return elapsed.count();
}