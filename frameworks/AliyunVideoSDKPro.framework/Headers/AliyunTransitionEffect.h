//
//  AliyunTransitionEffect.h
//  QUSDK
//
//  Created by Vienta on 2018/5/29.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunJSONModel.h"

typedef enum : NSUInteger {
    AliyunTransitionEffectTypeShuffer,  //百叶窗
    AliyunTransitionEffectTypeTranslate,//平移
    AliyunTransitionEffectTypeCircle,   //圆形
    AliyunTransitionEffectTypePolygon,  //多边形 可自定义是几边形
    AliyunTransitionEffectTypeFade,     //淡入淡出
} AliyunTransitionEffectType;

@interface AliyunTransitionEffect : AliyunJSONModel

/**
 转场时间，需要保证转场时间大于等于视频片段时长
 */
@property (nonatomic, assign) float overlapDuration;

/**
 自定义转场效果
 */
@property (nonatomic, copy) NSString *customShader;

/**
 转场自定义字段设置
 */
@property (nonatomic, strong) NSDictionary *transitionParam;


- (id)initWithRestore:(NSDictionary *)dict;

@end
