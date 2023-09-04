#include "CLinkedList.h"

// CLinkedList constructor
template <typename T>
CLinkedList<T>::CLinkedList()
{
    this->head = NULL;
}

// add node to the list ie back
template <typename T>
void CLinkedList<T>::add(T item)
{
    Node<T> *node = new Node<T>;
    node->val = item;

    if (head == nullptr)
    {
        node->next = node;
        head = node;
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
}

// add node to the front
template <typename T>
void CLinkedList<T>::addFront(T item)
{
    Node<T> *node = new Node<T>;
    node->val = item;

    if (head == nullptr)
    {
        node->next = node;
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
    }
    head = node;
}

// add node at the given position
template <typename T>
void CLinkedList<T>::addPos(T item, int pos)
{
    if (head == NULL)
    {
        add(item);
        return;
    }

    Node<T> *node = new Node<T>;
    node->val = item;

    Node<T> *temp = head;
    if (pos > length())
    {
        add(item);
        return;
    }
    while (--pos)
    {
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;
}

// remove node from the back
template <typename T>
void CLinkedList<T>::rm()
{
    Node<T> *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = head;
}

// remove node from the front
template <typename T>
void CLinkedList<T>::rmFront()
{
    if (length() == 1)
    {
        delete head;
        return;
    }

    Node<T> *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    head = head->next;
    temp->next = head;
}

// remove node from the given position
template <typename T>
void CLinkedList<T>::rmPos(int pos)
{
    if (pos > length())
    {
        // std::cout << "out of bound!! deleting from the end of list.\n";
        rm();
        return;
    }

    Node<T> *temp = head;
    while (--pos)
    {
        temp = temp->next;
    }
}

// display the list
template <typename T>
void CLinkedList<T>::display()
{
    std::cout << head->val << " ";
    Node<T> *temp = head->next;
    while (temp != head)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// calculate the length
template <typename T>
int CLinkedList<T>::length()
{
    int len = 0;
    Node<T> *temp = head;
    if (temp->next == head)
        return 1;
    while (temp->next != head)
    {
        len++;
        temp = temp->next;
    }
    len++;
    return len;
}

template class CLinkedList<int>; // You can add more types if needed
