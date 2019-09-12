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
/****
 A base class that defines all stickers and captions.
 */
@interface AliyunEffectPasterBase : AliyunEffect

/**
 设置开始时间

 单位：秒
 */
/****
 The start time of the sticker. 
 
 Unit: seconds.
 */
@property(nonatomic, assign) CGFloat startTime;

/**
 设置结束时间

 单位：秒
 */

/****
 The end time of the sticker.
 
 Unit: seconds.
 */
@property(nonatomic, assign) CGFloat endTime;

/**
 动图最小播放时长

 配置文件内配置
 */
/****
 The minimum display duration of the sticker.
 
 This property is specified in the configuration file.
 */
@property(nonatomic, assign, readonly) CGFloat minDuration;

/**
 旋转角度
 */
/****
 The rotation angle of the sticker.
 */
@property(nonatomic, assign) CGFloat rotate;

/**
 动图的展示区域

 即动图的父视图 例如在编辑demo中的editzoneview
 */
/****
 The display area of the sticker.
 
 This area is the parent view of the sticker. 
 For example, the editzoneview in the demo.
 */
@property(nonatomic, assign) CGSize displaySize;

/**
 视频导出分辨率
 */
/****
 The video export resolution. 
 */
@property(nonatomic, assign) CGSize outputSize;

/**
 动图的位置大小
 */
/****
 The size of the sticker in the screen.
 */
@property(nonatomic, assign) CGRect frame;

/**
 动图的位置
 */
/****
 The position of the sticker in the screen.
 */
@property(nonatomic, assign) CGPoint position;

/**
 动图的大小
 */
/****
 The size of the sticker.
 */
@property(nonatomic, assign) CGSize size;

/**
 动图的宽
 */
/****
 The width of the sticker. 
 */
@property(nonatomic, assign) double width;

/**
 动图的高
 */
/****
 The height of the sticker. 
 */
@property(nonatomic, assign) double height;

/**
 动图是否镜像
 */
/****
 Whether to flip the sticker. 
 */
@property(nonatomic, assign) BOOL mirror;

/**
 初始化方法

 @param dict 初始化参数
 @return 动图实例
 */
/****
 Initializer.

 @param dict The initialization parameter.
 @return A sticker object.
 */
- (id)initWithDict:(NSDictionary *)dict;

/**
 API_AVAILABLE(3.7.0)

 添加动画 注意：在倒播特效下，不支持此功能

 @param action 动画
 */
/****
 API_AVAILABLE(3.7.0)

 Applies an animation. Note: This method is not applicable when the reverse playback effect is used.

 @param action The animation to be applied.
 */
- (void)runAction:(AliyunAction *)action;

/**
 API_AVAILABLE(3.7.0)

 停止动画

 @param action 动画
 */
/****
 API_AVAILABLE(3.7.0)

 Stops an animation.

 @param action The animation to be stopped.
 */
- (void)stopAction:(AliyunAction *)action;

/**
 停止所有动画
 */
/****
 Stops all animations.
 */
- (void)stopAllActions;

/**
 获取所有动画

 @return 动画集合
 */
/****
 Gets all animations.

 @return All animations in an array.
 */
- (NSArray *)allActions;

@end
