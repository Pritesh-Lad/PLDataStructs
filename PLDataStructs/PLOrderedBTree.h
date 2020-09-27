//
//  PLOrderedBTree.h
//  PLDataStructs
//
//  Created by Pritesh on 19/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLOrderedBTree : NSObject
+ (PLOrderedBTree*)buildTree:(NSArray*)treeNodes;
- (PLOrderedBTree*)addNodes:(NSArray*)nodes;
- (PLOrderedBTree*)removeNodes:(NSArray*)nodes;
- (void)printPreOrderDescription;
- (void)printInOrderDescription;

@property (nonatomic, assign, readonly) int value;
@property (nonatomic, assign, readonly) NSString *hexColor;
@property (nonatomic, assign, readonly) PLOrderedBTree *leftSubTree;
@property (nonatomic, assign, readonly) PLOrderedBTree *rightSubTree;

@end

NS_ASSUME_NONNULL_END
