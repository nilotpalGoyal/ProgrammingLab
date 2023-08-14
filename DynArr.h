#ifndef DYNARR_H
#define DYNARR_H

#include <iostream>

using namespace std;

template <class T>
class ArrNode
{
public:
    T *array;
    int length;

    ArrNode()
    {
        length = 0;
    }
};

template <typename T>
class DynArray
{
public:
    ArrNode<T> ad;

    void insertEl()
    {
        T num;
        int pos;
        cout << "Enter a value to be inserted: ";
        cin >> num;
        cout << "Enter the position at which the new element is to be inserted: ";
        cin >> pos;
        if (pos <= ad.length + 1)
        {
            ad.length++;
            for (int i = pos - 1; i < ad.length; i++)
            {
                ad.array[i + 1] = ad.array[i];
            }
            ad.array[pos - 1] = num;
            display();
        }
        else
        {
            cout << "The element cannnot be inserted at the given position." << endl;
        }
    }

    void deleteEl()
    {
        int num;
        cout << "Enter the value to be deleted: ";
        cin >> num;
        for (int i = 0; i < ad.length; i++)
        {
            if (ad.array[i] == num)
            {
                for (int j = i; j < ad.length; j++)
                {
                    ad.array[j] = ad.array[j + 1];
                }
                ad.length--;
                display();
                break;
            }
            else
            {
                cout << "The given element could not be found." << endl;
            }
        }
    }

    void searchEl()
    {
        int num, found = 0;
        cout << "Enter a number that you want to be searched: ";
        cin >> num;

        for (int i = 0; i < ad.length; i++)
        {
            if (ad.array[i] == num)
            {
                cout << "The element is found at position " << i + 1 << endl;
                found++;
                break;
            }
        }
        if (found == 0)
        {
            cout << "The given element is not present in the list." << endl;
        }
    }

    void display()
    {

        cout << "The new list is: ";
        for (int i = 0; i < ad.length; i++)
        {
            cout << ad.array[i] << " ";
        }
        cout << endl;
    }
};

#endif
