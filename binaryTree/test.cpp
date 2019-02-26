#include <iostream>
#include "binaryTree.h"
#include "binaryTree.cpp"

using namespace std;

int main()
{
    int root = 6;
    int array[5] = {1, 2, 3, 4, 5};

    BinaryTree<int> bTree(root);

    bTree.insert(array[0]);
    bTree.insert(array[1]);
    bTree.insert(array[2]);
    bTree.insert(array[3]);
    bTree.insert(array[4]);

    bTree.preOrder();

    bTree.inOrder();

    bTree.postOrder();

    bTree.remove(3); //有bug

    bTree.preOrder();

    if(bTree.isFind(5))
        cout << "5 is in this tree" << endl;
    else
        cout << "5 is not in this tree." <<endl;


    bTree.insert(7);
    bTree.insert(9);
    bTree.insert(8);
    bTree.insert(10);

    if(bTree.isEmpty())
        cout << "The tree is empty" <<endl;
    else
        cout << "The tree is not empty" << endl;

    bTree.preOrder();

    bTree.inOrder();

    bTree.postOrder();


    return 0;
}
