//
//  AliyunEffectTimeFilter.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/2/26.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffect.h"

/**
 时间特效类型

 - TimeFilterTypeSpeed: 变速
 - TimeFilterTypeRepeat: 反复
 - TimeFilterTypeInvert: 倒放
 */
typedef NS_ENUM(NSInteger, TimeFilterType) {
    TimeFilterTypeSpeed,
    TimeFilterTypeRepeat,
    TimeFilterTypeInvert,
};

/**
 时间特效model类
 */
@interface AliyunEffectTimeFilter : AliyunEffect

/**
 时间特效开始时间
 */
@property(nonatomic, assign) float startTime;

/**
 时间特效结束时间
 */
@property(nonatomic, assign) float endTime;

/**
 时间特效
 */
@property(nonatomic, assign) TimeFilterType type;

/**
 时间特效参数

 1.在变速类型下代表速率，范围建议 0.5 - 2
 2.在反复类型下代表反复次数，内部取整型
 */
@property(nonatomic, assign) float param;

/**
 是否保留播放轴时长

 举例：如果10s视频，全程慢速2倍，如果originDuration为YES，则播放轴为10s，如果为NO,则播放轴为20s。
 */
@property(nonatomic, assign) BOOL originDuration;

/**
 内部调用接口

 @param dict dict
 @return AliyunEffectTimeFilter
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
