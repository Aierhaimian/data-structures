#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring>
#include <cstdio>

class MyString
{
public:
    MyString(char* pData = nullptr); // 构造函数
    MyString(const MyString& str); // 拷贝构造函数
    ~MyString(); // 析构函数

    MyString& operator=(const MyString& str); // 赋值运算符重载函数

private:
    char* m_pData;
};

MyString::MyString(char* pData)
{
    if (pData == nullptr) {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else {
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData);
    }
}

MyString::MyString(const MyString& str)
{
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
}

MyString::~MyString()
{
    delete []m_pData;
}

MyString& MyString::operator=(const MyString& str)
{
    if (this != &str) {
        MyString strTmp(str);
        char* pTmp = strTmp.m_pData;
        strTmp.m_pData = m_pData;
        m_pData = pTmp;
    }
    return *this;
}

#endif

