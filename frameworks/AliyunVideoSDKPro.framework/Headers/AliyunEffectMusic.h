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
/****
 A model class that defines music effects.
 */
@interface AliyunEffectMusic : AliyunEffect

/**
 音乐在播放轴上的开始播放时间
 */
/****
 The start time of the music on the playback timeline. 
 */
@property(nonatomic, assign) CGFloat startTime;

/**
 音乐在播放轴上的播放持续时间
 */
/****
 The playback duration of the music on the playback timeline.
 */
@property(nonatomic, assign) CGFloat duration;

/**
 音乐在自身轴上的用来播放的开始时间
 */
/****
 The start time of the music on the stream timeline.
 */
@property(nonatomic, assign) CGFloat streamStartTime;

/**
 音乐在自身轴上的用来播放的持续时长
 */
/****
 The playback duration of the music on the stream timeline.
 */
@property(nonatomic, assign) CGFloat streamDuration;

/**
 音量大小

 0-100
 */
/****
 The volume of the music.
 
 Valid values: [0, 100]
 */
@property(nonatomic, assign) int audioMixWeight;

/**
 是否去噪

 已废弃，请使用音效列表AliyunAudioEffect代替
 */
/****
 Whether to denoise the music.
 
 Deprecated. Replaced by AliyunAudioEffect.
 */
@property(nonatomic, assign) BOOL denoise __deprecated_msg("deprecated");

/**
 音效列表
 */
/****
 The sound effects.
 */
@property(nonatomic, strong) NSMutableArray<AliyunAudioEffect *> *audioEffects;

@end
