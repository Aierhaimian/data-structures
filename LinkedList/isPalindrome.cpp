#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

bool isPalindrome(SingleLinkedList<char> *list)
{
    LinkNode<char> *h = list->GetHead();
    if (list->isEmpty() == true && h->next == NULL)
        return true;

    LinkNode<char> *slow = list->GetHead();
    LinkNode<char> *fast = list->GetHead();

    while(fast && slow && fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    LinkNode<char> *mid = slow->next;
    slow->next = NULL;
    slow = list->GetHead();
    slow = slow->next;


    LinkNode<char> *pre = NULL;
    LinkNode<char> *cur = mid;

    while(cur != NULL)
    {
        LinkNode<char> *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    fast = pre;

    while(slow && fast)
    {
        if(slow->data != fast->data)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main()
{
    char str1[] = {'a','b','c','b','a'};
    char str2[] = {'a','b','c'};
    char a = 'a';

    SingleLinkedList<char> *list1 = new SingleLinkedList<char>();
    SingleLinkedList<char> *list2 = new SingleLinkedList<char>();
    SingleLinkedList<char> *list3 = new SingleLinkedList<char>();

    for(int i=0; i<sizeof(str1)/sizeof(str1[0]); i++)
        list1->InsertAfterPos(str1[i], 0);
    list1->PrintList();

    for(int i=0; i<sizeof(str2)/sizeof(str2[0]); i++)
        list2->InsertAfterPos(str2[i], 0);
    list2->PrintList();

    list3->InsertAfterPos(a, 0);
    list3->PrintList();

    bool res1, res2, res3;

    res1 = isPalindrome(list1);
    res2 = isPalindrome(list2);
    res3 = isPalindrome(list3);

    cout << "res1 = " << res1 << endl;
    cout << "res2 = " << res2 << endl;
    cout << "res3 = " << res3 << endl;

    return 0;
}
