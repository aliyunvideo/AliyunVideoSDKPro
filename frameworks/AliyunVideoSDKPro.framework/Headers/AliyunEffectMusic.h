//
//  AliyunEffectMusic.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/17.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

//关于startTime, duration, streamStartTime,streamDuration的举例说明：
//比如：视频的播放时长为15s， 音乐自身时长为10s，上述参数进行了如下设置：
// startTime = 2;
// duration = 10;
// streamStartTime = 2;
// streamDuration = 5;
// 上述参数设置后的实际效果是： 在视频播放到第2s的时候，音乐开始从其自身的2s处开始播放（注意其自身长度为10s，是从自身的2s处播放），并且只播放自身的5s时长，然后视频播放到10s时候音乐停止

#import "AliyunEffect.h"
#include <CoreGraphics/CoreGraphics.h>

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
 仅对mv和音乐有效，0-100 音量大小 （0 - 100）
 */
@property(nonatomic, assign) int audioMixWeight;

/**
 是否去噪
 */
@property(nonatomic, assign) BOOL denoise;

/**
 音效
 */
@property(nonatomic, strong) NSMutableArray<AliyunAudioEffect *> *audioEffects;

@end
