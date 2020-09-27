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

class OrderedBTree {

public:
    OrderedBTree(int nodeValue, std::string hColor);
    std::string color;
    int value;
    OrderedBTree *left;
    OrderedBTree *right;
    
    static OrderedBTree * insertNode(OrderedBTree *tree, int value, std::string color);
    static void printInorder(OrderedBTree *tree);
    static void printPreOrder(OrderedBTree *tree);
    static OrderedBTree * removeNodes(OrderedBTree *tree, int value);
    static OrderedBTree * removeNodes(OrderedBTree *tree, std::string color);
};

#endif /* PLOrderedBTree_hpp */
