//
//  PLTree.cpp
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#include "PLBTree.hpp"
#include "../PLBTreeUtil.hpp"

PLBTree::PLBTree(int value, std::string color) {
    root = new PLBTreeNode(value, color);
}

PLBTree::PLBTree(PLBTreeNode *rootNode) {
    root = rootNode;
}

int PLBTree::getValue() {
    return root->value;
}

std::string PLBTree::getColor() {
    return root->color;
}

int PLBTree::getHeight() {
    return root->height;
}

void PLBTree::printInOrder() {
    printInOrderTraversal(root);
}

void PLBTree::printPreOrder() {
    printPreOrderTraversal(root);
}

void PLBTree::printPostOrder() {
    printPostOrderTraversal(root);
}
