//
//  AliyunScaleAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"

/**
 缩放动画类
 */
/****
 A class that defines scale animations.
 */
@interface AliyunScaleAction : AliyunAction

/**
 缩放的起始缩放比例
 */
/****
 The initial scale factor.
 */
@property(nonatomic, assign) float fromScale;

/**
 缩放的终点缩放比例
 */
/****
 The target scale factor.
 */
@property(nonatomic, assign) float toScale;

/**
 初始化方法

 @param dict 初始化参数
 @return 缩放动画实例
 */
/****
 Initializer.

 @param dict The initialization parameter.
 @return A scale animation object.
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
