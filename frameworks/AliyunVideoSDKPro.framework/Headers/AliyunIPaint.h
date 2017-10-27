//
//  AliyunPaint.h
//  QUSDK
//
//  Created by TripleL on 17/6/7.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AliyunIPaint : NSObject


/**
 线条颜色
 */
@property (nonatomic, strong) UIColor *lineColor;


/**
 线条宽度
 */
@property (nonatomic, assign) CGFloat lineWidth;


/**
 线条阴影颜色
 */
@property (nonatomic, strong) UIColor *shadowColor;


/**
 线条阴影宽度
 */
@property (nonatomic, assign) CGFloat shadowWidth;


/**
 init

 @param lineWidth 线条宽度
 @param lineColor 线条颜色
 @return self
 */
- (instancetype)initWithLineWidth:(CGFloat)lineWidth
                        lineColor:(UIColor *)lineColor;
@end
