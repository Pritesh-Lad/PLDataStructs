//
//  PLBalancedBTree.cpp
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#include "PLBalancedBTree.hpp"
#include "../PLBTreeUtil.hpp"
#include <stack>
#include "PLTreeNodeData.hpp"
#include "PLBTreeNode.hpp"

#pragma mark - Constructors
PLBalancedBTree::PLBalancedBTree(int value, std::string color) : PLBTree(value, color){
    
}

PLBalancedBTree::PLBalancedBTree(PLBTreeNode *rootNode) : PLBTree(rootNode) {
    
}

PLBalancedBTree::PLBalancedBTree(std::vector<PLTreeNodeData*> nodesVector) : PLBTree(NULL) {
    for (PLTreeNodeData *data : nodesVector) {
        root = insertNode(root, data->value, data->color);
    }
}

#pragma mark - PLBTree virtual functions implementation
PLBalancedBTree * PLBalancedBTree::getLeftSubtree() {
    return (root->left != NULL) ? new PLBalancedBTree(root->left) : NULL;
}

PLBalancedBTree * PLBalancedBTree::getRightSubtree() {
    return (root->right != NULL) ? new PLBalancedBTree(root->right) : NULL;
}

void PLBalancedBTree::insertNode(int value, std::string color) {
    root = insertNode(root, value, color);
}

void PLBalancedBTree::removeNode(int value) {
    root = removeNode(root, value);
}

void PLBalancedBTree::removeNodes(std::string color) {
    root = removeNodes(root, color);
}

#pragma mark  - Private methods
/**
 * Left rotates the unbalanced node
 */
PLBTreeNode * leftRotate(PLBTreeNode *node) {
    PLBTreeNode *rightChild = node->right;
    PLBTreeNode *leftOfRightChild = rightChild->left;
    // Perform left rotation
    rightChild->left = node;
    node->right = leftOfRightChild;
  
    // Update heights
    node->height = max(heightOfTree(node->left),
                    heightOfTree(node->right)) + 1;
    rightChild->height = max(heightOfTree(rightChild->left),
                    heightOfTree(rightChild->right)) + 1;
  
    // Return the new root node
    return rightChild;
}

/**
 * Right rotates the unbalanced node
 */
PLBTreeNode * rightRotate(PLBTreeNode *node) {
    PLBTreeNode *leftChild = node->left;
    PLBTreeNode *rightOfLeftChild = leftChild->right;
  
    // Perform right rotation
    leftChild->right = node;
    node->left = rightOfLeftChild;
  
    // Update heights
    node->height = max(heightOfTree(node->left),
                    heightOfTree(node->right)) + 1;
    leftChild->height = max(heightOfTree(leftChild->left),
                    heightOfTree(leftChild->right)) + 1;
  
    // Return new root node
    return leftChild;
}

PLBTreeNode * PLBalancedBTree::insertNode(PLBTreeNode *tree, int value, std::string color) {
    // If tree is null, return the new root
    if (tree == NULL) {
        return new PLBTreeNode(value, color);
    }
    // Compare the new value to be inserted with the tree(root) value
    if (value < tree->value) {
        // Insert into left subtree
        tree->left = insertNode(tree->left, value, color);
    } else if (value > tree->value){
        // Insert into right subtree
        tree->right = insertNode(tree->right, value, color);
    } else {
        // Equal value! Simply update the node
        tree->color = color;
        return tree;
    }
    
    // Increase the height of the parent node by 1
    tree->height = max(heightOfTree(tree->left), heightOfTree(tree->right)) + 1;
    // Re-balance the tree
    // Get balance of the tree node
    int balance = getBalance(tree);
    
    // Single right rotation
    if (balance > 1 && value < tree->left->value)  {
        return rightRotate(tree);
    }
    // Left right rotation
    if (balance > 1 && value > tree->left->value)  {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }
    // Single left rotation
    if (balance < -1 && value > tree->right->value)  {
        return leftRotate(tree);
    }
    // Right left rotation
    if (balance < -1 && value < tree->right->value)  {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }
    
    // Tree is already height-balanced, return the updated tree
    return tree;
}

PLBTreeNode * PLBalancedBTree::removeNode(PLBTreeNode *tree, int value) {
    // If tree is null, return.
    if (tree == NULL) {
        return tree;
    }
    // Search for node
    if (value < tree->value) {
        // Search node in the left subtree
        tree->left = removeNode(tree->left, value);
    } else if (value > tree->value) {
        // Search node in the right subtree
        tree->right = removeNode(tree->right, value);
    } else {
        // Node found, check if it has any children
        if (tree->left == NULL || tree->right == NULL) {
            PLBTreeNode *child = tree->left ? tree->left : tree->right;
            if (child == NULL) {
                // No child
                child = tree;
                tree = NULL;
            } else {
                // Single child, copy the child contents to the node
                *tree = *child;
            }
            delete child;
        } else {
            // Node has two children
            // Copy the contents of inorder successor & remove the inorder successor
            PLBTreeNode *inorderSuccessor = getInorderSuccessor(tree);
            tree->value = inorderSuccessor->value;
            tree->color = inorderSuccessor->color;
            tree->right = removeNode(tree->right, inorderSuccessor->value);
        }
    }
    
    if (tree == NULL)
        return tree;
    // Re-balance the tree
    // Update the height of current node
    tree->height = 1 + max(heightOfTree(tree->left),
                           heightOfTree(tree->right));
    
    int balance = getBalance(tree);
    
    // Single right rotation
    if (balance > 1 && getBalance(tree->left) >= 0) {
        return rightRotate(tree);
    }
    // Left Right rotation
    if (balance > 1 && getBalance(tree->left) < 0) {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }
    // Single left rotation
    if (balance < -1 && getBalance(tree->right) <= 0) {
        return leftRotate(tree);
    }
    // Right Left rotation
    if (balance < -1 && getBalance(tree->right) > 0) {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }
    
    return tree;
}

PLBTreeNode * PLBalancedBTree::removeNodes(PLBTreeNode *tree, std::string color) {
    if (tree == NULL) {
        return tree;
    }
    // To remove same colored nodes, create a new tree with the nodes from the current tree, except the nodes matching the given color.
    
    // Iterate the tree in pre-order
    std::stack<PLBTreeNode*> nodeStack;
    nodeStack.push(tree);
    PLBTreeNode *newTree = NULL;
    while (nodeStack.empty() == false) {
        PLBTreeNode *node = nodeStack.top();
        // Copy the nodes, not matching the given color, in a new tree.
        if (node->color.compare(color) != 0) {
            newTree = insertNode(newTree, node->value, node->color);
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
