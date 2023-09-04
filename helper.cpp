#include "LinkedList.h"
#include "CLinkedList.h"
#include "DynArray.h"
#include "ListStack.h"
#include "DoublyLinkedList.h"
#include "DynArray2D.h"
#include "ArrayStack.h"

int main()
{
    LinkedList<int> mylist;
    mylist.add(11);
    mylist.add(12);
    mylist.add(13);
    mylist.add(14);
    std::cout << "linkedlist : ";
    mylist.display();

    DoublyLinkedList<float> dlist;
    dlist.pushBack(11);
    dlist.pushBack(12);
    dlist.pushBack(13);
    dlist.pushBack(14);
    dlist.popAtPosition(1);
    dlist.popAtPosition(3);
    dlist.popAtPosition(3);
    dlist.popAtPosition(3);
    std::cout << "doubly linkedlist : ";
    dlist.print();

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

    Stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.pop();
    stk.pop();

    std::cout << "stack top: " << stk.top() << "\n";

    Dynamic2DArray<int> b(3, 3, 2);
    for (int i = 0; i < b.getSize(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }

    CLinkedList<int> clist;
    clist.add(11);
    clist.add(12);
    clist.add(12);
    clist.add(12);
    clist.add(14);
    clist.display();
    clist.rmFront();
    clist.rm();
    clist.display();
    clist.addPos(123, 4);
    clist.display();
}