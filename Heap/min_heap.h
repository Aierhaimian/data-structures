#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <algorithm>


template<class T>
class MinHeap {
public:
    MinHeap(int _max_size=1024)
        :max_size(_max_size)
    {
        contents = new T[max_size + 1];
        count = 0;
    }

    ~MinHeap() {}

    void push(T data); // 插入元素
    void pop(); // 删除堆顶元素
    void update(T data); // 更新元素
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
bool MinHeap<T>::empty()
{
    return count == 0;
}

template<class T>
T MinHeap<T>::top()
{
    return contents[1];
}

template<class T>
int MinHeap<T>::size()
{
    return count+1;
}

template<class T>
void MinHeap<T>::push(T data)
{
    if (count >= max_size)
        return; // 堆满返回
    contents[++count] = data;

    int i = count;
    while (i/2 > 0 && contents[i] < contents[i/2]) { // 自下向上堆化
        std::swap(contents[i], contents[i/2]);
        i /= 2;
    }
}

template<class T>
void MinHeap<T>::pop()
{
    if (count == 0)
        return; // 堆空返回
    contents[1] = contents[count--];

    heapfiy(count, 1);
}

template<class T>
void MinHeap<T>::update(T data)
{
    for (int i=1; i<=count; ++i)
    {
        if (data == contents[i])
        {
            contents[i] = data;
            break;
        }
    }
}

template<class T>
void MinHeap<T>::heapfiy(int n, int i) // 自上向下堆化
{
    while (true) {
        int maxPos = i;
        if (i*2 <= n && contents[i] > contents[i*2]) maxPos = i*2;
        if (i*2+1 <= n && contents[maxPos] > contents[i*2+1]) maxPos = i*2+1;
        if (maxPos == i) break;
        std::swap(contents[i], contents[maxPos]);
        i = maxPos;
    }
}

#endif
