#pragma once
#include <vector>


template <class T>
class MyMatrix {
private:
    std::vector<T> matrixData;
public:
    MyMatrix();
    MyMatrix(std::initializer_list<T>&& list);
    MyMatrix(std::vector<T> vector);
    MyMatrix& operator=(const MyMatrix& other);
    void push_back(T element);
    std::vector<T>& getData();
    void set(std::vector<T>& vector);
    void out();
    bool is_symmetric(double eps = 1e-5, size_t n = 4, size_t m = 4);
    MyMatrix transposed(size_t n = 3, size_t m = 3);
};


#include "MyMatrix.hxx"