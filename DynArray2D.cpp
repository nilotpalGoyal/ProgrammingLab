#include "DynArray2D.h"
#include <iostream>

template <typename T>
Dynamic2DArray<T>::Dynamic2DArray() {}

template <typename T>
Dynamic2DArray<T>::Dynamic2DArray(int rows, int cols, T value) : array2D(rows, DynArr<T>(cols, value)) {}

template <typename T>
DynArr<T> &Dynamic2DArray<T>::operator[](int row)
{
    return array2D[row];
}

template <typename T>
const DynArr<T> &Dynamic2DArray<T>::operator[](int row) const
{
    return array2D[row];
}

template <typename T>
int Dynamic2DArray<T>::getSize() const
{
    return array2D.size();
}