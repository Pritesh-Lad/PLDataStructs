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
#include "PLBTreeNode.hpp"

class PLBTree {    
protected :
    PLBTreeNode *root;
    PLBTree(PLBTreeNode *rootNode);
public:
    PLBTree(int value, std::string color);

    int getValue();
    std::string getColor();
    int getHeight();
    
    virtual PLBTree * getLeftSubtree() = 0;
    virtual PLBTree * getRightSubtree() = 0;
    
    // Describe/Traverse tree
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
    
    //Tree operations
    //Insert value
    virtual void insertNode(int value, std::string color) = 0;
    //Remove by value
    virtual void removeNode(int value) = 0;
    //Remove by color
    virtual void removeNodes(std::string color) = 0;
};

#endif /* PLBTree_hpp */
