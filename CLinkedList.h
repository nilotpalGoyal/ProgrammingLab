#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include <iostream>

template <typename T>
class CNode
{
public:
    T val;
    CNode<T> *next;

    CNode()
    {
        this->next = NULL;
    }
};

template <typename T>
class CLinkedList
{
private:
    CNode<T> *head;

public:
    CLinkedList()
    {
        this->head = NULL;
    }

    // add node to the list ie back
    void add(T item)
    {
        CNode<T> *node = new CNode<T>;
        node->val = item;

        if (head == NULL)
        {
            head = node;
            head->next = head;
            std::cout << "added first node.\n";
            return;
        }

        CNode<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
        std::cout << "added a node at the back\n";
    }

    // add node to the front
    void addFront(T item)
    {
        if (head == NULL)
        {
            add(item);
            return;
        }

        CNode<T> *node = new CNode<T>;
        node->val = item;

        CNode<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        node->next = head;
        temp->next = node;
        head = node;
    }

    // add node at the given position
    void addPos(T item, int pos)
    {
        if (head == NULL)
        {
            add(item);
            return;
        }

        CNode<T> *node = new CNode<T>;
        node->val = item;

        CNode<T> *temp = head;
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
    void rm()
    {
        CNode<T> *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = head;
    }

    // remove node from the front
    void rmFront()
    {
        if (length() == 1)
        {
            delete head;
            return;
        }

        CNode<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        CNode<T> *dummy = head;
        head = head->next;
        temp->next = head;
    }

    // remove node from the given position
    void rmPos(int pos)
    {
        if (pos > length())
        {
            std::cout << "out of bound!! deleting from the end of list.\n";
            rm();
            return;
        }

        CNode<T> *temp = head;
        while (--pos)
        {
            temp = temp->next;
        }
    }

    // display the list
    void display()
    {
        std::cout << head->val << " ";
        CNode<T> *temp = head->next;
        while (temp != head)
        {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // calculate the length
    int length()
    {
        int len = 0;
        CNode<T> *temp = head;
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
};

#endif