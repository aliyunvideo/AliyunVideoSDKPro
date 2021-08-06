//
//  AEPEffectTrack.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEPTrack.h"

#import "AliyunEffectMV.h"
#import "AliyunEffectFilter.h"
#import "AliyunEffectTimeFilter.h"

@interface AEPEffectTrack : AEPTrack
@end

/**
 时间特效类型

 - AEPEffectTimeType_Speed: 变速
 - AEPEffectTimeType_Repeat: 反复
 - AEPEffectTimeType_Invert: 倒放
 */
typedef NS_ENUM(NSUInteger, AEPEffectTimeType) {
    AEPEffectTimeType_None      = 0,
    AEPEffectTimeType_Speed     = 1,
    AEPEffectTimeType_Repeat    = 2,
    AEPEffectTimeType_Invert    = 3,
};


@interface AEPEffectTimeTrack : AEPEffectTrack

/**
 时间特效类型
 */
/**
Timeline effect types.
 */
@property (nonatomic, assign, readonly) AEPEffectTimeType timeType;

/**
 时间特效参数

 1.在变速类型下代表速率，范围建议 0.5 - 2
 2.在反复类型下代表反复次数，内部取整型
 */
@property (nonatomic, assign, readonly) float timeParam;

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
 是否保留播放轴时长

 举例：如果10s视频，全程慢速2倍，如果originDuration为YES，则播放轴为10s，如果为NO,则播放轴为20s。
 */
/**
 Whether to keep the original duration of the playback timeline.

 For example, if a 10-second video is played at half of the original speed, the playback timeline duration is 10 seconds if originDuration is set to YES and 20 seconds if originDuration is set to NO.
 */
@property (nonatomic, assign, readonly) BOOL needOriginDuration;

/**
 在编辑器中使用的特效对象
 */
/**
 The effect obj for editor
 */
@property (nonatomic, strong, readonly) AliyunEffectTimeFilter *editorEffect;

@end

/**
 滤镜效果model类
 */
@interface AEPEffectFilterTrack : AEPEffectTrack

/**
 滤镜资源
 */
/**
 The resource of effect
 */
@property (nonatomic, strong, readonly) AEPSource *source;

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
 编辑器用到的滤镜对象
 */
@property (nonatomic, strong, readonly) AliyunEffectFilter *editorEffect;

@end

/**
 特效
 */
/**
 The Animation filter
 */
@interface AEPEffectAnimationFilterTrack : AEPEffectFilterTrack
/**
 特效参数
 */
/**
 The param of animation filter
 */
@property (nonatomic, copy, readonly) NSString *paramString;
@end

/**
 mv效果model类
 */
/**
 A model class that defines MV effects.
 */
@interface AEPEffectMVTrack : AEPEffectTrack

/**
 MV资源
 */
/**
 The resource of mv
 */
@property (nonatomic, strong, readonly) AEPSource *source;

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
 流ID
 */
/**
 The id of stream
 */
@property (nonatomic, assign, readonly) int audioStreamId;

/**
 是否静音
 */
/**
 Mute
 */
@property (nonatomic, assign, readonly) BOOL mute;

/**
 混音权重
 */
/**
 The weight of mix
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
 效果列表
 */
/**
 The list of effects.
 */
@property (nonatomic, copy, readonly) NSArray<AEPEffect *> *effects;

/**
 音效
 */
/**
 The sound effect
 */
@property (nonatomic, strong, readonly) AEPAudioEffect *audioEffect;

/**
 淡入Model
 */
/**
 The fade in model.
 */
@property (nonatomic, strong, readonly) AEPAudioFadeEffect *fadeInEffect;
/**
 淡出Model
 */
/**
 The fade out model.
 */
@property (nonatomic, strong, readonly) AEPAudioFadeEffect *fadeOutEffect;

/**
 编辑器中使用的MV对象
 */
/**
 The mv obj for editor
 */
@property (nonatomic, strong, readonly) AliyunEffectMV *editorEffect;

@end
