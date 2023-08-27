#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T val;
        Node<T> *prev;
        Node<T> *next;
        Node(const T &value) : val(value), prev(nullptr), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void pushFront(const T &value);
    void pushBack(const T &value);
    void deleteNodeAtPosition(int position);
    void print() const;
    int getSize() const;
};

#include "DoublyLinkedList.cpp"

#endif