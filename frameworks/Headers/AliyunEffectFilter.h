//
//  AliyunEffectFilter.h
//  qurecorder
//
//  Created by Vienta on 2017/1/7.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"

@class AliyunEffectConfig;
/**
 滤镜效果model类
 */
@interface AliyunEffectFilter : AliyunEffect

/**
 开始时间

 预留字段，无需设置
 */
@property(nonatomic, assign) float startTime;

/**
 结束时间

 预留字段，无需设置
 */
@property(nonatomic, assign) float endTime;

/**
 滤镜开始时间

 只在设置动效滤镜时有效
 */
@property(nonatomic, assign) float streamStartTime;

/**
 滤镜结束时间

 只在设置动效滤镜时有效
 */
@property(nonatomic, assign) float streamEndTime;

/**
 滤镜自定义参数字符串
 */
@property(nonatomic,copy) NSString *paramString;

/**
 滤镜配置对象
 */
@property(nonatomic,strong) AliyunEffectConfig* effectConfig;

/**
 内部调用方法

 @param dict dict
 @return AliyunEffectFilter
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

/**
 内部调用方法
*/
-(NSString*)getFliterParamString;

@end
