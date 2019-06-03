#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <algorithm>


template<class T>
class MaxHeap {
public:
    MaxHeap(int _max_size=1024)
        :max_size(_max_size)
    {
        contents = new T[max_size + 1];
        count = 0;
    }

    ~MaxHeap() {}

    void insert(int data); // 插入元素
    void removeMax(); // 删除堆顶元素
    T top();
    bool empty();
    int size();

private:
    void heapfiy(int n, int i);
private:
    const int max_size;
    int count;
    T *contents;
};

template<class T>
bool MaxHeap<T>::empty()
{
    return count == 0;
}

template<class T>
T MaxHeap<T>::top()
{
    return contents[1];
}

template<class T>
int MaxHeap<T>::size()
{
    return count;
}

template<class T>
void MaxHeap<T>::insert(int data)
{
    if (count >= max_size)
        return; // 堆满返回
    contents[++count] = data;

    int i = count;
    while (i/2 > 0 && contents[i] > contents[i/2]) { // 自下向上堆化
        std::swap(contents[i], contents[i/2]);
        i /= 2;
    }
}

template<class T>
void MaxHeap<T>::removeMax()
{
    if (count == 0)
        return; // 堆空返回
    contents[1] = contents[count--];

    heapfiy(count, 1);
}

template<class T>
void MaxHeap<T>::heapfiy(int n, int i) // 自上向下堆化
{
    while (true) {
        int maxPos = i;
        if (i*2 <= n && contents[i] < contents[i*2]) maxPos = i*2;
        if (i*2+1 <= n && contents[maxPos] < contents[i*2+1]) maxPos = i*2+1;
        if (maxPos == i) break;
        std::swap(contents[i], contents[maxPos]);
        i = maxPos;
    }
}

#endif
