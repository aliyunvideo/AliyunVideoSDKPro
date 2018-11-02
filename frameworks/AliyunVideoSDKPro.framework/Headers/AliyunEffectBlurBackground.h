//
//  AliyunEffectBlurBackground.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/6/29.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"

@interface AliyunEffectBlurBackground : AliyunEffect

@property(nonatomic, assign) float streamStartTime;
@property(nonatomic, assign) float streamEndTime;
@property(nonatomic, assign) int targetStreamId;//作用的目标流的ID 一定需要设置
@property(nonatomic, assign) float blurRadius; // 0-29的范围

- (id)initWithRestore:(NSDictionary *)dict;

@end
