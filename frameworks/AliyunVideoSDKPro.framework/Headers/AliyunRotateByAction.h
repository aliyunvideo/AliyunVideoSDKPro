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
@interface AliyunRotateByAction : AliyunRotateAction

/**
 在当前的旋转弧度上再旋转多少弧度
 */
@property(nonatomic, assign) float rotateDegree;

/**
 初始化方法

 @param dict 初始化参数
 @return 旋转动画实例
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
