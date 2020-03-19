//
//  AliyunTransitionEffect.h
//  QUSDK
//
//  Created by Vienta on 2018/5/29.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunJSONModel.h"
#import <Foundation/Foundation.h>

@class AliyunEffectConfig;

/**
 AliyunTransitionEffectTypeShuffer:     百叶窗
 AliyunTransitionEffectTypeTranslate:   平移
 AliyunTransitionEffectTypeCircle:      圆形
 AliyunTransitionEffectTypePolygon:     多边形 可自定义是几边形
 AliyunTransitionEffectTypeFade:        淡入淡出
 */
typedef enum : NSUInteger {
    AliyunTransitionEffectTypeShuffer,
    AliyunTransitionEffectTypeTranslate,
    AliyunTransitionEffectTypeCircle,
    AliyunTransitionEffectTypePolygon,
    AliyunTransitionEffectTypeFade,
    AliyunTransitionEffectTypeCustom,
} AliyunTransitionEffectType;

/**
 转场效果的基类
 */
@interface AliyunTransitionEffect : AliyunJSONModel

/**
 转场时间，需要保证转场时间小于等于视频片段时长
 */
@property(nonatomic, assign) float overlapDuration;

/**
 自定义转场效果
 */
@property(nonatomic, copy) NSString *customShader;

/**
 转场自定义字段设置
 */
@property(nonatomic, strong) NSDictionary *transitionParam;

/**
 转场类型
 */
/**
 Transition Type
 */
@property(nonatomic,assign) AliyunTransitionEffectType type;

/**
 转场配置对象
 */
/**
 The config object of Transition
 */
@property(nonatomic,strong) AliyunEffectConfig* effectConfig;

/**
 自定义转场本地资源路径
 */
/**
 The local resouce path of  custom Transition
 */
@property(nonatomic,copy) NSString *path;

/**
转场自定义参数字符串
*/
@property(nonatomic,copy) NSString *paramString;

/**
 废弃方法
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

/**
 根据资源路径进行初始化
 */
/**
 init by resource path
 */
-(id)initWithPath:(NSString *)path;

/**
 获取转场配置参数
 */
-(NSString*)getFliterParamString;

@end
