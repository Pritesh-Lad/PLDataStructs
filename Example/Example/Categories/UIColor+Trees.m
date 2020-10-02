//
//  UIColor+Trees.m
//  Example
//
//  Created by Pritesh on 02/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "UIColor+Trees.h"

@implementation UIColor (Trees)

+ (UIColor *)colorFromHexString:(NSString *)hexString {
    unsigned rgbValue = 0;
    NSScanner *scanner = [NSScanner scannerWithString:hexString];
    [scanner setScanLocation:1]; // skip '#'
    [scanner scanHexInt:&rgbValue];
    return [UIColor colorWithRed:((rgbValue & 0xFF0000) >> 16)/255.0
                           green:((rgbValue & 0xFF00) >> 8)/255.0
                            blue:(rgbValue & 0xFF)/255.0
                           alpha:1.0];
}

@end
