//
//  AliyunEffectPasterBase.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/3.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"
#import "AliyunActionProtocol.h"
#import "AliyunEffect.h"
#import <CoreGraphics/CoreGraphics.h>

static const double kQUSDKPasterBase = 640.f;

/**
 所有动图/字幕的基类
 */
@interface AliyunEffectPasterBase : AliyunEffect

/**
 设置开始时间

 单位：秒
 */
@property(nonatomic, assign) CGFloat startTime;

/**
 设置结束时间

 单位：秒
 */

@property(nonatomic, assign) CGFloat endTime;

/**
 动图最小播放时长

 配置文件内配置
 */
@property(nonatomic, assign, readonly) CGFloat minDuration;

/**
 旋转角度
 */
@property(nonatomic, assign) CGFloat rotate;

/**
 动图的展示区域

 即动图的父视图 例如在编辑demo中的editzoneview
 */
@property(nonatomic, assign) CGSize displaySize;

/**
 视频导出分辨率
 */
@property(nonatomic, assign) CGSize outputSize;

/**
 动图的位置大小
 */
@property(nonatomic, assign) CGRect frame;

/**
 动图的位置
 */
@property(nonatomic, assign) CGPoint position;

/**
 动图的大小
 */
@property(nonatomic, assign) CGSize size;

/**
 动图的宽
 */
@property(nonatomic, assign) double width;

/**
 动图的高
 */
@property(nonatomic, assign) double height;

/**
 动图是否镜像
 */
@property(nonatomic, assign) BOOL mirror;

/**
 初始化方法

 @param dict 初始化参数
 @return 动图实例
 */
- (id)initWithDict:(NSDictionary *)dict;

/**
 API_AVAILABLE(3.7.0)

 添加动画 注意：在倒播特效下，不支持此功能

 @param action 动画
 */
- (void)runAction:(AliyunAction *)action;

/**
 API_AVAILABLE(3.7.0)

 停止动画

 @param action 动画
 */
- (void)stopAction:(AliyunAction *)action;

/**
 停止所有动画
 */
- (void)stopAllActions;

/**
 获取所有动画

 @return 动画集合
 */
- (NSArray *)allActions;

@end
