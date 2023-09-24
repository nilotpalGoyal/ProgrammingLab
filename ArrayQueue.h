#ifndef ARRQUEUE_H
#define ARRQUEUE_H

#include "DynArray.h"

template <typename T>
class ArrayQueue
{
private:
    DynArr<T> array;

public:
    // Constructor
    ArrayQueue();

    // Destructor
    ~ArrayQueue();

    // Enqueue an element to the back of the queue
    void enqueue(const T &val);

    // Dequeue an element from the front of the queue
    void dequeue();

    // Get the front element of the queue
    T &peek();

    // Check if the queue is empty
    bool isEmpty() const;

    // Get the size of the queue
    int getSize() const;
};

#include "ArrayQueue.cpp" // Include the source file for template implementation

#endif
