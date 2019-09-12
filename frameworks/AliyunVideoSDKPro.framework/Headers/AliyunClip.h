//
//  AliyunClip.h
//  qurecorder
//
//  Created by dangshuai on 17/1/4.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunAction.h"
#import "AliyunEffect.h"
#import "AliyunJSONModel.h"
#import "AliyunTransitionEffect.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol AliyunClip;

/**
 片段类型

 - AliyunClipVideo: 视频
 - AliyunClipImage: 图片
 - AliyunClipAudio: 音频
 - AliyunClipGif: gif
 */
/****
 Clip types.

 - AliyunClipVideo: Video
 - AliyunClipImage: Image
 - AliyunClipAudio: Audio
 - AliyunClipGif: GIF
 */
typedef NS_ENUM(NSInteger, AliyunClipType) {
    AliyunClipVideo = 0,
    AliyunClipImage = 1,
    AliyunClipAudio = 2,
    AliyunClipGif = 3
};

/**
 媒体片段
 */
/****
 A class that defines media clips.
 */
@interface AliyunClip : AliyunJSONModel

/**
 类型
 */
/****
 The media type.
 */
@property(nonatomic, assign) AliyunClipType mediaType;

/**
 图片/视频高
 */
/****
 The height of the image or video.
 */
@property(nonatomic, assign) int mediaHeight;

/**
 图片/视频宽
 */
/****
 The width of the image or video.
 */
@property(nonatomic, assign) int mediaWidth;

/**
 片段资源本地路径
 */
/****
 The local path of the clip file.
 */
@property(nonatomic, copy) NSString *src;

/**
 开始时间
 */
/****
 The start time of this clip.
 */
@property(nonatomic, assign) CGFloat startTime;

/**
 过渡时长
 */
/****
 The duration of the transition.
 */
@property(nonatomic, assign) CGFloat fadeDuration;

/**
 显示模式
 0:裁剪 1:填充
 */
/****
 The display mode of this clip.
 0 indicates cut mode. 1 indicates fill mode.
 */
@property(nonatomic, assign) int displayMode;

/**
 旋转角度
 */
/****
 The rotation angle of this clip.
 */
@property(nonatomic, assign) int rotation;

/**
 持续时长
 */
/****
 The display duration of this clip.
 */
@property(nonatomic, assign) CGFloat duration;

/**
 片段id
 无需设置，sdk内部产生
 */
/****
 The id of this clip.
 This id is assigned by the system.
 */
@property(nonatomic, assign) int streamId;

/**
 转场效果
 和前一段视频/图片之间的转场效果
 */
/****
 The transition effect between the current video/image and the previous video/image.
 */
@property(nonatomic, strong) AliyunTransitionEffect *transitionEffect;

/**
 音效列表
 只对有音频的视频流生效
 */
/****
 The array of sound effects.
 Sound effects can only be applied to streams that have audio tracks. 
 */
@property(nonatomic, strong) NSMutableArray<AliyunAudioEffect *> *audioEffects;

/**
 音量大小
 0-100
 */
/****
 The volume of this clip.
 0-100
 */
@property(nonatomic, assign) NSInteger audioMixWeight;

/**
 已废弃字段
 */
/****
 Deprecated
 */
@property(nonatomic, assign) CGFloat audioRecordStartTime __deprecated_msg("deprecated");

/**
 创建一个图片片段

 @param path 图片路径
 @param duration 图片时长
 @param animDuration 过渡动画时长
 @return 图片片段
 */
/****
 Creates an image object.

 @param path The path of the image file.
 @param duration The display duration of the image.
 @param animDuration The duration of the transition.
 @return An image object.
 */
- (instancetype)initWithImagePath:(NSString *)path duration:(CGFloat)duration animDuration:(CGFloat)animDuration;

/**
 创建一个gif片段

 @param path gif路径
 @return gif片段
 */
/****
 Creates a GIF object.

 @param path The path of the GIF file.
 @return A GIF object.
 */
- (instancetype)initWithGifPath:(NSString *)path;

/**
 创建一个gif片段

 @param path gif路径
 @param startTime 指定gif的开始播放时间
 @param duration 指定gif的持续播放时间
 @return gif片段
 */
/****
 Creates a GIF object.

 @param path The path of the GIF file.
 @param startTime The time when the GIF appears. 
 @param duration The display duration of the GIF.
 @return A GIF object.
 */
- (instancetype)initWithGifPath:(NSString *)path startTime:(CGFloat)startTime duration:(CGFloat)duration;

/**
 创建一个视频片段

 @param path 视频路径
 @param animDuration 过渡动画时长
 @return 视频片段
 */
/****
 Creates a video object.

 @param path The path of the video file.
 @param animDuration The duration of the transition.
 @return A video object.
 */
- (instancetype)initWithVideoPath:(NSString *)path animDuration:(CGFloat)animDuration;

/**
 创建一个视频片段

 @param path 视频路径
 @param startTime 相对原视频开始时间
 @param duration 视频片段时长
 @param animDuration 过渡动画时长
 @return 视频片段
 */
/****
 Creates a video object.

 @param path The path of the video file.
 @param startTime The start time of the video. 
 @param duration The duration of the video.
 @param animDuration The duration of the transition.
 @return A video object.
 */
- (instancetype)initWithVideoPath:(NSString *)path startTime:(CGFloat)startTime duration:(CGFloat)duration animDuration:(CGFloat)animDuration;

/**
 API_AVAILABLE(3.7.0)

 添加动画 注意：1.主流不支持alpha帧动画 2.在倒播特效下，不支持此功能

 @param action 动画
 */
/****
 API_AVAILABLE(3.7.0)

 Applies an animation. Note: 1. Alpha animations cannot be applied to source streams.
 2. This method is not applicable when the reverse playback effect is used.

 @param action The animation to be applied.
 */
- (void)runAction:(AliyunAction *)action;

/**
 API_AVAILABLE(3.7.0)

 停止动画

 @param action 动画
 */
/****
 API_AVAILABLE(3.7.0)

 Stops an animation.

 @param action The animation to be stopped.
 */
- (void)stopAction:(AliyunAction *)action;

/**
 API_AVAILABLE(3.7.0)

 获取所有的动画

 @return 动画数组
 */
/****
 API_AVAILABLE(3.7.0)

 Gets all animations.

 @return All animations in an array.
 */
- (NSArray *)allActions;

@end

@protocol AliyunClip;

/**
 sdk内部使用类
 */
/****
 Internal class.
 */
@interface AliyunTrack : AliyunJSONModel

/**
 track id
 */
/****
 The track id.
 */
@property(nonatomic, assign) int idTrack;

/**
 音量
 */
/****
 The volume.
 */
@property(nonatomic, assign) float volume;

/**
 片段列表
 */
/****
 The array of clips.
 */
@property(nonatomic, strong) NSMutableArray<AliyunClip *> *clipList;

@end
