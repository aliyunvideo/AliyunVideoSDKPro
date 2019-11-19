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
typedef NS_ENUM(NSInteger, AliyunScaleMode) {
    AliyunScaleModeFit = 0,
    AliyunScaleModeFill = 1
};

/**
 内容模式
 
 - AlivcContentModeScaleAspectFit: 填充模式
 - AlivcContentModeScaleAspectFill: 裁剪模式
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
@interface AliyunVideoParam : NSObject

/**
 帧率

 默认25 建议20 - 60 不超过60
 */
@property(nonatomic, assign) int fps;

/**
 关键帧间隔

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
