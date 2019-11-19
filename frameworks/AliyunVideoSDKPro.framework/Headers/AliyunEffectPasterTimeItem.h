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
@interface AliyunEffectPasterTimeItem : NSObject

/**
 该动画场景开始的时间
 */
@property(nonatomic, assign) CGFloat beginTime;

/**
 该动画场景结束的时间
 */
@property(nonatomic, assign) CGFloat endTime;

/**
 是否可以压缩，即是否能够调整该场景的时长
 */
@property(nonatomic, assign) BOOL shrink;

/**
 该场景的最小持续时间
 */
@property(nonatomic, assign) CGFloat minTime;

/**
 该场景的最长持续时间
 */
@property(nonatomic, assign) CGFloat maxTime;

@end
