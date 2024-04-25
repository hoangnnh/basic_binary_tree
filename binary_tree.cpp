#include "binary_tree.h"

#include <iostream>


void NLR(binaryTree root) {
    if (root != nullptr) {
        std::cout << root->val << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(binaryTree root) {
    if (root != nullptr) {
        LNR(root->left);
        std::cout << root->val << " ";
        LNR(root->right);
    }
}

void LRN(binaryTree root) {
    if (root != nullptr) {
        LRN(root->left);
        LRN(root->right);
        std::cout << root->val << " ";
    }
}

void createTree(binaryTree &tree) {
    tree = nullptr;
}

treeNode *createTNode(int val) {
    treeNode *p = new treeNode;

    p->val = val;
    p->left = nullptr;
    p->right = nullptr;
}

int insertNode(binaryTree &tree, int val) {
    if (tree) {
        if (tree->val == val) {
            return 0;
        } else if (tree->val > val) {
            return insertNode(tree->left, val);
        } else {
            return insertNode(tree->right, val);
        }
    }

    tree = new treeNode;

    tree->val = val;
    tree->left = nullptr;
    tree->right = nullptr;

    return 1;
}

treeNode *searchNode(binaryTree root, int val) {
    treeNode *p = root;

    while (p != nullptr) {
        if (val == p->val) {
            return p;
        } else {
            if (val < p->val) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
    }

    return nullptr;
}

void substituteNode(binaryTree &p, binaryTree &tree) {
    if (tree->left != nullptr) {
        substituteNode(p, tree->left);
    } else {
        p->val = tree->val;
        p = tree;
        tree = tree->right;
    }
}

void deleteNode(binaryTree &tree, int val) {
    if (tree != nullptr) {
        if (tree->val < val) {
            deleteNode(tree->right, val);
        } else if (tree->val > val) {
            deleteNode(tree->left, val);
        } else {
            treeNode *p = tree;

            if (tree->left == nullptr) {
                tree = tree->right;
            } else if (tree->right == nullptr) {
                tree = tree->left;
            } else {
                substituteNode(p, tree->right);
            }

            delete p;
        }
    } else {
        std::cout << "Node with value " << val << " not found.\n";
    }
}

int getHeight(binaryTree tree) {
    if (tree == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(tree->left);

    int rightHeight = getHeight(tree->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    return rightHeight + 1;

}

void printLevelOrder(binaryTree tree, int height) {
    for (int i = 1; i <= height; i++) {
        printCurrentLevel(tree, i);
    }
}

void printCurrentLevel(binaryTree tree, int level) {
    if (tree == nullptr)
        return;
    if (level == 1) {
        std::cout << tree->val << " ";
    } else {
        printCurrentLevel(tree->left, level - 1);
        printCurrentLevel(tree->right, level - 1);
    }
}