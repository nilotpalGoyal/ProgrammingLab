#include "LinkedList.h"
#include "DLinkedList.h"
#include "CLinkedList.h"
#include "DynArr.h"

int main()
{
    LinkedList<int> mylist;
    mylist.add(11);
    mylist.add(12);
    mylist.add(13);
    mylist.add(14);
    mylist.display();

    DLinkedList<float> dlist;
    dlist.add(12.4);
    dlist.add(3.13);
    dlist.add(1.423);
    dlist.display();

    CLinkedList<long> clist;
    clist.add(12124);
    clist.add(1231244140);
    clist.add(1252365740);
    clist.display();

    DynArr<int> arr(10, 0);
    arr.pushBack(12);
    arr.remove(2);
    arr[0] = 12;
    std::cout << arr[0];
}