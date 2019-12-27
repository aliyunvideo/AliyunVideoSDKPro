//
//  AliyunTransitionEffectPolygon.h
//  QUSDK
//
//  Created by Vienta on 2018/5/31.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunTransitionEffect.h"
//#import <AliyunVideoSDKPro/AliyunVideoSDKPro.h>

/**
 多边形转场效果
 */
@interface AliyunTransitionEffectPolygon : AliyunTransitionEffect

/**
 设置几变形

 n >= 3
 */
@property(nonatomic, assign) int n;

/**
 初始化方法

 @param dict 初始化参数
 @return 多边形转场实例
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
