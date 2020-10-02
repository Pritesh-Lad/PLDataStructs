//
//  UIColor+Trees.h
//  Example
//
//  Created by Pritesh on 02/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (Trees)
/**
 * Creates a color from a hexadecimal string with format #RRGGBB
 * @param hexString Hexadecimal string in format #RRGGBB
 * @return UIColor equivalent to given hex color
 */
+ (UIColor *)colorFromHexString:(NSString *)hexString;
@end

NS_ASSUME_NONNULL_END
