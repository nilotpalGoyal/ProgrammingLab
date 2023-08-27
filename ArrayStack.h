#ifndef STACKUSINGDYNARR_H
#define STACKUSINGDYNARR_H

#include "DynArray.h"

template <typename T>
class Stack
{
private:
    DynArr<T> dynArray; // Use the extended DynArr class as the underlying container

public:
    // Push an element onto the stack
    void push(T value)
    {
        dynArray.pushBack(value);
    }

    // Pop an element from the stack
    void pop()
    {
        if (!isEmpty())
        {
            dynArray.remove(dynArray.size() - 1);
        }
        else
        {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    // Get the top element of the stack
    T top() const
    {
        if (!isEmpty())
        {
            return dynArray.back();
        }
        else
        {
            std::cerr << "Stack is empty. Cannot retrieve top." << std::endl;
            return T(); // Return a default-constructed value
        }
    }

    // Check if the stack is empty
    bool isEmpty() const
    {
        return dynArray.size() == 0;
    }

    // Get the number of elements in the stack
    int size() const
    {
        return dynArray.size();
    }
};

#endif