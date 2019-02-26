#ifndef BINARYTREE_BINARYTREE_H_H
#define BINARYTREE_BINARYTREE_H_H

#include <iostream>

template<class T>
class TreeNode{
    public:
        T data;
        TreeNode<T> *leftNode;
        TreeNode<T> *rightNode;

        //无参构造
        TreeNode()
            :data(0), leftNode(nullptr), rightNode(nullptr) {}
        //带参构造
        TreeNode(const T &item, TreeNode<T> *left, TreeNode<T> *right)
            : data(item), leftNode(left), rightNode(right) {}
        TreeNode(const T &item)
            : data(item), leftNode(nullptr), rightNode(nullptr) {}
        //拷贝构造
        TreeNode(const TreeNode *treeNode)
            : data(treeNode->data), leftNode(treeNode->leftNode), rightNode(treeNode->rightNode) {}
};

template<class T>
class BinaryTree: public TreeNode<T>
{
    public:
        //无参构造函数
        BinaryTree();
        //带参构造函数
        BinaryTree(const T &item);
        //拷贝构造函数
        BinaryTree(BinaryTree<T> &bt);
        //析构函数
        ~BinaryTree();
        //重载函数：赋值
        BinaryTree<T>& operator=(BinaryTree<T> &bt);

        //释放树节点
        void release();

        //二叉树是否为空
        bool isEmpty();

        //向二叉树插入给定节点
        void insert(const T &theNode);

        //删除二叉树中给定的节点
        void remove(const T &theNode);

        //查找给定节点是否在二叉树中
        bool isFind(const T &theNode);

        //二叉树前序遍历
        void preOrder() const;

        //二叉树中序遍历
        void inOrder() const;

        //二叉树后序遍历
        void postOrder() const;

    private:
        TreeNode<T> *root;
        TreeNode<T> *clone(const TreeNode<T> *bt);
        void release(TreeNode<T> *bt);
        bool isEmpty(TreeNode<T> *bt);
        void insert(const T &theNode, TreeNode<T> *&bt);
        void remove(const T &theNode, TreeNode<T> *&bt);
        bool isFind(const T &theNode, TreeNode<T> * bt);
        BinaryTree *findMin(TreeNode<T> *bt) const;
        BinaryTree *findMax(TreeNode<T> *bt) const;
        void preOrder(TreeNode<T> *bt) const;
        void inOrder(TreeNode<T> *bt) const;
        void postOrder(TreeNode<T> *bt) const;
};


#endif
