#ifndef DYNAMICARRAY2D_H
#define DYNAMICARRAY2D_H

#include "DynArray.h"

template <typename T>
class Dynamic2DArray
{
private:
    DynArr<DynArr<T>> array2D; // 2D dynamic array

public:
    // Constructor to create a 2D dynamic array with 'rows' rows and 'cols' columns
    Dynamic2DArray();
    Dynamic2DArray(int rows, int cols, T value = T());

    DynArr<T> &operator[](int row);
    const DynArr<T> &operator[](int row) const;

    int getSize() const;

    // Access element at row 'row' and column 'col'
    // T &at(int row, int col);

    // Get the number of rows in the array
    // int numRows() const;

    // Get the number of columns in the array
    // int numCols() const;
};

#include "DynArray2D.cpp"

#endif
