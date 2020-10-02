//
//  ViewController.m
//  Example
//
//  Created by Pritesh on 20/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "ViewController.h"
#import "TreeView.h"
#import "NSJSONSerialization+Trees.h"

#define CREATE_TREE_FILE_NAME    @"CreateTree"
#define ADD_NODES_FILE_NAME      @"AddNodes"
#define REMOVE_NODES_FILE_NAME   @"RemoveNodes"

@interface ViewController ()
@property (nonatomic, strong) PLTreeWrapper *tree;
@property (nonatomic, strong) TreeView *treeView;
@property (nonatomic, strong) UIScrollView *scrollView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    _scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 100, CGRectGetWidth(self.view.frame), CGRectGetHeight(self.view.frame)-100)];
    [self.view addSubview:self.scrollView];
}

#pragma mark - Private methods
- (void)createTree {
    NSArray *createNodes = [NSJSONSerialization jsonObjectFromFile:CREATE_TREE_FILE_NAME];
    _tree = [PLTreeWrapper balancedBTreeWithNodes:createNodes];
    [self renderTree];
}

- (void)addNodesToTree {
    NSArray *nodesToAdd = [NSJSONSerialization jsonObjectFromFile:ADD_NODES_FILE_NAME];
    [self.tree addNodes:nodesToAdd];
    [self renderTree];
}

- (void)removeNodesFromTree {
    NSArray *nodesToRemove = [NSJSONSerialization jsonObjectFromFile:REMOVE_NODES_FILE_NAME];
    [self.tree removeNodes:nodesToRemove];
    [self renderTree];
}

- (void)renderTree {
    if (self.treeView) {
        [self.treeView removeFromSuperview];
        self.treeView = nil;
    }
    CGFloat deltaX = pow(2, self.tree.height-1)-1;;
    CGSize contentSize = CGSizeMake(2*deltaX*NODE_SEPARATION + 50, self.tree.height*NODE_SEPARATION + 50);
    _treeView = [[TreeView alloc] initWithFrame:CGRectMake(0, 0, contentSize.width, contentSize.height) tree:self.tree];
    [self.scrollView setContentSize:contentSize];
    [self.scrollView setContentOffset:CGPointMake(self.treeView.center.x-CGRectGetWidth(self.view.frame)/2, 0)];
    [self.scrollView addSubview:self.treeView];    
}

#pragma mark - IBActions
- (IBAction)createTree:(id)sender {
    [self createTree];
    [self.tree describeTree:PLTreeDescriptionPreOrder];
}

- (IBAction)addNodes:(id)sender {
    [self addNodesToTree];
    [self.tree describeTree:PLTreeDescriptionPreOrder];
}

- (IBAction)removeNodes:(id)sender {
    [self removeNodesFromTree];
    [self.tree describeTree:PLTreeDescriptionPreOrder];}
@end
