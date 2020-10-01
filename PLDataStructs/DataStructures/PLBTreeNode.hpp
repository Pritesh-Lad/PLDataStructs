//
//  PLOrderedBTree.hpp
//  PLDataStructs
//
//  Created by Pritesh on 19/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#ifndef PLOrderedBTree_hpp
#define PLOrderedBTree_hpp

#include <stdio.h>
#include <string>

class PLBTreeNode {

public:
    PLBTreeNode(int nodeValue, std::string hColor);
    std::string color;
    int value;
    int height;
    PLBTreeNode *left;
    PLBTreeNode *right;
};

#endif /* PLOrderedBTree_hpp */
