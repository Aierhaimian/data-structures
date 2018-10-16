#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<iostream>

using namespace std;

//实现顺序栈模板
template<class T>
class stack
{
public:
    //构造函数
    Stack(){int MaxStackSize = 100};
    //析构函数
    ~Stack(){Clear()};
    //销毁栈
    void Clear();
    //清空栈
    void Empty();
    //判断栈是否为空
    bool isEmpty();
    //判断栈是否已满
    bool isFull();
    //入栈
    bool Push(const T &item);
    //出栈
    bool Pop();
    //返回栈顶元素
    bool Top(T &item);
private:
    int topOfStack;
    int capacity;
    T *array;
};

template<class T>
Stack<T>::Stack(int MaxStackSize):capacity(MaxStackSize)
{
    array = new T[capacity];
    topOfStack = -1;
}

template<class T>
bool Stack<T>::isEmpty()
{
    return topOfStack == -1;
}

template<class T>
bool Stack<T>::isFull()
{
    return topOfStack == capacity - 1;
}

template<class T>
bool Stack<T>::Push(const T &item)
{
    if(isFull() == true)
        return false;
    topOfStack ++;
    array[topOfStack] = item;
    return true;
}

template<class T>
bool Stack<T>::Pop()
{
    if(isEmpty() == true)
        return false;
    topOfStack --;
    return true;
}

template<class T>
bool Stack<T>::Top(T &item)
{
    if(isEmpty() == true)
        return false;
    item = array[topOfStack];
    return true;
}

template<class T>
void Stack<T>::Clear()
{
    topOfStack = -1;
    delete []array;
}

template<class T>
void Stack<T>::Empty()
{
    topOfStack = -1;
}

#endif // STACK_H_INCLUDED
