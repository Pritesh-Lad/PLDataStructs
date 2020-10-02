//
//  NSJSONSerialization+Trees.h
//  Example
//
//  Created by Pritesh on 02/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSJSONSerialization (Trees)

/**
 * Reads a json object from a file in bundle
 * @param file name of the file in project bundle
 * @return Parsed JSON object
 */
+ (id)jsonObjectFromFile:(NSString*)file;

@end

NS_ASSUME_NONNULL_END
