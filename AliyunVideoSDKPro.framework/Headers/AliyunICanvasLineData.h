//
//  AliyunICanvasLineData.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/7/28.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 画布线条数据
 */
@interface AliyunICanvasLineData : NSObject

/**
 线条颜色
 */
@property (nonatomic, strong, readonly) UIColor *lineColor;
/**
 线条宽度
 */
@property (nonatomic, assign, readonly) CGFloat lineWidth;
/**
 线条阴影颜色
 */
@property (nonatomic, strong, readonly) UIColor *shadowColor;
/**
 线条阴影宽度
 */
@property (nonatomic, assign, readonly) CGFloat shadowWidth;
/**
 点数据
 */
/**
 The points of line
 */
@property (nonatomic, copy, readonly) NSArray<NSValue *> *points;

@end
