//
//  AliyunMoveAction.h
//  QUSDK
//
//  Created by Vienta on 2018/5/25.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"
#import <UIKit/UIKit.h>

/**
 平移动画
 */
/****
 A class that defines translational motions.
 */
@interface AliyunMoveAction : AliyunAction

/**
 移动的起始坐标

 坐标参考系是为系统屏幕坐标系 （0，0）为左上角  和系统view行为一致
 */
/****
 The coordinates of the start point of the motion.
 
 The coordinate system of the screen is used. The origin (0, 0) is at the top left of the screen.
 */
@property(nonatomic, assign) CGPoint fromePoint;

/**
 移动的终点位置
 */
/****
 The coordinates of the end point of the motion.
 */
@property(nonatomic, assign) CGPoint toPoint;

/**
 动画移动的区域范围
 */
/****
 The moving area of the motion.
 */
@property(nonatomic, assign) CGSize displaySize;

/**
 初始化方法

 @param dict 初始化参数
 @return 平移动画实例
 */
/****
 Initializer.

 @param dict The initialization parameter.
 @return A translational motion object.
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
