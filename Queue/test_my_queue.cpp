#include <iostream>
#include <queue>
#include "my_queue.h"

using namespace std;

int main()
{
    my_queue<int> my_que;
    cout << "The queue size: " << my_que.size() << endl;
    my_que.push(5);
    my_que.push(8);
    cout << "que.front() = " << my_que.front() << endl;
    cout << "que.back() = " << my_que.back() << endl;
    cout << "The queue size: " << my_que.size() << endl;
    my_que.pop();
    cout << "que.front() = " << my_que.front() << endl;
    cout << "que.back() = " << my_que.back() << endl;
    cout << "The queue size: " << my_que.size() << endl;
    my_que.pop();
    cout << "que.front() = " << my_que.front() << endl;
    cout << "que.back() = " << my_que.back() << endl;
    cout << "The queue size: " << my_que.size() << endl;

    cout << "-----------------------" << endl;

    queue<int> que;
    cout << "The queue size: " << que.size() << endl;
    que.push(5);
    que.push(8);
    cout << "que.front() = " << que.front() << endl;
    cout << "que.back() = " << que.back() << endl;
    cout << "The queue size: " << que.size() << endl;
    que.pop();
    cout << "que.front() = " << que.front() << endl;
    cout << "que.back() = " << que.back() << endl;
    cout << "The queue size: " << que.size() << endl;
    que.pop();
    cout << "que.front() = " << que.front() << endl;
    cout << "que.back() = " << que.back() << endl;
    cout << "The queue size: " << que.size() << endl;

    return 0;
}
