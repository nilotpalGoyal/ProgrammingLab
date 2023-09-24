#include "LinkedList.h"
#include "CLinkedList.h"
#include "DynArray.h"
#include "ListStack.h"
#include "DoublyLinkedList.h"
#include "DynArray2D.h"
#include "ArrayStack.h"
#include "ListQueue.h"
#include "ArrayQueue.h"

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

    std::cout << "\nstack top: " << stk.top() << "\n";

    Dynamic2DArray<int> b(3, 3, 2);
    for (int i = 0; i < b.getSize(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }

    CircularLinkedList<int> clist;
    clist.append(11);
    clist.append(12);
    clist.append(13);
    clist.append(14);
    clist.append(15);
    clist.display();

    Queue<int> q;
    q.enqueue(88);
    q.enqueue(89);
    q.enqueue(90);
    q.dequeue();
    std::cout << q.peek() << "\n";

    ArrayQueue<int> q1;
    q1.enqueue(12);
    q1.enqueue(123);
    q1.enqueue(1234);
    q1.dequeue();
    std::cout << q1.peek();
}