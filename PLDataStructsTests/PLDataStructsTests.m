//
//  PLDataStructsTests.m
//  PLDataStructsTests
//
//  Created by Pritesh on 19/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <PLDataStructs/PLOrderedBTree.h>

@interface PLDataStructsTests : XCTestCase
@property (nonatomic, strong) PLOrderedBTree *tree;
@end

@implementation PLDataStructsTests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
    _tree = [PLOrderedBTree new];
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    _tree = nil;
}

- (void)testExample {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    
}

@end
