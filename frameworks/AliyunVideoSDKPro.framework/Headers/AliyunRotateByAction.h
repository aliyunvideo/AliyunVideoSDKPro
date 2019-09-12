//
//  AliyunRotateByAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunRotateAction.h"

/**
 旋转动画类
 */
/****
 A class that defines rotation animations with a rotation angle.
 */
@interface AliyunRotateByAction : AliyunRotateAction

/**
 在当前的旋转弧度上再旋转多少弧度
 */
/****
 The rotation angle.
 */
@property(nonatomic, assign) float rotateDegree;

/**
 初始化方法

 @param dict 初始化参数
 @return 旋转动画实例
 */
/****
 Initializer.

 @param dict The initialization parameter.
 @return A rotation animation object.
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
