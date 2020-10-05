//
//  PLOrderedBTree.cpp
//  PLDataStructs
//
//  Created by Pritesh on 04/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#include "PLOrderedBTree.hpp"
#include "../PLBTreeUtil.hpp"
#include <stack>
#include "PLTreeNodeData.hpp"
#include "PLBTreeNode.hpp"

#pragma mark - Constructors
PLOrderedBTree::PLOrderedBTree(int value, std::string color) : PLBTree(value, color){
    
}

PLOrderedBTree::PLOrderedBTree(PLBTreeNode *rootNode) : PLBTree(rootNode) {
    
}

PLOrderedBTree::PLOrderedBTree(std::vector<PLTreeNodeData*> nodesVector) : PLBTree(NULL) {
    for (PLTreeNodeData *data : nodesVector) {
        root = insertNode(root, data->value, data->color);
    }
}

#pragma mark - PLBTree virtual functions implementation
PLOrderedBTree * PLOrderedBTree::getLeftSubtree() {
    return (root->left != NULL) ? new PLOrderedBTree(root->left) : NULL;
}

PLOrderedBTree * PLOrderedBTree::getRightSubtree() {
    return (root->right != NULL) ? new PLOrderedBTree(root->right) : NULL;
}

void PLOrderedBTree::insertNode(int value, std::string color) {
    root = insertNode(root, value, color);
}

void PLOrderedBTree::removeNode(int value) {
    root = removeNode(root, value);
}

void PLOrderedBTree::removeNodes(std::string color) {
    root = removeNodes(root, color);
}

#pragma mark  - Private methods
PLBTreeNode * PLOrderedBTree::insertNode(PLBTreeNode *tree, int value, std::string color) {
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
    
    // Tree is already height-balanced, return the updated tree
    return tree;
}

PLBTreeNode * PLOrderedBTree::removeNode(PLBTreeNode *tree, int value) {
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
    
    return tree;
}

PLBTreeNode * PLOrderedBTree::removeNodes(PLBTreeNode *tree, std::string color) {
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
