#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <iostream>
#include <vector>

template<class T>
class my_queue
{
public:
    my_queue() {}
    ~my_queue() {}

    bool empty();
    size_t size() const;
    T front();
    T back();
    void push(T x);
    void pop();

private:
    std::vector<T> contents;
};

template<class T>
bool my_queue<T>::empty()
{
    return contents.empty();
}

template<class T>
size_t my_queue<T>::size() const
{
    return contents.size();
}

template<class T>
T my_queue<T>::front()
{
    return contents.front();
}

template<class T>
T my_queue<T>::back()
{
    return contents.back();
}

template<class T>
void my_queue<T>::push(T x)
{
    contents.push_back(x);
}

template<class T>
void my_queue<T>::pop()
{
    contents.erase(contents.begin());
}

#endif
