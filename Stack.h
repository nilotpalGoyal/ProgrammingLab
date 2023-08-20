#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"

template <class T>
class Stack
{
private:
    /* data */
    LinkedList<T> *top;

public:
    Stack(/* args */);
    ~Stack();
};

template <typename T>
Stack<T>::Stack() {}

#endif