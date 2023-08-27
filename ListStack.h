#ifndef LISTSTACK_H
#define LISTSTACK_H

#include <iostream>
#include "LinkedList.h"

template <class T>
class ListStack
{
private:
    /* data */
    LinkedList<T> list;
    int size;

public:
    ListStack(/* args */);
    // ~ListStack();
    void push(T data);
    T top();
    void pop();
    int getsize();
};

template <typename T>
ListStack<T>::ListStack()
{
    size = 0;
}

template <typename T>
void ListStack<T>::push(T data)
{
    size++;
    list.addFront(data);
}

template <typename T>
T ListStack<T>::top()
{
    return list.getFrontval();
}

template <typename T>
void ListStack<T>::pop()
{
    list.rmFront();
    size--;
}

template <typename T>
int ListStack<T>::getsize()
{
    return list.length();
}

#endif