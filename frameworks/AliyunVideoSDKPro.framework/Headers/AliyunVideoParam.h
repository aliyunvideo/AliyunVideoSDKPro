//
//  AliyunVideoParam.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/21.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 输出视频质量

 - AliyunVideoQualityVeryHight: VeryHight
 - AliyunVideoQualityHight: Hight
 - AliyunVideoQualityMedium: Medium
 - AliyunVideoQualityLow: Low
 - AliyunVideoQualityPoor: Poor
 - AliyunVideoQualityExtraPoor: ExtraPoor
 */
/****
 Video quality types.

 - AliyunVideoQualityVeryHight: Very High
 - AliyunVideoQualityHight: Hight
 - AliyunVideoQualityMedium: Medium
 - AliyunVideoQualityLow: Low
 - AliyunVideoQualityPoor: Very Low
 - AliyunVideoQualityExtraPoor: Extremely Low
 */
typedef NS_ENUM(NSInteger, AliyunVideoQuality) {
    AliyunVideoQualityVeryHight,
    AliyunVideoQualityHight,
    AliyunVideoQualityMedium,
    AliyunVideoQualityLow,
    AliyunVideoQualityPoor,
    AliyunVideoQualityExtraPoor
};

/**
 裁剪模式

 - AliyunScaleModeFit: 裁剪
 - AliyunScaleModeFill: 填充
 */
/****
 Crop modes.

 - AliyunScaleModeFit: Cut mode
 - AliyunScaleModeFill: Fill mode
 */
typedef NS_ENUM(NSInteger, AliyunScaleMode) {
    AliyunScaleModeFit = 0,
    AliyunScaleModeFill = 1
};

/**
 内容模式
 
 - AlivcContentModeScaleAspectFit: 填充模式
 - AlivcContentModeScaleAspectFill: 裁剪模式
 */
/****
 content modes.
 
 - AlivcContentModeScaleAspectFit: Fill mode
 - AlivcContentModeScaleAspectFill: Cut mode
 */
typedef NS_ENUM(NSInteger, AlivcContentMode) {
    AlivcContentModeScaleAspectFit = 1,
    AlivcContentModeScaleAspectFill = 0,
};

/**
 编码器类型

 ios只开放部分编码类型
 - AliyunVideoCodecTypeAuto: 自动
 - AliyunVideoCodecHardware: 硬编
 - AliyunVideoCodecFFmpeg: ffmpeg
 - AliyunVideoCodecOpenh264: Openh264
 - AliyunVideoCodecX264: X264
 */
/****
 Encoder types.
 
 Only the first three encoder types are supported in iOS.
 - AliyunVideoCodecTypeAuto: Automatic
 - AliyunVideoCodecHardware: Hardware encoding
 - AliyunVideoCodecFFmpeg: FFmpeg
 - AliyunVideoCodecOpenh264: OpenH264
 - AliyunVideoCodecX264: x264
 */
typedef NS_ENUM(NSInteger, AliyunVideoCodecType) {
    AliyunVideoCodecTypeAuto = 0,
    AliyunVideoCodecHardware,
    AliyunVideoCodecFFmpeg,
    AliyunVideoCodecOpenh264,
    AliyunVideoCodecX264
};

/**
 视频参数设置类
 */
/****
 A class that defines video parameter settings.
 */
@interface AliyunVideoParam : NSObject

/**
 帧率

 默认25 建议20 - 60 不超过60
 */
/****
 The frame rate.
 
 Default is 25. Recommended values: [20, 60]
 */
@property(nonatomic, assign) int fps;

/**
 关键帧间隔

 gop > 1
 */
/****
 The GOP size.
 
 gop > 1
 */
@property(nonatomic, assign) int gop;

/**
 码率

 单位bps 建议：
 480P:1000000-2000000
 540P:2000000-3000000
 720P:2000000-4000000
 1080:2000000-6000000
 设置bitrate参数后，videoQuality设置无效
 */
/****
 The bitrate.
 
 Unit: bit/s 
 Recommended values:
 480P: 1,000,000-2,000,000
 540P: 2,000,000-3,000,000
 720P: 2,000,000-4,000,000
 1080: 2,000,000-6,000,000
 If specified, the bitrate parameter overrides the videoQuality parameter.
 */
@property(nonatomic, assign) int bitrate;

/**
 视频质量
 */
/****
 The video quality.
 */
@property(nonatomic, assign) AliyunVideoQuality videoQuality;

/**
 裁剪或者填充模式
 */
/****
 The crop mode.
 */
@property(nonatomic, assign) AliyunScaleMode scaleMode;

/**
 编码类型
 */
/****
 The encoder type.
 */
@property(nonatomic, assign) AliyunVideoCodecType codecType;

/**
 创建一个AliyunVideoParam对象，并设置为默认属性

 @return AliyunVideoParam对象
 */
/****
 Creates an AliyunVideoParam object with default settings.

 @return An AliyunVideoParam object.
 */
+ (instancetype)defaultVideoParam;

@end
