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

+ (id)jsonObjectFromFile:(NSString*)file;

@end

NS_ASSUME_NONNULL_END
