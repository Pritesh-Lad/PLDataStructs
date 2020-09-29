//
//  Utility.h
//  Example
//
//  Created by Pritesh on 29/09/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface Utility : NSObject

@end

@interface UIColor (TreeColors)
+ (UIColor *)colorFromHexString:(NSString *)hexString;
@end

@interface NSJSONSerialization (TreeNodes)
+ (id)jsonObjectFromFile:(NSString*)file;
@end

NS_ASSUME_NONNULL_END
