//
//  AliyunRotateAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"

/**
 旋转动画类
 */
/****
 A class that defines rotation animations.
 */
@interface AliyunRotateAction : AliyunAction

/**
 旋转方向

 可以设置为顺时针或者逆时针
 true:顺时针
 false:逆时针
 */
/****
 The rotation direction.
 
 true indicates clockwise.
 false indicates counter-clockwise.
 */
@property(nonatomic, assign) bool clockwise;

/**
 开始旋转时的弧度

 单位：弧度
 */
/****
 The initial angle.
 
 Unit: radians.
 */
@property(nonatomic, assign) float fromDegree;

/**
 初始化方法

 @param dict 初始化参数
 @return 旋转动画实例对象
 */
/****
 Initializer.

 @param dict The initialization parameter.
 @return A rotation animation object.
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
