//
//  ViewController.h
//  Example
//
//  Created by Pritesh on 20/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TreeView.h"

@interface ViewController : UIViewController

//@property (weak, nonatomic) IBOutlet TreeView *treeView;
- (IBAction)createTree:(id)sender;
- (IBAction)addNodes:(id)sender;
- (IBAction)removeNodes:(id)sender;

@end

