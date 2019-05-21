#include <iostream>
#include "Stack.h"

using namespace std;


int main()
{
    Stack<int> s;
    cout << "s.size = " << s.size() << endl;
    s.push(5);
    s.push(8);
    cout << "s.top = " << s.top() << endl;
    cout << "s.size = " << s.size() << endl;
    s.pop();
    cout << "s.top = " << s.top() << endl;
    cout << "s.size = " << s.size() << endl;
    s.makeEmpty();
    cout << "s.size = " << s.size() << endl;
    int i=0;
    while (!s.full()) {
        s.push(i++);
    }
    cout << "s.size = " << s.size() << endl;
    while (!s.empty())
        s.pop();
    cout << "s.size = " << s.size() << endl;
    return 0;
}

