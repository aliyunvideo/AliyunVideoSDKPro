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
@interface AliyunClipManager : NSObject

/**
 视频最大时长

 默认8
 */
@property (nonatomic, assign) CGFloat maxDuration;

/**
 视频最小时长

 默认0.5
 */
@property (nonatomic, assign) CGFloat minDuration;

/**
 视频总时长
 */
@property (nonatomic, assign, readonly) CGFloat duration;

/**
 视频段数
 */
@property (nonatomic, assign, readonly) NSInteger partCount;

/**
 分段视频存储路径(物理路径)
 */
@property (nonatomic, strong, readonly) NSArray *videoAbsolutePaths;

/**
 第一段视频旋转角度
 */
@property (nonatomic, assign, readonly) int firstClipVideoRotation;

/**
 删除所有视频片段
 */
- (void)deleteAllPart;

/**
 删除最后一个视频片段
 */
- (void)deletePart;

/**
 删除某一个视频段

 @param index 视频段序列数
 */
- (void)deletePart:(NSInteger)index;

@end
