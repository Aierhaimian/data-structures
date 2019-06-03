#include <iostream>
#include "max_heap.h"

using namespace std;


int main()
{
    MaxHeap<int> max_heap;
    cout << "heap.size() = " << max_heap.size() << endl;
    cout << "heap.empty() = " << max_heap.empty() << endl;
    max_heap.insert(5);
    max_heap.insert(7);
    max_heap.insert(16);
    max_heap.insert(12);
    max_heap.insert(3);
    max_heap.insert(2);
    max_heap.insert(15);
    cout << "heap.size() = " << max_heap.size() << endl;
    cout << "heap.top() = " << max_heap.top() << endl;
    while(!max_heap.empty()) {
        max_heap.removeMax();
        if (max_heap.empty())
            break;
        cout << "heap.top() = " << max_heap.top() << endl;
    }
    return 0;
}

