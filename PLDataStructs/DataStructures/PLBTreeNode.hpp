//
//  PLOrderedBTree.hpp
//  PLDataStructs
//
//  Created by Pritesh on 19/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#ifndef PLBTreeNode_hpp
#define PLBTreeNode_hpp

#include <stdio.h>
#include <string>
/**
 * Represents a node in a binary tree
 */
class PLBTreeNode {

public:
    /// Node value
    int value;
    
    /// Hex color string in format(#RRGGBB)
    std::string color;
    
    /// Height of the subtree with this node as root
    int height;
    
    /// Left subtree
    PLBTreeNode *left;
    
    /// Right subtree
    PLBTreeNode *right;
    
    /**
     * Initializes a node with integer value & hex color
     * @param nodeValue integer value for node
     * @param hexColor color in hex format(#RRGGBB)
     */
    PLBTreeNode(int nodeValue, std::string hexColor);    
};

#endif /* PLBTreeNode_hpp */
