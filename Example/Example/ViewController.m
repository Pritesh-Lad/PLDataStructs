//
//  ViewController.m
//  Example
//
//  Created by Pritesh on 20/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "ViewController.h"
#import <PLDataStructs/PLDataStructs.h>

#define CREATE_TREE_FILE_NAME    @"CreateTree"
#define ADD_NODES_FILE_NAME      @"AddNodes"
#define REMOVE_NODES_FILE_NAME   @"RemoveNodes"

@interface ViewController ()
@property (nonatomic, strong) PLOrderedBTree *tree;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

#pragma mark - Private methods
- (void)createTree {
    NSArray *createNodes = [self jsonTreeNodesFromFile:CREATE_TREE_FILE_NAME];
    _tree = [PLOrderedBTree buildTree:createNodes];
}

- (void)addNodesToTree {
    NSArray *nodesToAdd = [self jsonTreeNodesFromFile:ADD_NODES_FILE_NAME];
    _tree = [self.tree addNodes:nodesToAdd];
}

- (void)removeNodesFromTree {
    NSArray *nodesToRemove = [self jsonTreeNodesFromFile:REMOVE_NODES_FILE_NAME];
    _tree = [self.tree removeNodes:nodesToRemove];
}

- (NSArray*)jsonTreeNodesFromFile:(NSString*)file{
    NSArray *nodes;
    NSError *error;
    @try {
        NSString *filePath = [[NSBundle mainBundle] pathForResource:file ofType:@"json"];
        NSString *content = [NSString stringWithContentsOfFile:filePath
                                                      encoding:NSUTF8StringEncoding
                                                         error:&error];
        nodes = [NSJSONSerialization JSONObjectWithData:[content dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingMutableContainers | NSJSONReadingAllowFragments error:&error];
        if (error) {
            NSLog(@"Error parsing file data - %@", error.localizedDescription);
        }
    } @catch (NSException *exception) {
        NSLog(@"Exception occurred while parsing file data - %@", exception.reason);
    }
    return nodes;
}

#pragma mark - IBActions
- (IBAction)createTree:(id)sender {
    [self createTree];
    [self.tree printPreOrderDescription];
}

- (IBAction)addNodes:(id)sender {
    [self addNodesToTree];
    [self.tree printPreOrderDescription];
}

- (IBAction)removeNodes:(id)sender {
    [self removeNodesFromTree];
    [self.tree printPreOrderDescription];
}
@end
