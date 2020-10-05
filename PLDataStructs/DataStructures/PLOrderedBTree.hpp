//
//  PLOrderedBTree.hpp
//  PLDataStructs
//
//  Created by Pritesh on 04/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//


#ifndef PLOrderedBTree_hpp
#define PLOrderedBTree_hpp

#include <stdio.h>
#include "PLBTree.hpp"
#include <vector>

class PLTreeNodeData;

/**
 * This class defines a balanced, ordered, binary tree implementation.
 *
 * After every insertion/deletion operation, the tree re-balances itself to maintain the minimum possible height.
 * This self balancing technique is also known as AVL tree.
 */
class PLOrderedBTree : public PLBTree {
private:
    /**
     * Private initializer to initialize a tree with a root node.
     * @note Creation & maintenance of the root node for the tree is managed internally by the class.
     * @param rootNode root node for the tree
     */
    PLOrderedBTree(PLBTreeNode *rootNode);
    
    /**
     * Private method to insert a node in the tree recursively from the root node.
     * @param value Value of the new node to be inserted
     * @param color Color of the new node to be inserted
     * @return Reference of the updated root node of the new balanced tree
     */
    PLBTreeNode * insertNode(PLBTreeNode *tree, int value, std::string color);
    
    /**
     * Private method to remove a node with a given value from the tree.
     *
     * This function seraches the tree, recursively, from the root to find the node & remove it.
     * @param value Value of the node to be removed
     * @return Reference of the updated root node of the new balanced tree
     */
    PLBTreeNode * removeNode(PLBTreeNode *tree, int value);

    /**
     * Private method to remove all the nodes of the given value from the tree.
     *
     * @param color Color of the nodes to be deleted
     * @return Reference of the updated root node of the new balanced tree
     */
    PLBTreeNode * removeNodes(PLBTreeNode *tree, std::string color);
    
public :
    /// Constructors

    /**
     * Initializes a balanced tree with the given value & color for its root node.
     * @param value Root node's value
     * @param color Root node's color in hex format(#RRGGBB)
     */
    PLOrderedBTree(int value, std::string color);
    
    /**
     * Initializes a balanced tree with the list of nodes.
     * @param nodesVector Vector containing values for the tree nodes
     * @see PLTreeNodeData
     */
    PLOrderedBTree(std::vector<PLTreeNodeData*> nodesVector);
    
    /// Virtual functions

    /**
     * @return The left subtree of the balanced binary tree.
     */
    virtual PLOrderedBTree * getLeftSubtree();

    /**
     * @return The right subtree of the balanced binary tree.
     */
    virtual PLOrderedBTree * getRightSubtree();

    /**
     * Inserts a node into the current balanced binary tree & re-balances the tree after the insertion.
     * @param value Value of the node to be inserted
     * @param color Color of the node to be inserted, in hex format(#RRGGBB)
     */
    virtual void insertNode(int value, std::string color);
    
    /**
     * Removes a node with a given value from the tree.
     * @param value Value of the node to be removed
     */
    virtual void removeNode(int value);

    /**
     * Removes all the nodes of the given color from the tree.
     * @param color Color of the nodes to be removed, in hex format(#RRGGBB)
     */
    virtual void removeNodes(std::string color);
};
#endif /* PLOrderedBTree_hpp */
