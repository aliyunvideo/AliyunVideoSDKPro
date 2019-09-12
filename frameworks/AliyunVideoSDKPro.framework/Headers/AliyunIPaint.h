//
//  AliyunPaint.h
//  QUSDK
//
//  Created by TripleL on 17/6/7.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 画笔
 */
/****
 A class that defines paint brushes.
 */
@interface AliyunIPaint : NSObject

/**
 线条颜色
 */
/****
 The color of the paint brush.
 */
@property (nonatomic, strong) UIColor *lineColor;

/**
 线条宽度
 */
/****
 The size of the paint brush.
 */
@property (nonatomic, assign) CGFloat lineWidth;

/**
 线条阴影颜色
 */
/****
 The color of the shadow.
 */
@property (nonatomic, strong) UIColor *shadowColor;

/**
 线条阴影宽度
 */
/****
 The size of the shadow.
 */
@property (nonatomic, assign) CGFloat shadowWidth;

/**
 初始化方法

 @param lineWidth 线条宽度
 @param lineColor 线条颜色
 @return self
 */
/****
 Initializer.

 @param lineWidth The paint brush size.
 @param lineColor The paint brush color.
 @return self
 */
- (instancetype)initWithLineWidth:(CGFloat)lineWidth
                        lineColor:(UIColor *)lineColor;

@end
