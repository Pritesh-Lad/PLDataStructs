//
//  PLOrderedBTree.m
//  PLDataStructs
//
//  Created by Pritesh on 19/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "PLOrderedBTree.h"
#import "OrderedBTree.hpp"

@implementation PLOrderedBTree
- (NSString *)greetingString{
    OrderedBTree tree;
    NSString* greeting = [NSString stringWithCString:tree.getStatus().c_str() encoding:[NSString defaultCStringEncoding]];
    return greeting;
}
@end
