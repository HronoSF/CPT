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
    __size = size;
    __capacity = size + size / 3 + 1;
    elementData = new TYPE[__capacity];
    for (int i = 0; i < __size; i++) {
        elementData[i] = init;
    }
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

template<class TYPE>
Vector<TYPE>::Vector(Vector<TYPE> &&otherVector) noexcept {
    swap(otherVector);
}

template<class TYPE>
Vector<TYPE> &Vector<TYPE>::operator=(const Vector<TYPE> &otherVector) {
    delete elementData;
    __capacity = otherVector._capacity;
    __size = otherVector.__size;
    memcpy(this->elementData, otherVector.elementData, this->__capacity);
    return *this;
}

template<class TYPE>
Vector<TYPE> &Vector<TYPE>::operator=(Vector<TYPE> &&otherVector) noexcept {
    swap(otherVector);
    return *this;
}

template<class TYPE>
Vector<TYPE>::~Vector() {
    delete[] elementData;
}

template<class TYPE>
void Vector<TYPE>::push_back(TYPE &value) {
    ensureCapacity();
    elementData[__size++] = value;
}

template<class TYPE>
void Vector<TYPE>::push_back(TYPE &&value) {
    ensureCapacity();
    elementData[__size++] = std::move(value);
}


template<class TYPE>
void Vector<TYPE>::grow(int reserve) {
    if (reserve < __capacity) {
        return;
    }
    TYPE *tmp_elementData = new TYPE[reserve];
    memmove(tmp_elementData, elementData, __size);
    __capacity = reserve;
    delete[] elementData;
    elementData = tmp_elementData;
}

template<class TYPE>
void Vector<TYPE>::pop_back() {
    erase(end());
}

template<class TYPE>
void Vector<TYPE>::clear() {
    __capacity = 0;
    __size = 0;
    delete[] elementData;
}

template<typename T>
void Vector<T>::swap(Vector<T> &other) {
    using std::swap;
    swap(this->__size, other.__size);
    swap(this->__capacity, other.__capacity);
    swap(this->elementData, other.elementData);
}

template<typename TYPE>
void Vector<TYPE>::ensureCapacity() {
    if (__size >= __capacity) {
        grow(__capacity + __capacity / 3 + 1);
    }
}

template<class TYPE>
unsigned int Vector<TYPE>::capacity() const { return __capacity; }

template<class TYPE>
unsigned int Vector<TYPE>::size() const { return __size; }

template<class TYPE>
typename Vector<TYPE>::iterator Vector<TYPE>::begin() { return elementData; }

template<class TYPE>
typename Vector<TYPE>::iterator Vector<TYPE>::end() { return (elementData + __size); }

template<typename TYPE>
typename Vector<TYPE>::iterator Vector<TYPE>::erase(iterator position) {
    iterator iter = &elementData[position - elementData];
    iter->~TYPE();
    memmove(iter, iter + 1, (__size - (iter - elementData)) * sizeof(TYPE));
    __size -= 1;
    return iter;
}

template<typename TYPE>
typename Vector<TYPE>::iterator Vector<TYPE>::erase(iterator first, iterator last) {
    int size = last - first;
    iterator iter_first = &elementData[first - elementData];
    iterator iter_last = iter_first + size;
    if (size == 0) {
        return iter_first;
    }
    for (int i = 0; i < size; i++) {
        first++->~TYPE();
    }
    memmove(iter_first, iter_last, (__size - (iter_last - elementData)) * sizeof(TYPE));
    __size -= size;
    return iter_first;
}

template<class TYPE>
TYPE &Vector<TYPE>::front() { return elementData[0]; }

template<class TYPE>
TYPE &Vector<TYPE>::back() { return elementData[__size - 1]; }

template<class T>
void swap(Vector<T> &firstVector, Vector<T> &secondVector) {
    firstVector.swap(secondVector);
}



