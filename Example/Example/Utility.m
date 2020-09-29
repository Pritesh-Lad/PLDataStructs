//
//  Utility.m
//  Example
//
//  Created by Pritesh on 29/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "Utility.h"

@implementation Utility

@end

@implementation UIColor (TreeColors)
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

@implementation NSJSONSerialization (TreeNodes)
+ (id)jsonObjectFromFile:(NSString*)file{
    id jsonObject;
    NSError *error;
    @try {
        NSString *filePath = [[NSBundle mainBundle] pathForResource:file ofType:@"json"];
        NSString *content = [NSString stringWithContentsOfFile:filePath
                                                      encoding:NSUTF8StringEncoding
                                                         error:&error];
        jsonObject = [NSJSONSerialization JSONObjectWithData:[content dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingMutableContainers | NSJSONReadingAllowFragments error:&error];
        if (error) {
            NSLog(@"Error parsing file data - %@", error.localizedDescription);
        }
    } @catch (NSException *exception) {
        NSLog(@"Exception occurred while parsing file data - %@", exception.reason);
    }
    return jsonObject;
}

@end
