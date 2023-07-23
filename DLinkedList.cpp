#include <iostream>
#include <string>

template <typename T>
class DNode
{
public:
    T val;
    DNode<T> prev;
    DNode<T> next;

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
    /* data */
public:
    DLinkedList(){

    };
    ~DLinkedList();
};
