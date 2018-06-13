//
//  AliyunEffectMV.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/17.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"

@interface AliyunEffectMV : AliyunEffect
@property(nonatomic, assign) int audioEffectVid;    // mv音乐流id
@property(nonatomic, assign) int disableAudio;      // 是否打开mv音乐
@property (nonatomic, assign) int audioMixWeight;     // 仅对mv和音乐有效，0-100
@end
