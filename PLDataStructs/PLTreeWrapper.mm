//
//  PLTreeWrapper.m
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "PLTreeWrapper.h"
#import "PLBalancedBTree.hpp"
#import "PLTreeNodeData.hpp"

#define NODE_VAL_KEY    @"value"
#define NODE_COLOR_KEY  @"color"

@interface PLTreeWrapper()
@property (nonatomic, assign) PLBTree *tree;
@end

@implementation PLTreeWrapper

+ (PLTreeWrapper*)balancedBTreeWithNodes:(NSArray*)nodes{
    std::vector<PLTreeNodeData*> nodeVector;
    for (NSDictionary *node in nodes) {
        int value = [node[NODE_VAL_KEY] intValue];
        NSString *color = node[NODE_COLOR_KEY];
        PLTreeNodeData *nodeData = new PLTreeNodeData(value, [color cStringUsingEncoding:[NSString defaultCStringEncoding]]);
        nodeVector.push_back(nodeData);
    }
    PLBalancedBTree *tree = new PLBalancedBTree(nodeVector);
    return [[PLTreeWrapper alloc] initWithBTree:tree];
}

- (instancetype)initWithBTree:(PLBTree*)bTree {
    self = [super init];
    if (self) {
        // Add initialisation code here.
        _tree = bTree;
    }
    return self;
}

- (void)dealloc {
    _tree = nil;
}

#pragma mark - Tree properties
- (int)value {
    return  self.tree->getValue();
}

- (NSString*)hexColor{
    return [NSString stringWithCString:self.tree->getColor().c_str() encoding:[NSString defaultCStringEncoding]];
}

- (int)height {
    return self.tree->getHeight();
}

- (PLTreeWrapper*)leftSubTree{
    PLBTree *left = self.tree->getLeftSubtree();
    if (left != NULL) {
        return [[PLTreeWrapper alloc] initWithBTree:left];
    }
    return nil;
}

- (PLTreeWrapper*)rightSubTree{
    PLBTree *right = self.tree->getRightSubtree();
    if (right != NULL) {
        return [[PLTreeWrapper alloc] initWithBTree:right];
    }
    return nil;
}

#pragma mark - Describe Tree
- (void)describeTree:(PLTreeDescription)descOrder {
    switch (descOrder) {
        case PLTreeDescriptionInOrder:
            self.tree->printInOrder();
            break;
        case PLTreeDescriptionPreOrder:
            self.tree->printPreOrder();
            break;
        case PLTreeDescriptionPostOrder:
            self.tree->printPostOrder();
            break;
        default:
            self.tree->printPreOrder();
            break;
    }
}

#pragma makrk - Tree Operations
- (void)addNodes:(NSArray *)nodes {
    for (NSDictionary *treeNode in nodes) {
        int value = [treeNode[NODE_VAL_KEY] intValue];
        NSString *color = treeNode[NODE_COLOR_KEY];
        NSLog(@"Adding Node(%d, %@)", value, color);
        self.tree->insertNode(value, [color cStringUsingEncoding:[NSString defaultCStringEncoding]]);
    }
}

- (void)removeNodes:(NSArray *)nodes {
    for (NSDictionary *node in nodes) {
        if (node[NODE_VAL_KEY]) {
            int value = [node[NODE_VAL_KEY] intValue];
            NSLog(@"Removing nodes with value - %d", value);
            self.tree->removeNode(value);
        } else if (node[NODE_COLOR_KEY]) {
            NSString *color = node[NODE_COLOR_KEY];
            NSLog(@"Removing nodes with color - %@", color);
            self.tree->removeNodes([color cStringUsingEncoding:[NSString defaultCStringEncoding]]);
        }
    }
}

@end
