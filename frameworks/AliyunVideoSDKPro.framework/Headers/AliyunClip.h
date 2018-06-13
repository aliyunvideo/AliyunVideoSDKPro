//
//  AliyunClip.h
//  qurecorder
//
//  Created by dangshuai on 17/1/4.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliyunJSONModel.h"


@protocol AliyunClip;
typedef NS_ENUM(NSInteger,AliyunClipType) {
    AliyunClipVideo,
    AliyunClipImage
};

@interface AliyunClip : AliyunJSONModel
/*
 mediaType  :  类型，视频或图片image，类型改为0,1 0标示视频，1标示图片  
 mediaHeight:  图片/视频／图片的分辨率
 mediaWidth :
 src        :  
 startTime  :  图片/视频、配音 开始时间
 endTime    :  图片/视频、配音 结束时间
 rotation   :  图片/视频角度
 duration   :  图片
 */
@property (nonatomic, assign) AliyunClipType mediaType;
@property (nonatomic, assign) int mediaHeight;
@property (nonatomic, assign) int mediaWidth;
@property (nonatomic, copy) NSString *src;
@property (nonatomic, assign) CGFloat startTime;
@property (nonatomic, assign) CGFloat endTime;
@property (nonatomic, assign) CGFloat fadeDuration;
@property (nonatomic, assign) int displayMode;
@property (nonatomic, assign) int rotation;
@property (nonatomic, assign) CGFloat duration;
@property (nonatomic, assign) int streamId;

/**
 创建一个图片片段

 @param path 图片路径
 @param duration 图片时长
 @param animDuration 过渡动画时长
 @return 图片片段
 */
- (instancetype)initWithImagePath:(NSString *)path
                         duration:(CGFloat)duration
                     animDuration:(CGFloat)animDuration;


/**
 创建一个视频片段

 @param path 视频路径
 @param animDuration 过渡动画时长
 @return 视频片段
 */
- (instancetype)initWithVideoPath:(NSString *)path
                     animDuration:(CGFloat)animDuration;


/**
 创建一个视频片段

 @param path 视频路径
 @param startTime 相对原视频开始时间
 @param duration 视频片段时长
 @param animDuration 过渡动画时长
 @return 视频片段
 */
- (instancetype)initWithVideoPath:(NSString *)path
                        startTime:(CGFloat)startTime
                         duration:(CGFloat)duration
                     animDuration:(CGFloat)animDuration;

@end


@protocol AliyunClip;

@interface AliyunTrack : AliyunJSONModel

@property (nonatomic, assign) int idTrack;
@property (nonatomic, assign) float volume;
@property (nonatomic, strong) NSMutableArray<AliyunClip *> *clipList;

@end
