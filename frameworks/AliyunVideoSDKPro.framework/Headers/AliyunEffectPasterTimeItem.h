//
//  AliyunEffectPasterTimeItem.h
//  QUSDK
//
//  Created by Vienta on 2017/5/8.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

/**
 动图的进场类
 */
/****
 A class that defines the rendering of sticker animations.
 */
@interface AliyunEffectPasterTimeItem : NSObject

/**
 该动画场景开始的时间
 */
/****
 The start time of the animation.
 */
@property(nonatomic, assign) CGFloat beginTime;

/**
 该动画场景结束的时间
 */
/****
 The end time of the animation. 
 */
@property(nonatomic, assign) CGFloat endTime;

/**
 是否可以压缩，即是否能够调整该场景的时长
 */
/****
 Whether the animation duration can be adjusted.
 */
@property(nonatomic, assign) BOOL shrink;

/**
 该场景的最小持续时间
 */
/****
 The minimum animation duration.
 */
@property(nonatomic, assign) CGFloat minTime;

/**
 该场景的最长持续时间
 */
/****
 The maximum animation duration.
 */
@property(nonatomic, assign) CGFloat maxTime;

@end
