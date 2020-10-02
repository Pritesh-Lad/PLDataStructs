//
//  NSJSONSerialization+Trees.m
//  Example
//
//  Created by Pritesh on 02/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import "NSJSONSerialization+Trees.h"

@implementation NSJSONSerialization (Trees)

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
