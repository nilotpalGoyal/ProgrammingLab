#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

template <typename T>
class CLinkedList
{
private:
    Node<T> *head;

public:
    CLinkedList();

    // add node to the list ie back
    void add(T item);

    // add node to the front
    void addFront(T item);

    // add node at the given position
    void addPos(T item, int pos);

    // remove node from the back
    void rm();

    // remove node from the front
    void rmFront();

    // remove node from the given position
    void rmPos(int pos);

    // display the list
    void display();

    // calculate the length
    int length();
};

#include "CLinkedList.cpp"

#endif
