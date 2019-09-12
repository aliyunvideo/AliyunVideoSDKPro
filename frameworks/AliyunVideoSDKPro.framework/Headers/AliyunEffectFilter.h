//
//  AliyunEffectFilter.h
//  qurecorder
//
//  Created by Vienta on 2017/1/7.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"

/**
 滤镜效果model类
 */
/****
 A model class that defines filter effects.
 */
@interface AliyunEffectFilter : AliyunEffect

/**
 开始时间

 预留字段，无需设置
 */
/****
 The start time of the filter effect.

 Reserved. Do not change.
 */
@property(nonatomic, assign) float startTime;

/**
 结束时间

 预留字段，无需设置
 */
/****
 The end time of the filter effect.

 Reserved. Do not change.
 */
@property(nonatomic, assign) float endTime;

/**
 滤镜开始时间

 只在设置动效滤镜时有效
 */
/****
 The start time of the filter effect.

 This property is only applicable to animated filters.
 */
@property(nonatomic, assign) float streamStartTime;

/**
 滤镜结束时间

 只在设置动效滤镜时有效
 */
/****
 The end time of the filter effect.

 This property is only applicable to animated filters.
 */
@property(nonatomic, assign) float streamEndTime;

/**
 内部调用方法

 @param dict dict
 @return AliyunEffectFilter
 */
/****
 Internal method.

 @param dict The initialization parameter.
 @return AliyunEffectFilter
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
