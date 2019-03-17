#include <iostream>
#include "binaryTree.h"
#include "binaryTree.cpp"

using namespace std;

int main()
{
    int root = 6;
    int array[5] = {1, 2, 3, 4, 5};

    BinaryTree<int> bTree(root);

    cout << "create a tree" << endl;
    bTree.insert(array[0]);
    bTree.insert(array[1]);
    bTree.insert(array[2]);
    bTree.insert(array[3]);
    bTree.insert(array[4]);

    cout << "pre order of the tree:" << endl;
    bTree.preOrder();

    cout << "in order of the tree:" << endl;
    bTree.inOrder();

    cout << "post order of the tree:" << endl;
    bTree.postOrder();

    cout << "remove the tree node 3:" << endl;
    bTree.remove(3);

    if (bTree.isFind(3))
        cout << "3 is in this tree!" << endl;
    else
        cout << "3 is removed from this tree" << endl;

    cout << "pre order the tree after removed 3:" << endl;
    bTree.preOrder();
    
    cout << "in order of the tree after removed 3:" << endl;
    bTree.inOrder();

    cout << "post order of the tree after removed 3:" << endl;
    bTree.postOrder();

    if(bTree.isFind(5))
        cout << "5 is in this tree" << endl;
    else
        cout << "5 is not in this tree." <<endl;


    cout << "insert some node to tree:" << endl;
    bTree.insert(7);
    bTree.insert(9);
    bTree.insert(8);
    bTree.insert(10);

    if(bTree.isEmpty())
        cout << "The tree is empty" <<endl;
    else
        cout << "The tree is not empty" << endl;

    cout << "pre/in/post order of the tree after insert some nodes:" << endl;
    bTree.preOrder();

    bTree.inOrder();

    bTree.postOrder();


    return 0;
}
