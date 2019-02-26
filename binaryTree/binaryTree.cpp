#include <iostream>

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
    isFind(theNode, root);
}

template<class T>
void BinaryTree<T>::preOrder() const
{
    preOrder(root);

    std::cout << std::endl;
}

template<class T>
void BinaryTree<T>::inOrder() const
{
    inOrder(root);

    std::cout << std::endl;
}

template<class T>
void BinaryTree<T>::postOrder() const
{
    postOrder(root);

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
    if(p->leftNode != nullptr && p->leftNode != nullptr) //需查找右子树最小的节点
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
void BinaryTree<T>::preOrder(TreeNode<T> *bt) const
{
    TreeNode<T> *p = bt;
    if (nullptr != p)
    {
        std::cout << p->data << " ";
        preOrder(p->leftNode);
        preOrder(p->rightNode);
    }
}

template<class T>
void BinaryTree<T>::inOrder(TreeNode<T> *bt) const
{
    TreeNode<T> *p = bt;
    if (nullptr != p)
    {
        inOrder(p->leftNode);
        std::cout << p->data << " ";
        inOrder(p->rightNode);
    }
}

template<class T>
void BinaryTree<T>::postOrder(TreeNode<T> *bt) const
{
    TreeNode<T> *p = bt;
    if (nullptr != p)
    {
        postOrder(p->leftNode);
        postOrder(p->rightNode);
        std::cout<< p->data << " ";
    }
}

