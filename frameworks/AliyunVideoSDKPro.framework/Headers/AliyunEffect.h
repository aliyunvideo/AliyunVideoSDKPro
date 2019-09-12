//
//  AliyunEffect.h
//  qurecorder
//
//  Created by Vienta on 2017/1/7.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunJSONModel.h"
#import <Foundation/Foundation.h>

/**
 音效类型

 - AliyunAudioEffectDefault: 默认
 - AliyunAudioEffectLolita: 萝莉
 - AliyunAudioEffectUncle: 大叔
 - AliyunAudioEffectReverb: 混响
 - AliyunAudioEffectEcho: 回声
 - AliyunAudioEffectRobot: 机器人
 - AliyunAudioEffectBigDevil: 大魔王
 - AliyunAudioEffectMinions: 小黄人
 - AliyunAudioEffectDenoise: 去噪
 */
/****
 Sound effect types.

 - AliyunAudioEffectDefault: Default
 - AliyunAudioEffectLolita: Cute girl
 - AliyunAudioEffectUncle: Middle-aged man
 - AliyunAudioEffectReverb: Reverberation
 - AliyunAudioEffectEcho: Echo
 - AliyunAudioEffectRobot: Robot
 - AliyunAudioEffectBigDevil: Demon
 - AliyunAudioEffectMinions: Minion
 - AliyunAudioEffectDenoise: Denoised
 */
typedef NS_ENUM(NSInteger, AliyunAudioEffectType) {
    AliyunAudioEffectDefault = 0,
    AliyunAudioEffectLolita,
    AliyunAudioEffectUncle,
    AliyunAudioEffectReverb,
    AliyunAudioEffectEcho,
    AliyunAudioEffectRobot,
    AliyunAudioEffectBigDevil,
    AliyunAudioEffectMinions,
    AliyunAudioEffectDenoise,
};

id QUSDKObjectOrNull(id object);

/**
 特效model基类
 */
/****
 A model base class that defines effects.
 */
@interface AliyunEffect : AliyunJSONModel

/**
 路径
 */
/****
 The path of the effect.
 */
@property(nonatomic, copy) NSString *path;

/**
 图标路径
 */
/****
 The path of the effect icon.
 */
@property(nonatomic, copy) NSString *icon;

/**
 名称
 */
/****
 The effect name.
 */
@property(nonatomic, copy) NSString *name;

/**
 id

 @return id
 */
/****
 Gets the effect id.

 @return id
 */
- (int)effectVid;

/**
 设置id

 @param vid id
 */
/****
 Sets the effect id.

 @param vid id
 */
- (void)setEffectVid:(int)vid;

/**
 通过文件夹路径初始化effect对象

 @param path effect资源文件夹对象
 @return effect实例对象
 */
/****
 Initializes an effect object with an effect path.

 @param path The effect path. 
 @return An effect object.
 */
- (instancetype)initWithFile:(NSString *)path;

/**
 内部调用方法

 @param dict dict
 @return AliyunEffect
 */
/****
 Internal method.

 @param dict dict
 @return AliyunEffect
 */
- (instancetype)initWithDict:(NSDictionary *)dict;

@end

/**
 音效model类
 */
/****
 A model class that defines sound effects.
 */
@interface AliyunAudioEffect : AliyunJSONModel

/**
 音效类型
 */
/****
 The sound effect type.
 */
@property(nonatomic, assign) AliyunAudioEffectType type;

/**
 音效值0-100
 */
/****
 The value of the sound effect. Valid values: [0, 100]
 */
@property(nonatomic, assign) int weight;

@end
