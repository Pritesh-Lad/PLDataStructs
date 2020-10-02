//
//  PLTreeWrapper.h
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Defines options for printing tree descriptions
typedef NS_ENUM(NSInteger, PLTreeDescription) {
    PLTreeDescriptionInOrder,
    PLTreeDescriptionPreOrder,
    PLTreeDescriptionPostOrder
};

@interface PLTreeWrapper : NSObject
/// Value of tree's root
@property (nonatomic, assign, readonly) int value;

/// Color of tree's root in hex format(#RRGGBB)
@property (nonatomic, assign, readonly) NSString *hexColor;

/// Height of the tree
@property (nonatomic, assign) int height;

/// left subtree
@property (nonatomic, assign, readonly) PLTreeWrapper *leftSubTree;

/// right subtree
@property (nonatomic, assign, readonly) PLTreeWrapper *rightSubTree;

/**
 * Creates a balanced binary tree implementation
 * @param nodes NSArray containing dictionary, where each dictionary has 'value' & 'color'
 * @return A balanced binary tree
 */
+ (PLTreeWrapper*)balancedBTreeWithNodes:(NSArray<NSDictionary*>*)nodes;

//Operations

/**
 * Adds given nodes to the tree
 * @param nodes Nodes to add.
 * @note NSArray containing dictionary, where each dictionary has a 'value' & a 'color'
 */
- (void)addNodes:(NSArray *)nodes;

/**
 * Removes nodes from the tree
 * @param nodes nodes to remove
 * @note NSArray containing dictionary, where each dictionary has a 'value' & a 'color'
 * */
- (void)removeNodes:(NSArray*)nodes;

//Describe Tree
/**
 * Prints tree description in the defined format
 * @param descOrder Format to be used for printing the tree description
 * @see PLTreeDescription
 */
- (void)describeTree:(PLTreeDescription)descOrder;

@end

