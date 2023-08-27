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
void DoublyLinkedList<T>::popFront()
{
    if (head)
    {
        Node *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
        size--;
    }
}

template <typename T>
void DoublyLinkedList<T>::popBack()
{
    if (tail)
    {
        Node *temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
        size--;
    }
}

template <typename T>
void DoublyLinkedList<T>::popAtPosition(int position)
{
    position--;
    if (position >= size)
    {
        if (tail)
        {
            Node *temp = tail;
            tail = tail->prev;
            if (tail)
                tail->next = nullptr;
            else
                head = nullptr; // List becomes empty
            delete temp;
            size--;
        }
    }
    else
    {
        if (position == 0)
        {
            Node *temp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            else
                tail = nullptr; // List becomes empty
            delete temp;
            size--;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < position; ++i)
                current = current->next;
            current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            else
                tail = current->prev;
            delete current;
            size--;
        }
    }
}

template <typename T>
void DoublyLinkedList<T>::print() const
{
    if (size == 0)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node *current = head;
    while (current)
    {
        std::cout << current->val << " ";
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
