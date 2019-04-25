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
typedef NS_ENUM(NSInteger, AliyunClipType) { AliyunClipVideo = 0, AliyunClipImage = 1, AliyunClipAudio = 2, AliyunClipGif = 3 };

@interface AliyunClip : AliyunJSONModel
/*
 mediaType    :  类型，视频或图片image，类型改为0,1 0标示视频，1标示图片
 mediaHeight  :  图片/视频高
 mediaWidth   :  图片/视频宽
 src          :  资源路径
 startTime    :  视频/配音 开始时间
 fadeDuration :  过渡时长
 displayMode  :  显示模式 0:截断填充 1:黑边填充
 rotation     :  图片/视频角度
 duration     :  图片/视频/配音时长
 streamId     :  图片/视频/配音流id，sdk内部生成，请勿直接赋值
 transitionEffect: 转场效果 是与前一段视频段进行转场
 recordStartTime: 音频录制开始时间，在播放轴上的时间
 */
@property(nonatomic, assign) AliyunClipType mediaType;
@property(nonatomic, assign) int mediaHeight;
@property(nonatomic, assign) int mediaWidth;
@property(nonatomic, copy) NSString *src;
@property(nonatomic, assign) CGFloat startTime;
@property(nonatomic, assign) CGFloat fadeDuration;
@property(nonatomic, assign) int displayMode;
@property(nonatomic, assign) int rotation;
@property(nonatomic, assign) CGFloat duration;
@property(nonatomic, assign) int streamId;
@property(nonatomic, strong) AliyunTransitionEffect *transitionEffect;
@property(nonatomic, assign) CGFloat audioRecordStartTime;
@property(nonatomic, strong) NSMutableArray<AliyunAudioEffect *> *audioEffects;

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

@interface AliyunTrack : AliyunJSONModel

@property(nonatomic, assign) int idTrack;
@property(nonatomic, assign) float volume;
@property(nonatomic, strong) NSMutableArray<AliyunClip *> *clipList;

@end
