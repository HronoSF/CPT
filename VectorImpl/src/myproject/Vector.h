#pragma once

template<class TYPE>
class Vector {
public:
    typedef TYPE* iterator;
    // CONSTRUCTORS:
    Vector();  // default constructor
    explicit Vector(const int size); // constructor with initial size
    Vector(const TYPE &init, const int size);  // constructor with initial element and initial size
    Vector(const Vector<TYPE> &other); // copy constructor
    Vector(Vector<TYPE> &&other) noexcept; // move constructor
    // DESTRUCTORS:
    ~Vector();
    // OVERLOADED OPERATORS:
    Vector<TYPE> &operator=(const Vector<TYPE> &otherVector);  // copy operator
    Vector<TYPE> &operator=(Vector<TYPE> &&otherVector) noexcept ; // move operator
    // STAFF METHODS:
    unsigned int capacity() const;
    unsigned int size() const;
    void grow(int reserve);
    // METHODS:
    void push_back(TYPE &value);
    void push_back(TYPE &&value);
    void pop_back();
    void clear();
    void swap(Vector<TYPE> & other);
    TYPE& front();
    TYPE& back();
    // ITERATOR:
    iterator begin();
    iterator end();
    iterator erase(iterator position);
private:
    TYPE *elementData;
    int __capacity;
    int __size;
    const int DEFAULT_CAPACITY = 16;
    void ensureCapacity();
};

#include "Vector.hxx"
