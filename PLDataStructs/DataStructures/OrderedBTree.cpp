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
    height = 1;
}

//OrderedBTree::~OrderedBTree() {
//    destroyTree();
//}
//
//void OrderedBTree::destroyTree(OrderedBTree *tree)
//{
//  if(tree!=NULL)
//  {
//    destroyTree(tree->left);
//    destroyTree(tree->right);
//    delete tree;
//  }
//}

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

int heightOfTree(OrderedBTree *tree) {
    if (tree == NULL)
        return 0;
    return tree->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

OrderedBTree *leftRotate(OrderedBTree *node) {
    OrderedBTree *rightChild = node->right;
    OrderedBTree *leftOfRightChild = rightChild->left;
  
    // Perform rotation
    rightChild->left = node;
    node->right = leftOfRightChild;
  
    // Update heights
    node->height = max(heightOfTree(node->left),
                    heightOfTree(node->right)) + 1;
    rightChild->height = max(heightOfTree(rightChild->left),
                    heightOfTree(rightChild->right)) + 1;
  
    // Return new root
    return rightChild;
}

OrderedBTree *rightRotate(OrderedBTree *node) {
    OrderedBTree *leftChild = node->left;
    OrderedBTree *rightOfLeftChild = leftChild->right;
  
    // Perform rotation
    leftChild->right = node;
    node->left = rightOfLeftChild;
  
    // Update heights
    node->height = max(heightOfTree(node->left),
                    heightOfTree(node->right)) + 1;
    leftChild->height = max(heightOfTree(leftChild->left),
                    heightOfTree(leftChild->right)) + 1;
  
    // Return new root
    return leftChild;
}

int getBalance(OrderedBTree *node) {
    if (node == NULL)
        return 0;
    return heightOfTree(node->left) - heightOfTree(node->right);
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
    
    // increase the height of parent node by 1
    tree->height = max(heightOfTree(tree->left),
                          heightOfTree(tree->right)) + 1;
    
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
    
    if (tree == NULL)
      return tree;
    
      // Update the height of current node
      tree->height = 1 + max(heightOfTree(tree->left),
                             heightOfTree(tree->right));
    
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

