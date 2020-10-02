//
//  PLBTreeUtil.hpp
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#ifndef PLBTreeUtil_h
#define PLBTreeUtil_h

class PLBTreeNode;

/**
 * Returns maximum of the two integers
 * @param a first integer to compare
 * @param b second integer to compare
 * @return a if a > b, b if a < b
 */
int max(int a, int b);

/**
 * Returns height of a tree
 * @param tree tree
 * @return Height of the tree
 */
int heightOfTree(PLBTreeNode *tree);

/**
 * Returns balance of tree.
 *
 * Balance of a tree is the difference between the height of left & right subtree
 * @param tree tree
 * @return balance of tree
 */
int getBalance(PLBTreeNode *tree);

/**
 * Returns inorder successor of the tree.
 * Inorder successor is the smallest value node from the right subtree of the tree
 *
 * @param tree tree
 * @return Inorder successor node
 */
PLBTreeNode * getInorderSuccessor(PLBTreeNode *tree);

/**
 * Prints inorder description of a binary tree
 * @param tree tree
 */
void printInOrderTraversal(PLBTreeNode *tree);

/**
 * Prints preorder description of a binary tree
 * @param tree tree
 */
void printPreOrderTraversal(PLBTreeNode *tree);

/**
 * Prints postorder description of a binary tree
 * @param tree tree
 */
void printPostOrderTraversal(PLBTreeNode *tree);

#endif /* PLBTreeUtil_h */
