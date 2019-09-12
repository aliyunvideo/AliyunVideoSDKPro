//
//  AliyunClipManager.h
//  qurecorder
//
//  Created by Vienta on 2016/12/29.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 片段管理器
 */
/****
 A class that defines clip managers.
 */
@interface AliyunClipManager : NSObject

/**
 视频最大时长

 默认8
 */
/****
 The maximum duration of a video clip.
 
 Default is 8 seconds.
 */
@property (nonatomic, assign) CGFloat maxDuration;

/**
 视频最小时长

 默认0.5
 */
/****
 The minimum duration of a video clip.
 
 Default is 0.5 second.
 */
@property (nonatomic, assign) CGFloat minDuration;

/**
 视频总时长
 */
/****
 The total duration of video clips.
 */
@property (nonatomic, assign, readonly) CGFloat duration;

/**
 视频段数
 */
/****
 The number of video clips.
 */
@property (nonatomic, assign, readonly) NSInteger partCount;

/**
 分段视频存储路径(物理路径)
 */
/****
 The paths of video clips.
 */
@property (nonatomic, strong, readonly) NSArray *videoAbsolutePaths;

/**
 第一段视频旋转角度
 */
/****
 The rotation angle of the first video clip.
 */
@property (nonatomic, assign, readonly) int firstClipVideoRotation;

/**
 删除所有视频片段
 */
/****
 Deletes all video clips.
 */
- (void)deleteAllPart;

/**
 删除最后一个视频片段
 */
/****
 Deletes the last video clip.
 */
- (void)deletePart;

/**
 删除某一个视频段

 @param index 视频段序列数
 */
/****
 Deletes a video clip.

 @param index The index of the video clip to be deleted.
 */
- (void)deletePart:(NSInteger)index;

@end
