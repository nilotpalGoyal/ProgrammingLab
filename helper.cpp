#include "LinkedList.h"
#include "DLinkedList.h"
#include "CLinkedList.h"
#include "DynArr.h"
#include "ListStack.h"

int main()
{
    LinkedList<int> mylist;
    mylist.add(11);
    mylist.add(12);
    mylist.add(13);
    mylist.add(14);
    std::cout << "linkedlist : ";
    mylist.display();

    DLinkedList<float> dlist;
    dlist.add(12.4);
    dlist.add(3.13);
    dlist.add(1.423);
    std::cout << "doubly linkedlist : ";
    dlist.display();

    CLinkedList<long> clist;
    clist.add(12124);
    clist.add(1231244140);
    clist.add(1252365740);
    std::cout << "\ncircular linkedlist : ";
    clist.display();

    DynArr<int> arr(10, 0);
    std::cout << "Dynamic Array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = i;
        std::cout << arr[i] << " ";
    }

    ListStack<int> st;
    st.push(41);
    st.push(21);
    st.push(1);
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(16);

    std::cout << "\nsize of stack:" << st.getsize() << "\n";
    for (int i = 0; i < st.getsize(); i++)
    {
        std::cout << st.top() << " ";
        st.pop();
    }

    // std::cout << "\ntop of stack:" << st.top();
}