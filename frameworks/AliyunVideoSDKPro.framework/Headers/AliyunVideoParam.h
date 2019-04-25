//
//  AliyunVideoParam.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/21.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AliyunVideoQuality) {
    AliyunVideoQualityVeryHight,
    AliyunVideoQualityHight,
    AliyunVideoQualityMedium,
    AliyunVideoQualityLow,
    AliyunVideoQualityPoor,
    AliyunVideoQualityExtraPoor
};

typedef NS_ENUM(NSInteger, AliyunScaleMode) {
    AliyunScaleModeFit = 0, // 裁剪
    AliyunScaleModeFill = 1 // 填充
};

typedef NS_ENUM(NSInteger, AliyunVideoCodecType) {
    AliyunVideoCodecTypeAuto = 0,
    AliyunVideoCodecHardware,
    AliyunVideoCodecFFmpeg,
    AliyunVideoCodecOpenh264,
    AliyunVideoCodecX264
};

@interface AliyunVideoParam : NSObject

/**
 帧率 默认25 建议20 - 60 不超过60
 */
@property(nonatomic, assign) int fps;

/**
 关键帧间隔 >1
 */
@property(nonatomic, assign) int gop;

/**
 码率  单位bps
 建议
 480P:1000000-2000000
 540P:2000000-3000000
 720P:2000000-4000000
 1080:2000000-6000000
 设置bitrate参数后，videoQuality设置无效
 */
@property(nonatomic, assign) int bitrate;

/**
 视频质量
 */
@property(nonatomic, assign) AliyunVideoQuality videoQuality;

/**
 裁剪或者填充模式
 */
@property(nonatomic, assign) AliyunScaleMode scaleMode;

/**
 编码类型
 */
@property(nonatomic, assign) AliyunVideoCodecType codecType;

/**
 创建一个AliyunVideoParam对象，并设置为默认属性

 @return AliyunVideoParam对象
 */
+ (instancetype)defaultVideoParam;

@end
