//
//  OrderedBTree.cpp
//  PLDataStructs
//
//  Created by Pritesh on 19/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#include "PLBTreeNode.hpp"
#include <stack>

PLBTreeNode::PLBTreeNode(int nodeValue, std::string hexColor) {
    value = nodeValue;
    color = hexColor;    
    left = NULL;
    right = NULL;
    height = 1;
}
