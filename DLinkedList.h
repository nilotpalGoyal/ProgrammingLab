#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <iostream>

template <typename T>
class DNode
{
public:
    T val;
    DNode<T> *prev;
    DNode<T> *next;

    // constructor
    DNode()
    {
        this->prev = NULL;
        this->next = NULL;
    }
};

template <typename T>
class DLinkedList
{
private:
    DNode<T> *head;

public:
    DLinkedList()
    {
        this->head = NULL;
    };

    // add new node at the back of list
    void add(T item)
    {
        DNode<T> *node = new DNode<T>;
        node->val = item;
        if (head == NULL)
        {
            head = node;
            std::cout << "First node added to the list.\n";
            return;
        }

        DNode<T> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node->prev = temp;
        temp->next = node;
        std::cout << "Node addedat the back of the list.\n";
    }

    // add new node at the front of list
    void addFront(T item)
    {
        DNode<T> *node = new DNode<T>;
        node->val = item;
        head->prev = node;
        node->next = head;
        head = node;
        std::cout << "node added at the front\n";
    }

    // add new node at the position given
    void addPos(T item, int pos)
    {
        if (pos > length())
        {
            std::cout << "out of bound!! Adding at the back of list.\n";
            add(item);
            return;
        }
        std::cout << "adding node at pos: " << pos << "\n";
        DNode<T> *node = new DNode<T>;
        node->val = item;

        DNode<T> *temp = head;
        while (--pos)
        {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next->prev = node;
        node->prev = temp;
        temp->next = node;
    }

    // remove node from the back
    void rm()
    {
        DNode<T> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
        std::cout << "Deleted node from the back\n";
    }

    // remove node from the front
    void rmFront()
    {
        head = head->next;
        delete head->prev;
        std::cout << "Deleted node from the front\n";
    }

    // remove node at the given pos
    void rmPos(int pos)
    {
        std::cout << "deleted node at pos: " << pos << "\n";
        if (pos > length())
        {
            std::cout << "out of bound!! Deleting from the back\n";
            rm();
            return;
        }
        DNode<T> *temp = head;
        while (--pos)
        {
            temp = temp->next;
        }
        DNode<T> *dummy = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete dummy;
    }

    // display list
    void
    display()
    {
        DNode<T> *temp = head;
        std::cout << "--------------FORWARD-------------\n";
        while (temp != NULL)
        {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << "\n----------------------------------\n";
    }

    void displayReverse()
    {
        DNode<T> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        std::cout << "--------------BACKWARD-------------\n";
        while (temp != NULL)
        {
            std::cout << temp->val << " ";
            temp = temp->prev;
        }
        std::cout << "\n-----------------------------------\n";
    }

    // calculate the length of the list
    int length()
    {
        int len = 0;
        DNode<T> *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
};

#endif