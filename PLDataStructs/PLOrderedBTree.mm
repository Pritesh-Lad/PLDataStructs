//
//  PLOrderedBTree.m
//  PLDataStructs
//
//  Created by Pritesh on 19/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "PLOrderedBTree.h"
#import "OrderedBTree.hpp"

#define NODE_VAL_KEY    @"value"
#define NODE_COLOR_KEY  @"color"

@interface PLOrderedBTree()
@property (nonatomic, assign) OrderedBTree *tree;
@end

@implementation PLOrderedBTree

- (instancetype)initWithTree:(OrderedBTree*)tree{
    self = [super init];
    if (self && tree != NULL) {
        // Add initialisation code here.
        _tree = tree;
    }else{
        self = nil;
    }
    return self;
}

#pragma mark - Property getters
- (int)value{
    return  self.tree->value;
}

- (NSString*)hexColor{
    return [NSString stringWithCString:self.tree->color.c_str() encoding:[NSString defaultCStringEncoding]];
}

- (PLOrderedBTree*)leftSubTree{
    return [[PLOrderedBTree alloc] initWithTree:self.tree->left];
}

- (PLOrderedBTree*)rightSubTree{
    return [[PLOrderedBTree alloc] initWithTree:self.tree->right];
}

- (int)height {
    return self.tree->height;
}
#pragma mark - operations
- (void)printPreOrderDescription {
    NSLog(@"#PreOrderDescription#");
    OrderedBTree::printPreOrder(self.tree);
}

- (void)printInOrderDescription {
    NSLog(@"#InOrderDescription#");
    OrderedBTree::printInorder(self.tree);
}

+ (PLOrderedBTree*)buildTree:(NSArray *)treeNodes{
    NSLog(@"#Building Tree#");
    return [[[PLOrderedBTree alloc] init] addNodes:treeNodes];
}

- (PLOrderedBTree*)addNodes:(NSArray *)nodes{
    for (NSDictionary *treeNode in nodes) {
        int value = [treeNode[NODE_VAL_KEY] intValue];
        NSString *color = treeNode[NODE_COLOR_KEY];
        NSLog(@"Adding Node(%d, %@)", value, color);
        self.tree = OrderedBTree::insertNode(self.tree, value, [color cStringUsingEncoding:[NSString defaultCStringEncoding]]);
    }
    return self;
}

- (PLOrderedBTree*)removeNodes:(NSArray *)nodes{
    for (NSDictionary *node in nodes) {
        if (node[NODE_VAL_KEY]) {
            int value = [node[NODE_VAL_KEY] intValue];
            NSLog(@"Removing nodes with value - %d", value);
            self.tree = OrderedBTree::removeNodes(self.tree, value);
        } else if (node[NODE_COLOR_KEY]) {
            NSString *color = node[NODE_COLOR_KEY];
            NSLog(@"Removing nodes with color - %@", color);
            self.tree = OrderedBTree::removeNodes(self.tree, [color cStringUsingEncoding:[NSString defaultCStringEncoding]]);
        }
    }
    return self;
}
@end
