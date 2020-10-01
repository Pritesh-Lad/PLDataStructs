//
//  PLTreeWrapper.m
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "PLTreeWrapper.h"
#import "PLBalancedBTree.hpp"
#define NODE_VAL_KEY    @"value"
#define NODE_COLOR_KEY  @"color"

@interface PLTreeWrapper()
@property (nonatomic, assign) PLBTree *tree;
@end

@implementation PLTreeWrapper

+ (PLTreeWrapper*)balancedBTreeWithNodes:(NSArray*)nodes{
    NSDictionary *root = nodes[0];
    int rootValue = [root[NODE_VAL_KEY] intValue];
    NSString *rootColor = root[NODE_COLOR_KEY];
    PLBTree *tree = new PLBalancedBTree(rootValue, [rootColor cStringUsingEncoding:[NSString defaultCStringEncoding]]);
    PLTreeWrapper *wrapperTree = [[PLTreeWrapper alloc] initWithBTree:tree];
    //Add remaining nodes
    NSMutableArray *leaves = nodes.mutableCopy;
    [leaves removeObjectAtIndex:0];
    [wrapperTree addNodes:leaves];
    return wrapperTree;
}

- (instancetype)initWithBTree:(PLBTree*)bTree {
    self = [super init];
    if (self) {
        // Add initialisation code here.
        _tree = bTree;
    }
    return self;
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
