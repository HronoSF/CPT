#pragma once

#include <iterator>
#include <vector>
#include <algorithm>
#include <thread>
#include <cmath>
#include <iostream>
#include <mutex>
#include "../myproject/resources/MergeSort.h"

using namespace std::chrono;

#define THREAD_MAX std::thread::hardware_concurrency()

std::vector<std::thread> threads{THREAD_MAX};

std::mutex mutex;

template<typename T>
void merge_sort_in_threads(T first, T last) {

    int size = std::distance(first, last);

    if (first == last || size == 1) {
        return;
    }

    T middle = std::next(first, size / 2);

    unsigned int i = THREAD_MAX;
    unsigned int j = THREAD_MAX;

    if (size >= 100) {
        std::lock_guard<std::mutex> locked(mutex);
        i = 0;
        while (i < THREAD_MAX) {
            if (!threads[i].joinable()) {
                threads[i] = std::thread{merge_sort_in_threads<T>, first, middle};
                break;
            }
            i++;
        }
        j = 0;
        while (j < THREAD_MAX) {
            if (!threads[j].joinable()) {
                threads[j] = std::thread{merge_sort_in_threads<T>, middle, last};
                break;
            }
            j++;
        }
    }
    (i == THREAD_MAX) ? merge_sort_in_threads(first, middle) : threads[i].join();
    (j == THREAD_MAX) ? merge_sort_in_threads(middle, last) : threads[j].join();
    std::inplace_merge(first, middle, last);
}


long merge_sort_in_threads(std::vector<int> &vec) {
    auto start = system_clock::now();
    merge_sort_in_threads(vec.begin(), vec.end());
    auto end = system_clock::now();
    milliseconds elapsed = duration_cast<milliseconds>(end - start);
    return elapsed.count();
}


long merge_sort_consistent(std::vector<int> &vec) {
    auto start = system_clock::now();
    merge_sort(vec.begin(), vec.end());
    auto end = system_clock::now();
    milliseconds elapsed = duration_cast<milliseconds>(end - start);
    return elapsed.count();
}
