//
//  AliyunEffectBlurBackground.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/6/29.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"

/**
 背景模糊效果model类
 */
@interface AliyunEffectBlurBackground : AliyunEffect

/**
 开始时间
 */
@property(nonatomic, assign) float streamStartTime;

/**
 结束时间
 */
@property(nonatomic, assign) float streamEndTime;

/**
 作用的目标流id

 该参数必须设置
 */
@property(nonatomic, assign) int targetStreamId;

/**
 模糊半径

 数值越大越模糊，范围0-29
 */
@property(nonatomic, assign) float blurRadius;

/**
 内部调用方法

 @param dict dict
 @return AliyunEffectBlurBackground
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
