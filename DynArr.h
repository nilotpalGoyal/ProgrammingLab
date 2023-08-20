#ifndef DYNARR_H
#define DYNARR_H

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

    // Overloads [] to select elements from this vector.
    T &operator[](int);

    void insert(int, T);
    void remove(int);
    void pushBack(T);
    int size() const;
};

template <typename T>
DynArr<T>::DynArr()
{
    count = capacity = 0;
    elements = NULL;
}

template <typename T>
DynArr<T>::DynArr(int n, T value)
{
    count = capacity = n;
    elements = (n == 0) ? NULL : new T[n];
    for (int i = 0; i < n; i++)
    {
        elements[i] = value;
    }
}

template <typename T>
void DynArr<T>::expandCapacity()
{
    capacity = std::max(1, capacity * 2);
    T *array = new T[capacity];
    for (int i = 0; i < count; i++)
    {
        array[i] = elements[i];
    }
    if (elements != NULL)
        delete[] elements;
    elements = array;
}

template <typename T>
void DynArr<T>::insert(int index, T value)
{
    if (count == capacity)
        expandCapacity();
    if (index < 0 || index > count)
    {
        perror("insert: index out of range");
    }
    for (int i = count; i > index; i--)
    {
        elements[i] = elements[i - 1];
    }
    elements[index] = value;
    count++;
}

template <typename T>
void DynArr<T>::remove(int index)
{
    if (index < 0 || index >= count)
        perror("remove: index out of range");
    for (int i = index; i < count - 1; i++)
    {
        elements[i] = elements[i + 1];
    }
    count--;
}

template <typename T>
void DynArr<T>::pushBack(T value)
{
    insert(count, value);
}

template <typename T>
int DynArr<T>::size() const
{
    return count;
}

template <typename T>
T &DynArr<T>::operator[](int index)
{
    if (index < 0 || index >= count)
        perror("Selection index out of range");
    return elements[index];
}

#endif