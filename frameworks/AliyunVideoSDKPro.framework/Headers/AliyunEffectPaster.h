//
//  AliyunEffectGif.h
//  qurecorder
//
//  Created by Vienta on 2017/1/7.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//



#import "AliyunEffectPasterBase.h"
#import <UIKit/UIKit.h>
#import "AliyunEffectPasterTimeItem.h"
#import "AliyunEffectPasterFrameItem.h"

typedef NS_ENUM(NSInteger, AliyunPasterType) {
    AliyunPasterTypeNormal,
    AliyunPasterTypeFace,
};

/**
 动图（纯序列帧的动图,包含人脸和普通两种类型）
 */
@interface AliyunEffectPaster : AliyunEffectPasterBase

@property (nonatomic, assign) AliyunPasterType type;
@property (nonatomic, strong) UIImage *kernelImage;//关键帧图片
@property (nonatomic, copy) NSArray<AliyunEffectPasterTimeItem *> *timeItems;
@property (nonatomic, copy) NSArray<AliyunEffectPasterFrameItem *> *frameItems;
@property (nonatomic, assign) CGFloat originDuration;//原始时长

- (AliyunEffectPaster*)copyAnother;

- (id)initWithRestore:(NSDictionary *)dict;

@end
