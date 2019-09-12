//
//  AliyunTransitionEffect.h
//  QUSDK
//
//  Created by Vienta on 2018/5/29.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunJSONModel.h"
#import <Foundation/Foundation.h>
/**
 AliyunTransitionEffectTypeShuffer:     百叶窗
 AliyunTransitionEffectTypeTranslate:   平移
 AliyunTransitionEffectTypeCircle:      圆形
 AliyunTransitionEffectTypePolygon:     多边形 可自定义是几边形
 AliyunTransitionEffectTypeFade:        淡入淡出
 */
/****
 AliyunTransitionEffectTypeShuffer:     Blinds
 AliyunTransitionEffectTypeTranslate:   Translational motion
 AliyunTransitionEffectTypeCircle:      Circle
 AliyunTransitionEffectTypePolygon:     Polygon
 AliyunTransitionEffectTypeFade:        Fade
 */
typedef enum : NSUInteger {
    AliyunTransitionEffectTypeShuffer,
    AliyunTransitionEffectTypeTranslate,
    AliyunTransitionEffectTypeCircle,
    AliyunTransitionEffectTypePolygon,
    AliyunTransitionEffectTypeFade,
} AliyunTransitionEffectType;

/**
 转场效果的基类
 */
/****
 A base class that defines transition effects.
 */
@interface AliyunTransitionEffect : AliyunJSONModel

/**
 转场时间，需要保证转场时间小于等于视频片段时长
 */
/****
 The transition duration. The transition duration must not be longer than that of the video clip. 
 */
@property(nonatomic, assign) float overlapDuration;

/**
 自定义转场效果
 */
/****
 The custom transition effect.
 */
@property(nonatomic, copy) NSString *customShader;

/**
 转场自定义字段设置
 */
/****
 The transition parameter.
 */
@property(nonatomic, strong) NSDictionary *transitionParam;

/**
 废弃方法
 */
/****
 Deprecated.
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
