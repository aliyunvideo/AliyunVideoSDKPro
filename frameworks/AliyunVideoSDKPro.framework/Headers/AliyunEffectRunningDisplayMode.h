//
//  AliyunEffectRunningDisplayMode.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/7/18.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"
/**
 播放模式

 - AliyunRunningModeFit：裁剪模式
 - AliyunRunningModeFill：填充模式
 */
/****
 Display modes.
 
 - AliyunRunningModeFit：Cut mode
 - AliyunRunningModeFill：Fill mode
 */
typedef NS_ENUM(NSInteger, AliyunRunningMode) { AliyunRunningModeFit = 0, AliyunRunningModeFill = 1 };

/**
 动态切换播放模式的效果类
 */
/****
 An effect class that enables changing the display mode.
 */
@interface AliyunEffectRunningDisplayMode : AliyunEffect

/**
 特效开始时间
 */
/****
 The start time of the effect.
 */
@property(nonatomic, assign) float streamStartTime;

/**
 特效结束时间
 */
/****
 The end time of the effect.
 */
@property(nonatomic, assign) float streamEndTime;

/**
 播放模式

 0：填充
 1：裁剪
 */
/****
 The display mode.
 
 0：Fill
 1：Cut
 */
@property(nonatomic, assign) AliyunRunningMode mode;

/**
 指定目标视频的id
 */
/****
 The id of the target video.
 */
@property(nonatomic, assign) int targetStreamId;

- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
