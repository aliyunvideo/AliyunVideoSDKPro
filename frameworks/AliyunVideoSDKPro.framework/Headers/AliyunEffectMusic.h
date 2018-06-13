//
//  AliyunEffectMusic.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/17.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"
#include <CoreGraphics/CoreGraphics.h>

@interface AliyunEffectMusic : AliyunEffect
@property (nonatomic, assign) CGFloat startTime;
@property (nonatomic, assign) CGFloat duration;
@property (nonatomic, assign) CGFloat streamStartTime;
@property (nonatomic, assign) CGFloat streamDuration;
@property (nonatomic, assign) int audioMixWeight;     // 仅对mv和音乐有效，0-100
@end
