#include <iostream>
#include <stack>

#include "binaryTree.h"

template<class T>
BinaryTree<T>::BinaryTree()
{
    root = new TreeNode<T>();
}

template<class T>
BinaryTree<T>::BinaryTree(const T &item)
{
    root = new TreeNode<T>(item);
}

template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &bt)
{
    if(nullptr != bt.root)
        this->root = clone(bt.root);
    else
        root = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    release();
}

template<class T>
void BinaryTree<T>::insert(const T &theNode)
{
    insert(theNode, root);
}

template<class T>
void BinaryTree<T>::remove(const T &theNode)
{
    remove(theNode, root);
}

template<class T>
bool BinaryTree<T>::isFind(const T &theNode)
{
    return isFind(theNode, root);
}

template<class T>
void BinaryTree<T>::preOrder() const
{
    preOrderRecur(root);
    std::cout << std::endl;

    preOrderNonRecur(root);
    std::cout << std::endl;
}

template<class T>
void BinaryTree<T>::inOrder() const
{
    inOrderRecur(root);
    std::cout << std::endl;

    inOrderNonRecur(root);
    std::cout << std::endl;
}

template<class T>
void BinaryTree<T>::postOrder() const
{
    postOrderRecur(root);
    std::cout << std::endl;

    postOrderNonRecur(root);
    std::cout << std::endl;
}

template<class T>
void BinaryTree<T>::release()
{
    release(root);
}

template<class T>
bool BinaryTree<T>::isEmpty()
{
    return isEmpty(root);
}

template<class T>
TreeNode<T> * BinaryTree<T>::clone(const TreeNode<T> *bt)
{
    if (nullptr == bt)
        return nullptr;
    else
        return new TreeNode<T>(bt->data, bt->leftNode, bt->rightNode);
}

template<class T>
void BinaryTree<T>::release(TreeNode<T> *bt)
{
    if (nullptr == bt)
        return;
    
    release(bt->leftNode);
    release(bt->rightNode);
    
    delete bt;
}

template<class T>
bool BinaryTree<T>::isEmpty(TreeNode<T> *bt)
{
    if (nullptr == bt)
        return true;
    return false;
}



//按照二叉查找树进行节点的插入、删除与查找
template<class T>
bool BinaryTree<T>::isFind(const T &theNode, TreeNode<T> *bt)
{
    TreeNode<T> *p = bt;
    while(p != nullptr)
    {
        if (theNode < p->data)
            p = p->leftNode;
        else if (theNode > p->data)
            p = p->rightNode;
        else
            return true;
    }

    return false;
}

template<class T>
void BinaryTree<T>::insert(const T &theNode, TreeNode<T> *&bt)
{
   if(nullptr == bt)
   {
       bt = new TreeNode<T>(theNode);
       return;
   }

   TreeNode<T> *p = bt;
   while(p != nullptr)
   {
       if (theNode > p->data)
       {
           if (p->rightNode == nullptr)
           {
                p->rightNode = new TreeNode<T>(theNode);
                return;
           }

           p = p->rightNode;
       }
       else if (theNode < p->data)
       {
            if (p->leftNode == nullptr)
            {
                p->leftNode = new TreeNode<T>(theNode);
                return;
            }

            p = p->leftNode;
       }
   }
}

template<class T>
void BinaryTree<T>::remove(const T &theNode, TreeNode<T> *&bt)
{
    TreeNode<T> *p = bt;//p指向要删除的节点，初始化指向根节点
    TreeNode<T> *pp = new TreeNode<T>(); //pp指向p的父节点

    while(p != nullptr && p->data != theNode)
    {
        pp = p;
        if(theNode > p->data)
            p = p->rightNode;
        else
            p = p->leftNode;
    }

    if(p == nullptr)
        return;

    //要删除的节点有两个子节点
    if(p->leftNode != nullptr && p->rightNode != nullptr) //需查找右子树最小的节点
    {
        TreeNode<T> *minP = p->rightNode;
        TreeNode<T> *minPP = p; //minPP表示minP的父节点

        while(minP->leftNode != nullptr)
        {
            minPP = minP;
            minP = minP->leftNode;
        }

        p->data = minP->data;
        p = minP; //下面就要删除minP
        pp = minPP;
    }

    //要删除的节点是叶子节点或者仅有一个节点
    TreeNode<T> *child = new TreeNode<T>(); //p的子节点
    if(p->leftNode != nullptr)
        child = p->leftNode;
    else if(p->rightNode != nullptr)
        child = p->rightNode;
    else
        child = nullptr;

    if(pp ==nullptr)
        bt = child;
    else if(pp->leftNode == p)
        pp->leftNode = child;
    else
        pp->rightNode = child;

    delete p;
}


template<class T>
BinaryTree<T> * BinaryTree<T>::findMax(TreeNode<T> *bt) const
{
    TreeNode<T> *p = bt;
    while(p != nullptr)
    {
        p = p->rightNode;
    }

    return p;
}

template<class T>
BinaryTree<T> * BinaryTree<T>::findMin(TreeNode<T> *bt) const
{
    TreeNode<T> *p = bt;
    while(p != nullptr)
    {
        p = p->leftNode;
    }

    return p;
}

template<class T>
void BinaryTree<T>::preOrderRecur(TreeNode<T> *bt) const
{
    TreeNode<T> *p = bt;
    if (nullptr != p)
    {
        std::cout << p->data << " ";
        preOrderRecur(p->leftNode);
        preOrderRecur(p->rightNode);
    }
}

// 根节点不空，打印，根节点入栈，并将左孩子设为当前节点
// 左孩子即当前节点不为空，打印，用一个while实现
// 若左孩子为空，跳出while循环
// 
// 若栈不空，则将栈顶设为当前节点，pop栈顶，将当前节点的右孩子为当前节点
template<class T>
void BinaryTree<T>::preOrderNonRecur(TreeNode<T> *bt) const
{
    TreeNode<T>* p = bt;
    if (nullptr == p)
        return;
    std::stack<TreeNode<T>*> s;
    TreeNode<T>* current = p;
    while (nullptr != current || !s.empty() )
    {
        while (nullptr != current)
        {
            std::cout << current->data << " ";
            s.push(current);
            current = current->leftNode;
        }

        if (!s.empty())
        {
            current = s.top();
            s.pop();
            current = current->rightNode;
        }
    }
}

template<class T>
void BinaryTree<T>::inOrderRecur(TreeNode<T> *bt) const
{
    TreeNode<T> *p = bt;
    if (nullptr != p)
    {
        inOrderRecur(p->leftNode);
        std::cout << p->data << " ";
        inOrderRecur(p->rightNode);
    }
}

// 类似前序遍历
template<class T>
void BinaryTree<T>::inOrderNonRecur(TreeNode<T>* bt) const
{
    TreeNode<T>* p = bt;
    if (nullptr == p)
        return;

    std::stack<TreeNode<T>*> s;
    TreeNode<T>* current = p;

    while (nullptr != current || !s.empty())
    {
        while (nullptr != current)
        {
            s.push(current);
            current = current->leftNode;
        }

        if (!s.empty())
        {
            current = s.top();
            std::cout << current->data << " ";
            s.pop();
            current = current->rightNode;
        }
    }
}

template<class T>
void BinaryTree<T>::postOrderRecur(TreeNode<T> *bt) const
{
    TreeNode<T> *p = bt;
    if (nullptr != p)
    {
        postOrderRecur(p->leftNode);
        postOrderRecur(p->rightNode);
        std::cout<< p->data << " ";
    }
}

// 要保证先访问根节点的左孩子、右孩子之后才能访问根节点
// 因此对于任一节点p，先将其入栈，若p不存在左孩子和右孩子
// 或者左孩子或右孩子都已被访问，则同样可以直接访问该节点
// 否则，将p的右孩子和左孩子依次入栈，这样就保证了每次取
// 栈顶元素的时候按照左右根的顺序访问。
template<class T>
void BinaryTree<T>::postOrderNonRecur(TreeNode<T>* bt) const
{
    TreeNode<T>* p = bt;
    if (nullptr == p)
        return;

    std::stack<TreeNode<T>*> s;
    TreeNode<T>* cur;
    TreeNode<T>* pre = nullptr;

    s.push(p);
    while (!s.empty())
    {
        cur = s.top();
        if ((nullptr == cur->leftNode && nullptr == cur->rightNode) ||
            (nullptr != pre && (pre == cur->leftNode || pre == cur->rightNode)))
        {
            std::cout << cur->data << " ";
            s.pop();
            pre = cur;
        }
        else
        {
            if (nullptr != cur->rightNode)
                s.push(cur->rightNode);
            if (nullptr != cur->leftNode)
                s.push(cur->leftNode);
        }
    }
}
