//
//  AliyunEffectMusic.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/17.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//


#import "AliyunEffect.h"
#include <CoreGraphics/CoreGraphics.h>

/**
 音乐model类
 */
@interface AliyunEffectMusic : AliyunEffect

/**
 音乐在播放轴上的开始播放时间
 */
@property(nonatomic, assign) CGFloat startTime;

/**
 音乐在播放轴上的播放持续时间
 */
@property(nonatomic, assign) CGFloat duration;

/**
 音乐在自身轴上的用来播放的开始时间
 */
@property(nonatomic, assign) CGFloat streamStartTime;

/**
 音乐在自身轴上的用来播放的持续时长
 */
@property(nonatomic, assign) CGFloat streamDuration;

/**
 音量大小

 0-100
 */
@property(nonatomic, assign) int audioMixWeight;

/**
 是否去噪

 已废弃，请使用音效列表AliyunAudioEffect代替
 */
@property(nonatomic, assign) BOOL denoise __deprecated_msg("deprecated");

/**
 音效列表
 */
@property(nonatomic, strong) NSMutableArray<AliyunAudioEffect *> *audioEffects;

@end
