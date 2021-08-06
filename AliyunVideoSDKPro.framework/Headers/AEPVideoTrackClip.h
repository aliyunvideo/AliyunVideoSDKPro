//
//  AEPVideoTrackClip.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunVideoParam.h"
#import "AEPSource.h"
#import "AEPAction.h"
#import "AEPEffect.h"
#import "AEPTransitionEffect.h"
#import "AliyunClip.h"

/**
 视频片段
 */
/**
 The clip of video
 */
@interface AEPVideoTrackClip : NSObject

/**
 视频ID
 */
/**
 The media id
 */
@property (nonatomic, assign, readonly) int mediaId;

/**
 片段类型
 */
/**
 The type of clip
 */
@property (nonatomic, assign, readonly) AliyunClipType type;

/**
 片段资源
 */
/**
 The resource of video clip
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
 视频分辨率，宽
 */
/**
 The width of video
 */
@property (nonatomic, assign, readonly) int width;
/**
 视频分辨率，高
 */
/**
 The height of video
 */
@property (nonatomic, assign, readonly) int height;
/**
 视频旋转角度
 */
/**
 The rotation of video
 */
@property (nonatomic, assign, readonly) int rotation;

/**
 裁剪模式

 - AliyunScaleModeFit: 裁剪
 - AliyunScaleModeFill: 填充
 */
/**
 Crop modes.

 - AliyunScaleModeFit: Cut mode
 - AliyunScaleModeFill: Fill mode
 */
@property (nonatomic, assign, readonly) AliyunScaleMode displayMode;

/**
 亮度值
 */
/**
 The  value of brightness
 */
@property (nonatomic, assign, readonly) float brightnessValue;

/**
 对比度值
 */
/**
 The  value of contrast
 */
@property (nonatomic, assign, readonly) float contrastValue;

/**
 暗角值
 */
/**
 The  value of vignette
 */
@property (nonatomic, assign, readonly) float vignetteValue;

/**
 饱和度值
 */
/**
 The  value of saturation
 */
@property (nonatomic, assign, readonly) float saturationValue;

/**
 锐度值
 */
/**
 The  value of sharpness
 */
@property (nonatomic, assign, readonly) float sharpnessValue;

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
 动画列表
 */
/**
 The list of actions
 */
@property (nonatomic, copy, readonly) NSArray<AEPAction *> *actions;

/**
 转场效果
 和前一段视频/图片之间的转场效果
 */
@property (nonatomic, strong, readonly) AEPTransitionEffect *transitionEffect;

/**
 模糊背景效果
 */
/**
 The effect of blur background
 */
@property (nonatomic, copy, readonly) NSArray<AEPBlurBackgroundEffect *> *blurBackgroundEffects;

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
@property (nonatomic, strong, readonly) AliyunClip *editorClip;

@end
