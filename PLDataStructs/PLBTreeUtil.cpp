//
//  PLBTreeUtil.cpp
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#include <stdio.h>
#include "PLBTreeNode.hpp"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int heightOfTree(PLBTreeNode *tree) {
    if (tree == NULL)
        return 0;
    return tree->height;
}

int getBalance(PLBTreeNode *tree) {
    if (tree == NULL)
        return 0;
    return heightOfTree(tree->left) - heightOfTree(tree->right);
}

PLBTreeNode * getInorderSuccessor(PLBTreeNode *tree) {
    PLBTreeNode * current = tree->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

#pragma mark - BTree Traversals
void printInOrderTraversal(PLBTreeNode *tree) {
    if (tree != NULL) {
        printInOrderTraversal(tree->left);
        printf("\nvalue = %d, color = %s",tree->value,tree->color.c_str());
        printInOrderTraversal(tree->right);
    }
}

void printPreOrderTraversal(PLBTreeNode *tree) {
    if (tree != NULL) {
        printf("\nvalue = %d, color = %s",tree->value,tree->color.c_str());
        printPreOrderTraversal(tree->left);
        printPreOrderTraversal(tree->right);
    }
}

void printPostOrderTraversal(PLBTreeNode *tree) {
    if (tree != NULL) {
        printPostOrderTraversal(tree->left);
        printPostOrderTraversal(tree->right);
        printf("\nvalue = %d, color = %s",tree->value,tree->color.c_str());
    }
}
