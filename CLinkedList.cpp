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
        CNode<T> *node = new CNode<T>;
        node->val = item;

        CNode<T> *temp = head;
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

    // remove node from the given position

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
};

int main()
{
    CLinkedList<int> myList;
    myList.add(11);
    myList.add(12);
    myList.add(13);
    myList.add(14);
    myList.add(15);
    myList.add(16);
    myList.addFront(6);
    myList.addFront(99);
    myList.addFront(88);
    myList.addPos(22, 5);
    myList.display();

    myList.rm();
    myList.display();
    return 0;
}