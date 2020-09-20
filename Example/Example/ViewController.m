//
//  ViewController.m
//  Example
//
//  Created by Pritesh on 20/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "ViewController.h"
#import <PLDataStructs/PLDataStructs.h>

@interface ViewController ()
@property (nonatomic, strong) PLOrderedBTree *tree;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    _tree = [PLOrderedBTree new];
    NSString *s = [self.tree greetingString];
    NSLog(@"greetingString - %@",s);
}


@end
