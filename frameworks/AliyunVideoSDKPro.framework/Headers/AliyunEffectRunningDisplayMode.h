//
//  AliyunEffectRunningDisplayMode.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/7/18.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"

typedef NS_ENUM(NSInteger, AliyunRunningMode) {
    AliyunRunningModeFit = 0,          // 裁剪
    AliyunRunningModeFill = 1          // 填充
};

@interface AliyunEffectRunningDisplayMode : AliyunEffect

@property(nonatomic, assign) float streamStartTime;
@property(nonatomic, assign) float streamEndTime;
@property(nonatomic, assign) AliyunRunningMode mode;//填充:0 裁剪:1
@property(nonatomic, assign) int targetStreamId;//作用的目标流的id

- (id)initWithRestore:(NSDictionary *)dict;

@end
