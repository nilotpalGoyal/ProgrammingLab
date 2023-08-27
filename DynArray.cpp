#include "DynArray.h"
#include <iostream>

template <typename T>
DynArr<T>::DynArr() : elements(nullptr), capacity(0), count(0) {}

template <typename T>
DynArr<T>::DynArr(int n, T value) : capacity(n), count(n)
{
    elements = (n == 0) ? nullptr : new T[n];
    for (int i = 0; i < n; i++)
    {
        elements[i] = value;
    }
}

template <typename T>
DynArr<T>::~DynArr()
{
    if (count == 0)
        delete[] elements;
}

template <typename T>
void DynArr<T>::expandCapacity()
{
    capacity = std::max(1, capacity * 2);
    T *array = new T[capacity];
    std::copy(elements, elements + count, array);
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
        std::cerr << "insert: index out of range" << std::endl;
        return;
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
T &DynArr<T>::front()
{
    if (count > 0)
    {
        return elements[0];
    }
    throw std::out_of_range("front: array is empty");
}

template <typename T>
const T &DynArr<T>::front() const
{
    if (count > 0)
    {
        return elements[0];
    }
    throw std::out_of_range("front: array is empty");
}

template <typename T>
T &DynArr<T>::back()
{
    if (count > 0)
    {
        return elements[count - 1];
    }
    throw std::out_of_range("back: array is empty");
}

template <typename T>
const T &DynArr<T>::back() const
{
    if (count > 0)
    {
        return elements[count - 1];
    }
    throw std::out_of_range("back: array is empty");
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
