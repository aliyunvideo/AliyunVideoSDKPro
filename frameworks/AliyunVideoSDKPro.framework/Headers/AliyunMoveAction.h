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
@interface AliyunMoveAction : AliyunAction

/**
 移动的起始坐标

 坐标参考系是为系统屏幕坐标系 （0，0）为左上角  和系统view行为一致
 */
@property(nonatomic, assign) CGPoint fromePoint;

/**
 移动的终点位置
 */
@property(nonatomic, assign) CGPoint toPoint;

/**
 动画移动的区域范围
 */
@property(nonatomic, assign) CGSize displaySize;

/**
 初始化方法

 @param dict 初始化参数
 @return 平移动画实例
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
