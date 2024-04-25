#ifndef BINARY_TREE_BINARY_TREE_H
#define BINARY_TREE_BINARY_TREE_H

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} treeNode;

typedef treeNode *binaryTree;

void NLR(binaryTree);

void LNR(binaryTree);

void LRN(binaryTree);

void createTree(binaryTree &);

treeNode *createTNode(int);

int insertNode(binaryTree &, int);

treeNode * searchNode(binaryTree, int);

int getHeight(binaryTree);

void printLevelOrder(binaryTree, int);

void printCurrentLevel(binaryTree, int);

void deleteNode(binaryTree&, int);

void substituteNode(binaryTree&, binaryTree&);

#endif //BINARY_TREE_BINARY_TREE_H
