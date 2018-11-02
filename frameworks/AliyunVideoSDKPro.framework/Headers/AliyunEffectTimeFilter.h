//
//  AliyunEffectTimeFilter.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/2/26.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"

typedef enum : NSUInteger {
    TimeFilterTypeSpeed,//变速
    TimeFilterTypeRepeat,//反复
    TimeFilterTypeInvert,//倒放
} TimeFilterType;


@interface AliyunEffectTimeFilter : AliyunEffect

/**
 时间特效开始时间
 */
@property (nonatomic, assign) float startTime;

/**
 时间特效结束时间
 */
@property (nonatomic, assign) float endTime;

/**
 时间特效滤镜
 */
@property (nonatomic, assign) TimeFilterType type;

/**
 速率、在变速类型下生效 范围建议 0.5 - 2
 */
@property (nonatomic, assign) float param;

/**
 是否保留播放轴时长  举例：如果10s视频，全程慢速2倍，如果originDuration为YES，则播放轴为10s，如果为NO,则播放轴为20s。
 */
@property (nonatomic, assign) BOOL originDuration;

- (id)initWithRestore:(NSDictionary *)dict;

@end
