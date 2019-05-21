#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<iostream>

using namespace std;

class Exception {
public:
    Exception() {
        msg = "Exception!";
    }

    virtual string Massage() {
        return msg;
    }
protected:
    string msg;
};

class StackEmptyException : public Exception {
public:
    StackEmptyException() {
        msg = "The stack is empty!";
    }
};

class StackFullException : public Exception {
public:
    StackFullException() {
        msg = "The stack is full!";
    }
};

//实现顺序栈模板
template<class T>
class Stack
{
public:
    //构造函数
    Stack(int MaxStackSize = 100);
    //析构函数
    ~Stack() {
        clear();
    }
    //清空栈
    void makeEmpty();
    //判断栈是否为空
    bool empty();
    //判断栈是否已满
    bool full();
    //入栈
    bool push(const T &item);
    //出栈
    bool pop();
    //返回栈顶元素
    T& top();
    // 返回栈的大小
    size_t size();
private:
    int topOfStack;
    int capacity;
    T *array;


    //销毁栈
    void clear();
};

template<class T>
Stack<T>::Stack(int MaxStackSize):capacity(MaxStackSize)
{
    array = new T[capacity];
    topOfStack = -1;
}

template<class T>
bool Stack<T>::empty()
{
    if (topOfStack == -1)
        return true;
    return false;
}

template<class T>
bool Stack<T>::full()
{
    if (topOfStack == capacity - 1)
        return true;
    return false;
}

template<class T>
bool Stack<T>::push(const T &item)
{
    if(full())
        throw StackFullException();
    topOfStack ++;
    array[topOfStack] = item;
    return true;
}

template<class T>
bool Stack<T>::pop()
{
    if(empty())
        throw StackEmptyException();
    topOfStack --;
    return true;
}

template<class T>
T& Stack<T>::top()
{
    if (empty())
        throw StackEmptyException();
    return array[topOfStack];
}

template<class T>
void Stack<T>::clear()
{
    topOfStack = -1;
    delete []array;
}

template<class T>
void Stack<T>::makeEmpty()
{
    topOfStack = -1;
}

template<class T>
size_t Stack<T>::size()
{
    return topOfStack + 1;
}

#endif // STACK_H_INCLUDED
