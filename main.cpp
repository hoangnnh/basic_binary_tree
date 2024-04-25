#include <iostream>

#include "binary_tree.h"

using std::cout, std::cin;

int main() {

    binaryTree tree;
    createTree(tree);

    insertNode(tree, 3);
    insertNode(tree, 5);
    insertNode(tree, 1);
    insertNode(tree, 2);
    insertNode(tree, 8);
    insertNode(tree, 6);
    insertNode(tree, 10);

    NLR(tree);
    cout << "\n";
    LNR(tree);
    cout << "\n";
    LRN(tree);
    cout << "\n";

    return 0;
}
