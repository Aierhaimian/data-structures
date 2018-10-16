#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main()
{
    int a[3] = {4, 7, 1};
    SingleLinkedList<int> linkList;

    cout << linkList.isEmpty() << endl;

    cout << linkList.InsertAfterPos(a[0], 0) << endl;
    cout << linkList.InsertAfterPos(a[1], 0) << endl;
    cout << linkList.InsertAfterPos(a[2], 0) << endl;

    cout << linkList.isEmpty() << endl;

    cout << linkList.Length() << endl;

    linkList.PrintList();
    
    //int item;
    //linkList.Delete(2, item);
    
    //cout<<"The delete node value is: " << item << endl;
    
    //linkList.SortList(true);

    //linkList.PrintList();

    linkList.Reverse();

    linkList.PrintList();

    linkList.Clear();
    
    cout << linkList.isEmpty() << endl;

    cout << linkList.Length() << endl;

    linkList.PrintList();
    
    return 0;
}
