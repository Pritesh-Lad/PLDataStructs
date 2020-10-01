//
//  PLBalancedBTree.cpp
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#include "PLBalancedBTree.hpp"
#include "../PLBTreeUtil.cpp"
#include <stack>
#include "PLTreeNodeData.hpp"

#pragma mark - Constructors
PLBalancedBTree::PLBalancedBTree(int value, std::string color) : PLBTree(value, color){
    
}

PLBalancedBTree::PLBalancedBTree(PLBTreeNode *rootNode) : PLBTree(rootNode) {
    
}

PLBalancedBTree::PLBalancedBTree(std::vector<PLTreeNodeData*> nodesVector) : PLBTree(NULL) {
    for (PLTreeNodeData *data : nodesVector) {
        root = insertNode(root, data->getValue(), data->getColor());
    }
}

#pragma mark - PLBTree virtual functions implementation
PLBTree* PLBalancedBTree::getLeftSubtree() {
    return (root->left != NULL) ? new PLBalancedBTree(root->left) : NULL;
}

PLBTree* PLBalancedBTree::getRightSubtree() {
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
PLBTreeNode *leftRotate(PLBTreeNode *node) {
    PLBTreeNode *rightChild = node->right;
    PLBTreeNode *leftOfRightChild = rightChild->left;
    // Perform rotation
    rightChild->left = node;
    node->right = leftOfRightChild;
  
    // Update heights
    node->height = max(heightOfNode(node->left),
                    heightOfNode(node->right)) + 1;
    rightChild->height = max(heightOfNode(rightChild->left),
                    heightOfNode(rightChild->right)) + 1;
  
    // Return new root
    return rightChild;
}

PLBTreeNode *rightRotate(PLBTreeNode *node) {
    PLBTreeNode *leftChild = node->left;
    PLBTreeNode *rightOfLeftChild = leftChild->right;
  
    // Perform rotation
    leftChild->right = node;
    node->left = rightOfLeftChild;
  
    // Update heights
    node->height = max(heightOfNode(node->left),
                    heightOfNode(node->right)) + 1;
    leftChild->height = max(heightOfNode(leftChild->left),
                    heightOfNode(leftChild->right)) + 1;
  
    // Return new root
    return leftChild;
}

PLBTreeNode * PLBalancedBTree::insertNode(PLBTreeNode *tree, int value, std::string color) {
    if (tree == NULL) {
        return new PLBTreeNode(value, color);
    }
    if (value < tree->value) {
        tree->left = insertNode(tree->left, value, color);
    } else {
        tree->right = insertNode(tree->right, value, color);
    }
    
    // increase the height of parent node by 1
    tree->height = max(heightOfNode(tree->left),
                          heightOfNode(tree->right)) + 1;
    
    // get balance of the tree node
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
    
    // Tree is already height-balanced, just return
    return tree;
}

PLBTreeNode * PLBalancedBTree::removeNode(PLBTreeNode *tree, int value) {
    if (tree == NULL) {
        return tree;
    }
    if (value < tree->value) {
        tree->left = removeNode(tree->left, value);
    } else if (value > tree->value) {
        tree->right = removeNode(tree->right, value);
    } else {//value = tree->value
        if (tree->left == NULL) {
            PLBTreeNode *rightSubTree = tree->right;
            tree = NULL;
            return rightSubTree;
        }
        else if (tree->right == NULL) {
            PLBTreeNode *leftSubTree = tree->left;
            tree = NULL;
            return leftSubTree;
        }
        //node has two children
        PLBTreeNode *inorderSuccessor = getInorderSuccessor(tree);
        tree->value = inorderSuccessor->value;
        tree->color = inorderSuccessor->color;
        tree->right = removeNode(tree->right, inorderSuccessor->value);
        //TODO: to remove all the matching nodes
//        if (inorderSuccessor->value == tree->value) {
//            return removeNode(tree, tree->value);
//        }
    }

    if (tree == NULL)
      return tree;

      // Update the height of current node
      tree->height = 1 + max(heightOfNode(tree->left),
                             heightOfNode(tree->right));

      int balance = getBalance(tree);

      // Right rotation
      if (balance > 1 && getBalance(tree->left) >= 0) {
          return rightRotate(tree);
      }
      // Left Right Case
      if (balance > 1 && getBalance(tree->left) < 0) {
          tree->left = leftRotate(tree->left);
          return rightRotate(tree);
      }
      // Left rotation
      if (balance < -1 && getBalance(tree->right) <= 0) {
          return leftRotate(tree);
      }
      // Right Left Case
      if (balance < -1 && getBalance(tree->right) > 0) {
          tree->right = rightRotate(tree->right);
          return leftRotate(tree);
      }

    return tree;
}

PLBTreeNode * PLBalancedBTree::removeNodes(PLBTreeNode *tree, std::string color) {
    //save nodes in pre-order traversal
    if (tree == NULL) {
        return tree;
    }
    std::stack<PLBTreeNode*> nodeStack;
    nodeStack.push(tree);
    PLBTreeNode *newTree = NULL;
    while (nodeStack.empty() == false) {
        PLBTreeNode *node = nodeStack.top();
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
