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
/****
 A model class that defines blurred background effects.
 */
@interface AliyunEffectBlurBackground : AliyunEffect

/**
 开始时间
 */
/****
 The time when the blurred background effect is applied.
 */
@property(nonatomic, assign) float streamStartTime;

/**
 结束时间
 */
/****
 The time when the blurred background effect is removed.
 */
@property(nonatomic, assign) float streamEndTime;

/**
 作用的目标流id

 该参数必须设置
 */
/****
 The id of the stream that the blurred background effect is applied to.
 Required.
 */
@property(nonatomic, assign) int targetStreamId;

/**
 模糊半径

 数值越大越模糊，范围0-29
 */
/****
 The blur radius.

 The higher the radius value, the more blurred the background is. Valid values: [0, 29]
 */
@property(nonatomic, assign) float blurRadius;

/**
 内部调用方法

 @param dict dict
 @return AliyunEffectBlurBackground
 */
/****
 Internal method.

 @param dict The dict.
 @return AliyunEffectBlurBackground
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
