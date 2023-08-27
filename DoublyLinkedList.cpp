#include "DoublyLinkedList.h"

#include "DoublyLinkedList.h"
#include <iostream>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::pushFront(const T &value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::pushBack(const T &value)
{
    Node *newNode = new Node(value);
    if (!tail)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::deleteNodeAtPosition(int position)
{
}

template <typename T>
void DoublyLinkedList<T>::print() const
{
    Node *current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
int DoublyLinkedList<T>::getSize() const
{
    return size;
}

// Explicit instantiation for the supported types
template class DoublyLinkedList<int>;
