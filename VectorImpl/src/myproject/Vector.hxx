#pragma once

#include <cstddef>
#include <iostream>
#include <cstring>
#include "Vector.h"

template<class TYPE>
Vector<TYPE>::Vector() {
    __size = 0;
    __capacity = DEFAULT_CAPACITY;
    elementData = new TYPE[this->__capacity];
}

template<class TYPE>
Vector<TYPE>::Vector(const int size) {
    __capacity = size;
    __size = size;
    elementData = new TYPE[__size];
}


template<class TYPE>
Vector<TYPE>::Vector(const TYPE &init, const int size) {
    __capacity = size;
    __size = size;
    elementData = new TYPE[__size];
    elementData[0] = init;
}

template<class T>
Vector<T>::Vector(const Vector<T> &otherVector) {
    __capacity = otherVector.capacity();
    __size = otherVector.size();
    elementData = new T[__capacity];
    for (int i = 0; i < __size; ++i) {
        elementData[i] = otherVector.elementData[i];
    }
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &otherVector) {
    if (&otherVector == this) {
        return *this;
    }
    // deallocate previous
    delete[] elementData;
    // allocate continuous block of memory with new Vector
    __capacity = otherVector.capacity();
    __size = otherVector.size();

    elementData = new T[__capacity];
    for (int i = 0; i < __size; ++i) {
        elementData[i] = otherVector.elementData[i];
    }
    return *this;
}

template<class T>
Vector<T>::Vector(Vector<T> &&otherVector) noexcept {
    __capacity = otherVector.capacity();
    __size = otherVector.size();
    elementData = otherVector.elementData;
    finalize(otherVector);
}

template<class T>
Vector<T> &Vector<T>::operator=(Vector<T> &&otherVector) noexcept {
    if (&otherVector == this) {
        return *this;
    }
    // deallocate previous
    delete[] elementData;
    // allocate continuous block of memory with new Vector
    __capacity = otherVector.capacity();
    __size = otherVector.size();
    elementData = otherVector.elementData;
    // destroy previous object
    finalize(otherVector);
    return *this;
}

template<class TYPE>
Vector<TYPE>::~Vector() {
    delete[] elementData;
}

template<class TYPE>
void Vector<TYPE>::push_back(const TYPE &value) {
    if (__size >= __capacity) { grow(__capacity + 1); }
    if (elementData == 0) {
        elementData = new TYPE[__capacity];
    }
    elementData[__size++] = value;
}

template<class TYPE>
void Vector<TYPE>::grow(int reserve) {
    if (reserve < __capacity) {
        return;
    }
    TYPE *tmp_elementData = new TYPE[reserve];
    for (int i = 0; i < __size; ++i) {
        tmp_elementData[i] = elementData[i];
    }
    __capacity = reserve;
    delete[] elementData;
    elementData = tmp_elementData;
}

template<class TYPE>
void Vector<TYPE>::resize(unsigned int size) {
    grow(size);
    __size = size;
}

template<class TYPE>
TYPE Vector<TYPE>::pop_back() {
    __size--;
    return elementData[__size];
}

template<class TYPE>
void Vector<TYPE>::erase() {
    __capacity = 0;
    __size = 0;
    elementData = 0;
}

template<class TYPE>
void Vector<TYPE>::swap(Vector<TYPE> &other) {
    std::swap<Vector<TYPE>>((*this), other);
}

template<class TYPE>
unsigned int Vector<TYPE>::capacity() const { return __capacity; }

template<class TYPE>
unsigned int Vector<TYPE>::size() const { return __size; }

template<class TYPE>
typename Vector<TYPE>::iterator Vector<TYPE>::begin() { return elementData; }

template<class TYPE>
typename Vector<TYPE>::iterator Vector<TYPE>::end() { return (elementData + __size); }

template<class TYPE>
TYPE &Vector<TYPE>::front() { return elementData[0]; }

template<class TYPE>
TYPE &Vector<TYPE>::back() { return elementData[__size - 1]; }

template<class TYPE>
void Vector<TYPE>::finalize(Vector<TYPE> &targetVector) {
    __capacity = 0;
    __size = 0;
    delete[] elementData;
}


