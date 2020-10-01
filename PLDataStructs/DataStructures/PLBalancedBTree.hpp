//
//  PLBalancedBTree.hpp
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#ifndef PLBalancedBTree_hpp
#define PLBalancedBTree_hpp

#include <stdio.h>
#include "PLBTree.hpp"
#include <vector>

class PLTreeNodeData;

class PLBalancedBTree : public PLBTree {
private:
    PLBalancedBTree(PLBTreeNode *rootNode);
    PLBTreeNode * insertNode(PLBTreeNode *tree, int value, std::string color);
    PLBTreeNode * removeNode(PLBTreeNode *tree, int value);
    PLBTreeNode * removeNodes(PLBTreeNode *tree, std::string color);
public :
    PLBalancedBTree(int value, std::string color);
    PLBalancedBTree(std::vector<PLTreeNodeData*> nodesVector);
    
    virtual PLBalancedBTree * getLeftSubtree();
    virtual PLBalancedBTree * getRightSubtree();
   //Tree operations
    //Insert value
    virtual void insertNode(int value, std::string color);
    //Remove by value
    virtual void removeNode(int value);
    //Remove by color
    virtual void removeNodes(std::string color);
};

#endif /* PLBalancedBTree_hpp */
