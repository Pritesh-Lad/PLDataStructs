//
//  TreeView.h
//  Example
//
//  Created by Pritesh on 29/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLTreeWrapper.h"
#define NODE_SEPARATION    50

NS_ASSUME_NONNULL_BEGIN
/**
 * Renders a tree in a visual format
 */
@interface TreeView : UIView
- (instancetype)initWithFrame:(CGRect)frame tree:(PLTreeWrapper*)tree;
@end

NS_ASSUME_NONNULL_END
