//
//  PLTreeWrapper.h
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PLTreeDescription) {
    PLTreeDescriptionInOrder,
    PLTreeDescriptionPreOrder,
    PLTreeDescriptionPostOrder
};

@interface PLTreeWrapper : NSObject

@property (nonatomic, assign, readonly) int value;
@property (nonatomic, assign, readonly) NSString *hexColor;
@property (nonatomic, assign, readonly) PLTreeWrapper *leftSubTree;
@property (nonatomic, assign, readonly) PLTreeWrapper *rightSubTree;
@property (nonatomic, assign) int height;

+ (PLTreeWrapper*)balancedBTreeWithNodes:(NSArray*)nodes;
//Operations
- (void)addNodes:(NSArray *)nodes;
- (void)removeNodes:(NSArray*)nodes;

//Describe Tree
- (void)describeTree:(PLTreeDescription)descOrder;

@end

