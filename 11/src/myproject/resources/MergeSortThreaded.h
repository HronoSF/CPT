#pragma once

#include <iterator>
#include <vector>
#include <algorithm>
#include <thread>
#include <cmath>
#include <iostream>
#include <mutex>
#include "../MyThread.hxx"

using namespace std::chrono;

#define THREAD_MAX std::thread::hardware_concurrency()

std::vector<my_thread> threads{THREAD_MAX};

template<typename T>
int merge_sort_in_threads(T first, T last) {
    int size = std::distance(first, last);

    if (first == last || size == 1) {
        return (0);
    }

    T middle = std::next(first, size / 2);

    unsigned int i = THREAD_MAX;
    unsigned int j = THREAD_MAX;

    if (size >= 100) {
        i = 0;
        while (i < THREAD_MAX) {
            if (!threads[i].joinable()) {
                threads[i] = my_thread([first, middle]() { return merge_sort_in_threads(first, middle); });
                break;
            }
            i++;
        }
        j = 0;
        while (j < THREAD_MAX) {
            if (!threads[j].joinable()) {
                threads[j] = my_thread([middle, last]() { return merge_sort_in_threads(middle, last); });
                break;
            }
            j++;
        }
    }


    if (i == THREAD_MAX) {
        merge_sort_in_threads(first, middle);
    }
    if (j == THREAD_MAX) {
        merge_sort_in_threads(middle, last);
    }
    if (i < THREAD_MAX) {
        threads[i].join();
    }
    if (j < THREAD_MAX) {
        threads[j].join();
    }

    std::inplace_merge(first, middle, last);
    return (0);
}

long merge_sort_in_threads(std::vector<int> &vec) {
    auto start = system_clock::now();

    merge_sort_in_threads(vec.begin(), vec.end());

    auto end = system_clock::now();
    milliseconds elapsed = duration_cast<milliseconds>(end - start);
    return elapsed.count();
}

