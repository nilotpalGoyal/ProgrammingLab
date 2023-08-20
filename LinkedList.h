#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

template <typename T>
class Node
{
public:
    T val;         // data inside the node
    Node<T> *next; // pointer to next node

public:
    // constructor
    Node()
    {
        this->next = NULL;
    }
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;

public:
    // constructor
    LinkedList()
    {
        head = NULL;
    }

    // add new node to back of the linkedlist
    void add(T item)
    {
        Node<T> *node = new Node<T>;
        node->val = item;

        if (head == NULL)
        {
            head = node;
            std::cout << "FIRST node added to list" << std::endl;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        std::cout << "node added at the back of list" << std::endl;
    }

    // add new node to front of the linkedlist
    void addFront(T item)
    {
        Node<T> *node = new Node<T>;
        node->val = item;

        if (head == NULL)
        {
            head = node;
            std::cout << "FIRST node added to list" << std::endl;
            return;
        }
        node->next = head;
        head = node;
        return;
    }

    // add new node at the given postion
    void addPos(T item, int pos)
    {

        if (pos > length())
        {
            std::cout << "out of bound!! Adding at the back of list.\n";
            add(item);
            return;
        }

        Node<T> *node = new Node<T>;
        node->val = item;

        Node<T> *temp = head;
        pos--;
        while (pos--)
        {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
        return;
    }

    // remove node from front
    void rmFront()
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    // remove node from back
    void rmBack()
    {
        Node<T> *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // remove at the given postion
    void rmPos(int pos)
    {
        if (pos > length())
        {
            std::cout << "out of bound!! Deleting from the back of the list.\n";
            rmBack();
            return;
        }
    }
    // search for the given item in linkedlist

    // traverse linkedlist and display
    void display()
    {
        if (head == NULL)
        {
            std::cout << "list is empty!!" << std::endl;
            return;
        }
        Node<T> *temp = head;

        while (temp != NULL)
        {
            std::cout << temp->val << ", ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // length of the linkedlist
    int length()
    {
        int len = 0;
        Node<T> *temp = head;

        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
};

#endif