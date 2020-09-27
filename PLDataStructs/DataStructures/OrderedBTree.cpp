//
//  OrderedBTree.cpp
//  PLDataStructs
//
//  Created by Pritesh on 19/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#include "OrderedBTree.hpp"
#include <stack>

OrderedBTree::OrderedBTree(int nodeValue, std::string hColor) {
    value = nodeValue;
    color = hColor;    
    left = NULL;
    right = NULL;
}

void OrderedBTree::printInorder(OrderedBTree *tree) {
    if (tree != NULL) {
        OrderedBTree::printInorder(tree->left);
        printf("\nvalue = %d, color = %s",tree->value,tree->color.c_str());
        OrderedBTree::printInorder(tree->right);
    }
}

void OrderedBTree::printPreOrder(OrderedBTree *tree) {
    if (tree != NULL) {
        printf("\nvalue = %d, color = %s",tree->value,tree->color.c_str());
        OrderedBTree::printPreOrder(tree->left);
        OrderedBTree::printPreOrder(tree->right);
    }
}

OrderedBTree * OrderedBTree::insertNode(OrderedBTree *tree, int value, std::string color) {
    if (tree == NULL) {
        return new OrderedBTree(value, color);
    }
    if (value < tree->value) {
        tree->left = OrderedBTree::insertNode(tree->left, value, color);
    } else {
        tree->right = OrderedBTree::insertNode(tree->right, value, color);
    }
    return tree;
}

OrderedBTree * getInorderSuccessor(OrderedBTree *tree) {
    OrderedBTree * current = tree->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

OrderedBTree * OrderedBTree::removeNodes(OrderedBTree *tree, int value) {
    if (tree == NULL) {
        return tree;
    }
    if (value < tree->value) {
        tree->left = removeNodes(tree->left, value);
    } else if (value > tree->value) {
        tree->right = OrderedBTree::removeNodes(tree->right, value);
    } else {//value = tree->value
        if (tree->left == NULL) {
            OrderedBTree *rightSubTree = tree->right;
            tree = NULL;
            return rightSubTree;
        }
        else if (tree->right == NULL) {
            OrderedBTree *leftSubTree = tree->left;
            tree = NULL;
            return leftSubTree;
        }
        //node has two children
        OrderedBTree *inorderSuccessor = getInorderSuccessor(tree);
        tree->value = inorderSuccessor->value;
        tree->color = inorderSuccessor->color;
        tree->right = OrderedBTree::removeNodes(tree->right, inorderSuccessor->value);
        //TODO: to remove all the matching nodes
//        if (inorderSuccessor->value == tree->value) {
//            return removeNode(tree, tree->value);
//        }
    }
    return tree;
}

OrderedBTree * OrderedBTree::removeNodes(OrderedBTree *tree, std::string color) {
    //save nodes in pre-order traversal
    if (tree == NULL) {
        return tree;
    }
    std::stack<OrderedBTree*> nodeStack;
    nodeStack.push(tree);
    OrderedBTree *newTree = NULL;
    while (nodeStack.empty() == false) {
        OrderedBTree *node = nodeStack.top();
        if (node->color.compare(color) != 0) {
            newTree = OrderedBTree::insertNode(newTree, node->value, node->color);
        }
        nodeStack.pop();
        if (node->right) {
            nodeStack.push(node->right);
        }
        if (node->left) {
            nodeStack.push(node->left);
        }
    }
    return newTree;
}

