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
class SLinkedList
{
private:
    Node<T> *head;

public:
    // constructor
    SLinkedList()
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
            std::cout << "Out of bound!!\n";
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

        std::cout << "Last Value: " << temp->val << "\n";
    }

    // remove at the given postion
    void rmPos(int pos)
    {
        if (pos > length())
        {
            std::cout << "Out of bound!!\n";
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

int main()
{
    SLinkedList<int> myIntList;
    myIntList.add(12);
    myIntList.add(123);
    myIntList.add(1234);
    myIntList.addFront(1);
    myIntList.addFront(11);
    myIntList.addFront(111);
    myIntList.addPos(999, 9);
    myIntList.display();
    myIntList.rmFront();
    myIntList.display();

    SLinkedList<float> myFloatList;
    myFloatList.add(1.5);
    myFloatList.add(1.512);
    myFloatList.add(112.53);
    myFloatList.addFront(231.225);
    myFloatList.addFront(232.225);
    myFloatList.addFront(233.225);
    myFloatList.display();
    myFloatList.rmBack();
    myFloatList.display();
    return 0;
}
