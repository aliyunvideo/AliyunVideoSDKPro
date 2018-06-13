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
@property (nonatomic, assign) float startTime;
@property (nonatomic, assign) float endTime;
@property (nonatomic, assign) TimeFilterType type;
@property (nonatomic, assign) float param;//速率
@property (nonatomic, assign) BOOL originDuration;

- (id)initWithRestore:(NSDictionary *)dict;

@end
