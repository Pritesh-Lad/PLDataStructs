//
//  PLBTree.hpp
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#ifndef PLBTree_hpp
#define PLBTree_hpp

#include <stdio.h>
#include <string>

class PLBTreeNode;

/**
 * Base class implementation for a binary tree.
 *
 * This class can be extended to define different binary tree implementations.
 * For example,
 *     Binary Search Trees, AVL Trees, etc.
 */
class PLBTree {    
protected :
    /// Root node of the tree
    PLBTreeNode *root;
    
    /**
     * Protected initializer to initialize a tree with a root node.
     * @note Creation & maintenance of the root node for the tree is managed internally by the class.
     * @param rootNode root node for the tree
     */
    PLBTree(PLBTreeNode *rootNode);
    
    /**
     * Default destructor
     */
    ~PLBTree();
public:
    /**
     * Initializes a tree with the given value & color for its root node.
     * @param value Root node's value
     * @param color Root node's color in hex format(#RRGGBB)
     */
    PLBTree(int value, std::string color);
         
    /**
     * Returns value of the trees root node
     * @return Root node's integer value
     */
    int getValue();

    /**
     * Returns color of the tree's root node in hex format(#RRGGBB)
     * @return Root node's hex color
     */
    std::string getColor();
    
    /**
     * Returns height of the tree
     * @return Height of the tree
     */
    int getHeight();
    
    /**
     * Returns left sub tree of the tree
     *
     * Derived binary tree implementation must implement this function to return the specific
     * tree type.
     * @see PLBalancedBTree
     * @return An object reference of a subclass of PLBTree
     */
    virtual PLBTree * getLeftSubtree() = 0;
    
    /**
     * Returns right sub tree of the tree
     *
     * Derived binary tree implementation must implement this function to return the specific
     * tree type.
     * @see PLBalancedBTree
     * @return An object reference of a subclass of PLBTree
     */
    virtual PLBTree * getRightSubtree() = 0;
    
    /**
     * Pure virtual function to insert a node into current binary tree.
     *
     * Derived binary tree implementation must implement this function to insert a new node
     * following strategy a suitable for the derived implementation.
     * For example, a balanced tree re-balances the tree after every insertion
     * @param value Value of the node to be inserted
     * @param color Color of the node to be inserted, in hex format(#RRGGBB)
     * @see PLBalancedBTree
     */
    virtual void insertNode(int value, std::string color) = 0;
    
    /**
     * Pure virtual function to remove a node with a given value from the tree.
     *
     * Derived binary tree implementation must implement this function to remove a node
     * following strategy a suitable for the derived implementation.
     * For example, a balanced tree re-balances the tree after every deletion
     * @param value Vlaue of the node to be removed
     * @see PLBalancedBTree
     */
    virtual void removeNode(int value) = 0;
    
    /**
     * Pure virtual function to remove all nodes of the given color from the tree.
     *
     * Derived binary tree implementation must implement this function to remove all similar
     * colored nodes following a strategy suitable for the derived implementation.
     * For example, a balanced tree re-balances the tree after every deletion
     * @param color Color of the nodes to be removed, in hex format(#RRGGBB)
     * @see PLBalancedBTree
     */
    virtual void removeNodes(std::string color) = 0;
         
    /**
     * Prints inorder traversal of the binary tree.
     */
    void printInOrder();
    
    /**
     * Prints preorder traversal of the binary tree.
     */
    void printPreOrder();

    /**
     * Prints postorder traversal of the binary tree.
     */
    void printPostOrder();
};

#endif /* PLBTree_hpp */
