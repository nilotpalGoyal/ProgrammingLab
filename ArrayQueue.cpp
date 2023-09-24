#include "ArrayQueue.h"

template <typename T>
ArrayQueue<T>::ArrayQueue() {}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {}

template <typename T>
void ArrayQueue<T>::enqueue(const T &val)
{
    array.pushBack(val);
}

template <typename T>
void ArrayQueue<T>::dequeue()
{
    if (!isEmpty())
    {
        array.remove(0);
    }
}

template <typename T>
T &ArrayQueue<T>::peek()
{
    if (!isEmpty())
    {
        return array.front();
    }
    throw std::runtime_error("Queue is empty");
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const
{
    return array.size() == 0;
}

template <typename T>
int ArrayQueue<T>::getSize() const
{
    return array.size();
}
