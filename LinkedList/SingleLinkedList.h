#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include <iostream>

using namespace std;


/*单链表结点定义*/

template<class T>
class LinkNode
{
    public:
        T data;
        LinkNode<T> *next;
        LinkNode(LinkNode<T> *ptr = NULL){next = ptr;}
        LinkNode(const T &item, LinkNode<T> *ptr = NULL)
        {
            next = ptr;
            data = item;
        }
};


#if 0
template<class T>
struct LinkNode
{
    T data;
    LinkNode<T> *next;
    LinkNode(LinkNode<T> *ptr = NULL){next = ptr;}
    LinkNode(const T &item, LinkNode<T> *ptr = NULL)
    {
        next = ptr;
        data = item;
    }
};
#endif


/*带头结点的单链表定义*/
template<class T>
class SingleLinkedList: public LinkNode<T>
{
    public:
        //无参数的构造函数
        SingleLinkedList(){head = new LinkNode<T>;}
        //带参数的构造函数
        SingleLinkedList(const T &item){head = new LinkNode<T>(item);}
        //拷贝构造函数
        SingleLinkedList(SingleLinkedList<T> &List);
        //析构函数
        ~SingleLinkedList(){Clear();}
        //重载函数：赋值
        SingleLinkedList<T>& operator=(SingleLinkedList<T> &List);
        //链表清空
        void Clear();
        //获取链表长度
        int Length() const;
        //获取链表头结点
        LinkNode<T> * GetHead() const;
        //设置链表头结点
        void SetHead(LinkNode<T> *p);
        //查找给定数据的前一个位置，返回第一个找到的满足条件的结点指针
        LinkNode<T> * FindPrevious(T &item);
        //查找数据的位置，返回第一个找到的满足条件的结点指针
        LinkNode<T> * Find(T &item);
        //head头结点的下一个位置pos = 1，即链表的第一个结点
        /*查找给定位置结点的前一个结点，并返回该结点*/
        LinkNode<T> * LocatePrevious(int pos);
        //定位指定的位置，返回该位置上的结点指针
        LinkNode<T> * Locate(int pos);
        //在指定的位置pos后插入值为item的结点，失败返回false
        bool InsertAfterPos(T &item, int pos);
        //在指定的位置pos前插入值为item的结点，失败返回false
        bool InsertPrevPos(T &item, int pos);
        //删除指定位置pos的结点的值，item就是该结点的值，失败返回false
        bool Delete(int pos, T &item);
        //获取指定位置pos结点的值，失败返回false
        bool GetData(int pos, T &item);
        //设置指定位置pos的结点的值，失败返回false
        bool SetData(int pos, T &item);
        //判断链表是否为空
        bool isEmpty() const;
        /*判断指定位置pos的结点是否为最后一个结点*/
        bool isLast(int pos);
        //打印链表
        void PrintList() const;
        //链表排序
        void SortList(bool flag);//flag为ture时升序，false时为降序
        //链表逆序
        void Reverse();
    private:
        LinkNode<T> *head;
};

/*判断链表是否为空*/
template<class T>
bool SingleLinkedList<T>::isEmpty() const
{
        return head->next == NULL;
}

/*判断指定位置pos的结点是否为最后一个结点*/
template<class T>
bool SingleLinkedList<T>::isLast(int pos)
{
   LinkNode<T> *p = head;
   int cnt = 0;
   while(p->next != NULL && cnt < pos)
   {
        cnt++;
        p = p->next;
   }

   if(p->next == NULL)
       return true;//无论cnt是否等于pos，只要链表遍历空了，pos位置就为空
   
   return false;//否则肯定是pos位置链表不空
}

/*获取链表长度*/
template<class T>
int SingleLinkedList<T>::Length() const
{
    int len = 0;
    LinkNode<T> *p = head;
    while(p->next != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

/*链表清空*/
template<class T>
void SingleLinkedList<T>::Clear()
{
    LinkNode<T> *p = NULL;
    while(head->next != NULL)
    {
        p = head->next;
        head->next = p->next;
        delete p;
    }
}

/*获取链表头结点*/
template<class T>
LinkNode<T>* SingleLinkedList<T>::GetHead() const
{
    LinkNode<T> *p = head;

    return p;
}

/*设置链表头结点*/
template<class T>
void SingleLinkedList<T>::SetHead(LinkNode<T> *p)
{
    head = p;
}

//查找给定数据的前一个位置，返回第一个找到的满足条件的结点指针
template<class T>
LinkNode<T>* SingleLinkedList<T>::FindPrevious(T &item)
{
    LinkNode<T> *p = head;
    while(p->next != NULL && p->next->data != item)
    {
        p = p->next;
    }

    return p;
}

/*查找数据的位置，返回第一个找到的满足该数值的结点指针*/
template<class T>
LinkNode<T>* SingleLinkedList<T>::Find(T &item)
{
    LinkNode<T> *p = head->next;
    while(p != NULL && p->data != item)
    {
        p = p->next;
    }
    return p;
}

/*查找给定位置结点的前一个结点，并返回该结点*/
template<class T>
LinkNode<T>* SingleLinkedList<T>::LocatePrevious(int pos)
{
    LinkNode<T> *p = head;
    LinkNode<T> *prev = new LinkNode<T>();
    int cnt = 0;
    while(p->next != NULL && cnt < pos)
    {
        cnt++;
        prev = p;
        p = p->next;
    }

    if(cnt == pos)
        return prev;

    return NULL;
}

/*定位指定的位置，返回该位置上的结点指针*/
template<class T>
LinkNode<T>* SingleLinkedList<T>::Locate(int pos)
{
    if(pos < 0)
        return NULL;
    
    int cnt = 0;
    LinkNode<T> *p = head;//这里让p为head方便后续插入删除，否则会有小bug
    while(p != NULL && cnt < pos)
    {
        cnt++;
        p = p->next;
    }
    return p;
}

/*在指定位置pos后插入值为item的结点，失败返回false*/
/*如果pos=0则直接在链表尾端插入结点*/
template<class T>
bool SingleLinkedList<T>::InsertAfterPos(T &item, int pos)
{
    if(pos == 0)
    {
        LinkNode<T> *p = head;
        while(p->next != NULL)
            p = p->next;

        LinkNode<T> *node = new LinkNode<T>(item);
        if(node == NULL)
            return false;

        p->next = node;

        return true;
    }

    LinkNode<T> *p = Locate(pos);
    if(p == NULL)
        return false;

    LinkNode<T> *node = new LinkNode<T>(item);
    if(node == NULL)
        return false;
    node->next = p->next;
    p->next = node;

    return true;
}

/*在指定位置pos前插入值为item的结点，失败返回false*/
/*如果pos=0则直接在head头结点后插入结点*/
template<class T>
bool SingleLinkedList<T>::InsertPrevPos(T &item, int pos)
{
    if(pos == 0)
    {
        LinkNode<T> *p = head;

        LinkNode<T> *node = new LinkNode<T>(item);
        if(node == NULL)
            return false;

        node->next = head->next;
        head->next = node;

        return true;
    }

    LinkNode<T> *p = LocatePrevious(pos);
    if(p == NULL)
        return false;

    LinkNode<T> *node = new LinkNode<T>(item);
    if(node == NULL)
        return false;
    
    node->next = p->next;
    p->next = node;
}

/*删除指定位置pos上的结点，item就是该结点的值，失败返回false*/
template<class T>
bool SingleLinkedList<T>::Delete(int pos, T &item)
{
    LinkNode<T> *p = LocatePrevious(pos);
    if(p == NULL || p->next == NULL)
        return false;

    LinkNode<T> *del = p->next;
    item = del->data;
    p->next = del->next;
    delete del;

    return true;
}

/*获取指定位置pos的结点的值，失败返回false*/
template<class T>
bool SingleLinkedList<T>::GetData(int pos, T &item)
{
    LinkNode<T> *p = Locate(pos);
    if(p == NULL || p->next == NULL)
        return false;
    
    item = p->data;

    return true;
}

/*设置指定位置pos的结点的值，失败返回false*/
template<class T>
bool SingleLinkedList<T>::SetData(int pos, T &item)
{
    LinkNode<T> *p = Locate(pos);
    if(p == NULL || p->next == NULL)
        return false;

    p->data = item;

    return true;
}

/*打印链表*/
template<class T>
void SingleLinkedList<T>::PrintList() const
{
    LinkNode<T> *p = head->next;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

#if 0
/*链表排序*/
template<class T>
void SingleLinkedList<T>::SortList(bool flag)
{
    if(flag)
    {
        for(LinkNode<T> *p=head->next; p!=NULL; p = p->next)
        {
            for(LinkNode<T> *q=p->next; q!=NULL; q= q->next)
            {
                if(p->data > q->data)
                {
                    LinkNode<T> *tmp;
                    tmp->data = p->data;
                    p->data = q->data;
                    q->data = tmp->data;
                }
            }
        }
    }
    else
    {
        for(LinkNode<T> *p=head->next; p!=NULL; p = p->next)
        {                                                  
            for(LinkNode<T> *q=p->next; q!=NULL; q= q->next)
            {
                if(p->data < q->data)
                {
                    LinkNode<T> *tmp;
                    tmp->data = p->data;                      
                    p->data = q->data;                        
                    q->data = tmp->data;
                }
            }
        }
    }
}
#endif

/*链表逆序*/
template<class T>
void SingleLinkedList<T>::Reverse()
{
    LinkNode<T> *prev = NULL;
    LinkNode<T> *curr = head->next;

    while(curr)
    {
        LinkNode<T> *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = prev;
}

#endif
