//
//  AliyunEffectPasterBase.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/3.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"
#import <CoreGraphics/CoreGraphics.h>

static const CGFloat kQUSDKPasterBase = 640.f;

struct PasterPosition {
    CGFloat centerX;
    CGFloat centerY;
    CGFloat width;
    CGFloat height;
};
typedef struct PasterPosition PasterPosition;

/**
 所有动图 字幕的基类
 */
@interface AliyunEffectPasterBase : AliyunEffect

@property (nonatomic, assign) CGFloat startTime;//开始时间
@property (nonatomic, assign) CGFloat endTime;//结束时间
@property (nonatomic, assign) CGFloat minDuration;//最短时间
@property (nonatomic, assign) CGFloat rotate;//旋转角度
@property (nonatomic, assign) CGSize displaySize;//editzoneview
@property (nonatomic, assign) CGSize outputSize;//动图所在的视频的输入分辨率
@property (nonatomic, assign) CGRect frame;//位置大小
@property (nonatomic, assign) CGPoint position;//位置
@property (nonatomic, assign) CGSize size;//大小
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) BOOL mirror;

- (id)initWithDict:(NSDictionary *)dict;

- (PasterPosition)convertToPasterBaseSize;

- (PasterPosition)convertToDisplaySize;

@end
