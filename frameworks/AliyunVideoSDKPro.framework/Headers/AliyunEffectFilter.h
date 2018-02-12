//
//  AliyunEffectFilter.h
//  qurecorder
//
//  Created by Vienta on 2017/1/7.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"

@interface AliyunEffectFilter : AliyunEffect

@property (nonatomic, assign) float startTime;
@property (nonatomic, assign) float endTime;

- (id)initWithRestore:(NSDictionary *)dict;

@end
