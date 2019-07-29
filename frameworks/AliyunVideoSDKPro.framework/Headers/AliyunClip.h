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
typedef NS_ENUM(NSInteger, AliyunClipType) {
    AliyunClipVideo = 0,
    AliyunClipImage = 1,
    AliyunClipAudio = 2,
    AliyunClipGif = 3
};

/**
 媒体片段
 */
@interface AliyunClip : AliyunJSONModel

/**
 类型
 */
@property(nonatomic, assign) AliyunClipType mediaType;

/**
 图片/视频高
 */
@property(nonatomic, assign) int mediaHeight;

/**
 图片/视频宽
 */
@property(nonatomic, assign) int mediaWidth;

/**
 片段资源本地路径
 */
@property(nonatomic, copy) NSString *src;

/**
 开始时间
 */
@property(nonatomic, assign) CGFloat startTime;

/**
 过渡时长
 */
@property(nonatomic, assign) CGFloat fadeDuration;

/**
 显示模式
 0:裁剪 1:填充
 */
@property(nonatomic, assign) int displayMode;

/**
 旋转角度
 */
@property(nonatomic, assign) int rotation;

/**
 持续时长
 */
@property(nonatomic, assign) CGFloat duration;

/**
 片段id
 无需设置，sdk内部产生
 */
@property(nonatomic, assign) int streamId;

/**
 转场效果
 和前一段视频/图片之间的转场效果
 */
@property(nonatomic, strong) AliyunTransitionEffect *transitionEffect;

/**
 音效列表
 只对有音频的视频流生效
 */
@property(nonatomic, strong) NSMutableArray<AliyunAudioEffect *> *audioEffects;

/**
 音量大小
 0-100
 */
@property(nonatomic, assign) NSInteger audioMixWeight;

/**
 已废弃字段
 */
@property(nonatomic, assign) CGFloat audioRecordStartTime __deprecated_msg("deprecated");

/**
 创建一个图片片段

 @param path 图片路径
 @param duration 图片时长
 @param animDuration 过渡动画时长
 @return 图片片段
 */
- (instancetype)initWithImagePath:(NSString *)path duration:(CGFloat)duration animDuration:(CGFloat)animDuration;

/**
 创建一个gif片段

 @param path gif路径
 @return gif片段
 */
- (instancetype)initWithGifPath:(NSString *)path;

/**
 创建一个gif片段

 @param path gif路径
 @param startTime 指定gif的开始播放时间
 @param duration 指定gif的持续播放时间
 @return gif片段
 */
- (instancetype)initWithGifPath:(NSString *)path startTime:(CGFloat)startTime duration:(CGFloat)duration;

/**
 创建一个视频片段

 @param path 视频路径
 @param animDuration 过渡动画时长
 @return 视频片段
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
- (instancetype)initWithVideoPath:(NSString *)path startTime:(CGFloat)startTime duration:(CGFloat)duration animDuration:(CGFloat)animDuration;

/**
 API_AVAILABLE(3.7.0)

 添加动画 注意：1.主流不支持alpha帧动画 2.在倒播特效下，不支持此功能

 @param action 动画
 */
- (void)runAction:(AliyunAction *)action;

/**
 API_AVAILABLE(3.7.0)

 停止动画

 @param action 动画
 */
- (void)stopAction:(AliyunAction *)action;

/**
 API_AVAILABLE(3.7.0)

 获取所有的动画

 @return 动画数组
 */
- (NSArray *)allActions;

@end

@protocol AliyunClip;

/**
 sdk内部使用类
 */
@interface AliyunTrack : AliyunJSONModel

/**
 track id
 */
@property(nonatomic, assign) int idTrack;

/**
 音量
 */
@property(nonatomic, assign) float volume;

/**
 片段列表
 */
@property(nonatomic, strong) NSMutableArray<AliyunClip *> *clipList;

@end
