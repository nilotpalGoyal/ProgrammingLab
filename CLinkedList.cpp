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
        head = NULL;
    }
};

int main()
{
    return 0;
}