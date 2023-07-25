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
    }

    // remove node from the front
    void rmFront()
    {
        head = head->next;
        delete head->prev;
    }

    // remove node at the given pos
    void rmPos(int pos)
    {
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
};

int main()
{
    DLinkedList<int> intDoublyLL;
    intDoublyLL.add(121);
    intDoublyLL.add(123);
    intDoublyLL.add(124);
    intDoublyLL.add(126);
    intDoublyLL.addFront(99);
    intDoublyLL.addPos(66, 4);
    intDoublyLL.display();
    intDoublyLL.displayReverse();

    intDoublyLL.rm();
    intDoublyLL.add(100);
    intDoublyLL.add(101);
    intDoublyLL.rmFront();
    intDoublyLL.display();
    intDoublyLL.rmPos(2);
    intDoublyLL.display();

    return 0;
}