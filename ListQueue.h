#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <typename T>
class Queue
{
private:
    LinkedList<T> list;

public:
    // Constructor
    Queue() {}

    // Enqueue an element to the back of the queue
    void enqueue(const T &val)
    {
        list.add(val); // Add to the back of the linked list
    }

    // Dequeue an element from the front of the queue
    void dequeue()
    {
        if (!isEmpty())
        {
            list.rmFront(); // Remove the front element from the linked list
        }
    }

    // Get the front element of the queue
    T peek()
    {
        if (!isEmpty())
        {
            return list.getFrontval();
        }
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return list.length() == 0;
    }

    // Get the size of the queue
    int getSize() const
    {
        return list.length();
    }
};

#endif
