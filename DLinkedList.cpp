#include <iostream>
#include <string>

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
    }
    // add new node at the position given

    // remove node from the back
    // remove node from the front
    // remove node at the given pos

    // display list
    void display()
    {
        DNode<T> *temp = head;
        std::cout << "---------------------------\n";
        while (temp != NULL)
        {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << "\n---------------------------\n";
    }

    void displayReverse()
    {
        DNode<T> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        std::cout << "---------------------------\n";
        while (temp != NULL)
        {
            std::cout << temp->val << " ";
            temp = temp->prev;
        }
        std::cout << "\n---------------------------\n";
    }
    // calculate the length of the list
};

int main()
{
    DLinkedList<int> intDoublyLL;
    intDoublyLL.add(121);
    intDoublyLL.add(123);
    intDoublyLL.add(124);
    intDoublyLL.add(126);
    intDoublyLL.display();
    intDoublyLL.displayReverse();
    return 0;
}