#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <iostream>

template <typename T>
class DynArr
{
private:
    T *elements;
    int capacity;
    int count;

    // private methods
    void expandCapacity();

public:
    DynArr();
    DynArr(int, T);

    // Destructor
    ~DynArr();

    // Overloads [] to select elements from this vector.
    T &operator[](int);

    void insert(int, T);
    void remove(int);
    void pushBack(T);
    int size() const;

    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
};

#include "DynArray.cpp"

#endif