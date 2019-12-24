#pragma once
#include <iostream>
#include "MyMatrix.h"


template<class T>
inline MyMatrix<T>::MyMatrix() { matrixData = {}; }

template<class T>
inline MyMatrix<T>::MyMatrix(std::initializer_list<T> &&list) {
    for (const auto &element : list)
        matrixData.push_back(element);
}

template<class T>
inline MyMatrix<T>::MyMatrix(std::vector<T> vector) {
    this->set(vector);
}

template<class T>
MyMatrix<T> &MyMatrix<T>::operator=(const MyMatrix<T> &other) {
    if (this != &other) {
        matrixData.clear();
        for (auto &element : other.matrixData) {
            matrixData.push_back(element);
        }
    }
    return *this;
}

template<class T>
std::vector<bool> operator<(MyMatrix<T> &first, MyMatrix<T> &second) {
    std::vector<bool> result{};
    std::vector<T> firstData = first.getData();
    std::vector<T> secondData = second.getData();
    for (unsigned int i = 0; i < std::max(firstData.size(), secondData.size()); i++) {
        if (i < firstData.size() && i > secondData.size())
            result.push_back(true);
        else if (i > firstData.size() && i < secondData.size())
            result.push_back(false);
        else
            result.push_back(firstData.at(i) < secondData.at(i));
    }
    return result;
}

template<class T>
MyMatrix<T> operator<(MyMatrix<T> matrix, double eps) {
    MyMatrix<T> matrixLogic;
    std::vector<T> condition{};
    for (unsigned int i = 0; i < matrix.getData().size(); i++) {
        if (matrix.getData().at(i) < eps)
            condition.push_back(1);
        else
            condition.push_back(0);
    }
    matrixLogic.set(condition);
    return matrixLogic;
}

template<class T>
MyMatrix<T> operator-(MyMatrix<T> first, MyMatrix<T> second) {
    MyMatrix<T> other{};
    std::vector<T> vector{};
    for (unsigned int i = 0; i < first.getData().size(); i++)
        vector.push_back(first.getData().at(i) - second.getData().at(i));
    other.set(vector);
    return other;
}

template<class T>
void MyMatrix<T>::push_back(T element) { matrixData.push_back(element); }

template<class T>
std::vector<T> &MyMatrix<T>::getData() { return matrixData; }

template<class T>
void MyMatrix<T>::set(std::vector<T> &vector) {
    this->matrixData.clear();
    matrixData = vector;
}

template<class T>
void MyMatrix<T>::out() {
    for (const auto &element : matrixData) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

template<class T>
MyMatrix<T> MyMatrix<T>::transposed(const size_t n, const size_t m) {
    assert(n * m == matrixData.size());
    std::vector<T> other{};
    other.resize(n * m);
    for (size_t i = 0; i < n * m; ++i)
        other.at(i) = matrixData.at(n * (i % n) + (i / n));
    return other;
}

template<class T>
MyMatrix<T> where(std::vector<bool> comparisonResult, MyMatrix<T> &firstMatrix, MyMatrix<T> &secondMatrix) {
    MyMatrix<T> result{};
    std::vector<T> firstData = firstMatrix.getData();
    std::vector<T> secondData = secondMatrix.getData();
    for (unsigned int i = 0; i < comparisonResult.size(); ++i) {
        if (comparisonResult.at(i) == true)
            result.push_back(firstData.at(i));
        else
            result.push_back(secondData.at(i));
    }

    return result;
}

template<class T>
MyMatrix<T> abs(MyMatrix<T> matrix) {
    for (auto &element : matrix.getData()) {
        element = abs(element);
    }
    return matrix;
}

template<class T>
bool all(MyMatrix<T> matrix) {
    for (unsigned int i = 0; i < matrix.getData().size(); ++i) {
        if (matrix.getData().at(i) == 0)
            return 0;
    }
    return 1;
}

template<class T>
bool MyMatrix<T>::is_symmetric(double eps, const size_t n, const size_t m) {
    return all(abs(*this - this->transposed(n, m)) < eps);
}


