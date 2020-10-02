//
//  TreeView.m
//  Example
//
//  Created by Pritesh on 29/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "TreeView.h"
#import "UIColor+Trees.h"

#define NODE_DIAMETER   40
#define PADDING         50

@interface TreeView()
@property (nonatomic, strong) PLTreeWrapper *tree;
@end

@implementation TreeView

- (instancetype)initWithFrame:(CGRect)frame tree:(PLTreeWrapper *)tree{
    self = [super initWithFrame:frame];
    if (self) {
        // Add initialisation code here.
        _tree = tree;
        self.backgroundColor = [UIColor whiteColor];
    }
    return self;
}

// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
    CGPoint drawPoint = CGPointMake(self.center.x, 30);
    [self drawNode:self.tree atPoint:drawPoint];
}

- (void)drawNode:(PLTreeWrapper*)node atPoint:(CGPoint)point{
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetLineWidth(context, 2.0);
    CGContextSetStrokeColorWithColor(context,
                                     [UIColor blueColor].CGColor);
    CGRect rectangle = CGRectMake(point.x-NODE_DIAMETER/2, point.y-NODE_DIAMETER/2,
                                  NODE_DIAMETER, NODE_DIAMETER);
    CGContextAddEllipseInRect(context, rectangle);
    CGContextStrokePath(context);
    CGContextSetFillColorWithColor(context, [UIColor colorFromHexString:node.hexColor].CGColor);
    CGContextFillEllipseInRect(context, rectangle);
    // Set value to the node
    NSString *value = [NSString stringWithFormat:@"%d", node.value];
    NSDictionary *attr = @{
        NSFontAttributeName:[UIFont systemFontOfSize:20],
        NSForegroundColorAttributeName:[UIColor blackColor]
    };
    CGSize textSize = [value sizeWithAttributes:attr];
    CGPoint textPoint = CGPointMake(point.x - textSize.width/2,
                                    point.y - textSize.height/2);
    [value drawAtPoint:textPoint withAttributes:attr];
    // Recur for subTrees
    CGFloat deltaX = pow(2,node.height-2);
    if (node.leftSubTree) {
        CGPoint drawPoint = CGPointMake(point.x - deltaX*NODE_SEPARATION,
                                        point.y + NODE_SEPARATION);
        // Draw line to the left sub trees
        [self drawLineFromPoint:point toPoint:drawPoint];
        // Draw left sub tree
        [self drawNode:node.leftSubTree atPoint:drawPoint];
    }
    if (node.rightSubTree) {
        CGPoint drawPoint = CGPointMake(point.x + deltaX*NODE_SEPARATION,
                                        point.y + NODE_SEPARATION);
        // Draw line to the right sub trees
        [self drawLineFromPoint:point toPoint:drawPoint];
        // Draw right sub tree
        [self drawNode:node.rightSubTree atPoint:drawPoint];
    }
}

- (void)drawLineFromPoint:(CGPoint)fromPoint toPoint:(CGPoint)toPoint {
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetLineWidth(context, 2.0);
    CGContextSetStrokeColorWithColor(context, [UIColor blueColor].CGColor);
    CGContextMoveToPoint(context, fromPoint.x, fromPoint.y);
    CGContextAddLineToPoint(context, toPoint.x, toPoint.y);
    CGContextStrokePath(context);
}

@end
