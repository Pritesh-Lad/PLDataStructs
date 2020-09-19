//
//  OrderedBTree.cpp
//  PLDataStructs
//
//  Created by Pritesh on 19/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#include "OrderedBTree.hpp"

OrderedBTree::OrderedBTree() {
    status = "New tree";
}

std::string OrderedBTree::getStatus() {
    return status;
}
