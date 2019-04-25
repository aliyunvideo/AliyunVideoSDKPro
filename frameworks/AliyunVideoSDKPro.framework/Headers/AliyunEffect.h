//
//  AliyunEffect.h
//  qurecorder
//
//  Created by Vienta on 2017/1/7.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunJSONModel.h"
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AliyunAudioEffectType) {
    AliyunAudioEffectDefault = 0,
    AliyunAudioEffectLolita,  // 萝莉
    AliyunAudioEffectUncle,   // 大叔
    AliyunAudioEffectReverb,  // 混响
    AliyunAudioEffectEcho,    // 回声
    AliyunAudioEffectDenoise, // 去噪
};

id QUSDKObjectOrNull(id object);
@interface AliyunEffect : AliyunJSONModel

@property(nonatomic, copy) NSString *path;
@property(nonatomic, copy) NSString *icon; // icon path
@property(nonatomic, copy) NSString *name;

- (int)effectVid;

- (void)setEffectVid:(int)vid;

/**
 初始化effect对象

 @param path effect资源文件夹对象
 @return effect实例对象
 */
- (instancetype)initWithFile:(NSString *)path;

- (instancetype)initWithDict:(NSDictionary *)dict;

@end

@interface AliyunAudioEffect : AliyunJSONModel

/**
 音效类型
 */
@property(nonatomic, assign) AliyunAudioEffectType type;

/**
 音效值0-100
 */
@property(nonatomic, assign) int weight;
@end
