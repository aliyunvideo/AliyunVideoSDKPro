//
//  AliyunEffectMV.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/17.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"

/**
 mv效果model类
 */
@interface AliyunEffectMV : AliyunEffect

/**
 mv音乐流id
 */
@property(nonatomic, assign) int audioEffectVid;

/**
 是否关闭mv音乐
 */
@property(nonatomic, assign) int disableAudio;

/**
 mv音量大小

 0-100
 */
@property(nonatomic, assign) int audioMixWeight;

/**
 降噪大小

 0-100，0关闭降噪，值越大降噪幅度越大
 */
@property(nonatomic, assign) int audioDenoiseWeight;

/**
 是否对mv去燥

 已废弃，请使用音效列表AliyunAudioEffect代替
 */
@property(nonatomic, assign) BOOL denoise __deprecated_msg("use audioDenoiseWeight");

/**
 音效列表
 */
@property(nonatomic, strong) NSMutableArray<AliyunAudioEffect *> *audioEffects;
@end
