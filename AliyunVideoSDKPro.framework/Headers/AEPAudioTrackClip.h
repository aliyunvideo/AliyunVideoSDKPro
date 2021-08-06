//
//  AEPAudioTrackClip.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEPEffect.h"
#import "AEPSource.h"
#import "AliyunEffectMusic.h"
#import "AliyunEffectDub.h"

/**
 音轨片段类型
 */
/**
 The type of audio track clip
 */
typedef NS_ENUM(NSUInteger, AEPAudioTrackClipType) {
    /**
     音乐类型
     */
    /**
     The Music
     */
    AEPAudioTrackClipType_Music = 0,
    
    /**
     配音
     */
    /**
     The Dub
     */
    AEPAudioTrackClipType_Dub   = 1,
};

/**
 音轨片段
 */
@interface AEPAudioTrackClip : NSObject

/**
 媒体ID
 */
/**
 The Media id
 */
@property (nonatomic, assign, readonly) int mediaId;

/**
 音轨片段类型
 */
/**
 The type of audio track clip
 */
@property (nonatomic, assign, readonly) AEPAudioTrackClipType type;

/**
 音频资源
 */
/**
 The resource of audio
 */
@property (nonatomic, strong, readonly) AEPSource *source;

/**
 片段内部开始时间（秒）
 */
/**
 The start time on stream. (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval clipIn;
/**
 片段内部结束时间（秒）
 */
/**
 The end time on stream. (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval clipOut;

/**
 片段时长
 */
/**
 The duration of clip.(second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval clipDuration;
/**
 时间线的持续时间（秒）
 */
/**
 The duration of timeline. (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;
/**
 时间线上的开始时间（秒）
 */
/**
 The start time on timeline. (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval timelineIn;
/**
 时间线上的结束时间（秒）
 */
/**
 The end time on timeline. (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval timelineOut;

/**
 混音权重
 */
/**
 The weight of mix volume
 */
@property (nonatomic, assign, readonly) int mixWeight;
/**
 降噪权重
 */
/**
 The weight of denoise
 */
@property (nonatomic, assign, readonly) int denoiseWeight;

/**
 音效
 */
/**
 The effect of audio
 */
@property (nonatomic, strong, readonly) AEPAudioEffect *audioEffect;
/**
 声音淡入效果
 */
/**
 The fade in effect of audio
 */
@property (nonatomic, strong, readonly) AEPAudioFadeEffect *fadeInEffect;
/**
 声音淡出效果
 */
/**
 The fade out effect of audio
 */
@property (nonatomic, strong, readonly) AEPAudioFadeEffect *fadeOutEffect;
/**
 编辑器中的片段对象
 */
/**
 The clip obj for editor
 */
@property (nonatomic, strong, readonly) AliyunEffectMusic *editorClip;

@end
