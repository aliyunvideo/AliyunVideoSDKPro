//
//  AliyunCrop.h
//  qurecorder
//
//  Created by dangshuai on 17/1/13.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunVideoParam.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 裁剪模式

 - AliyunCropCutModeScaleAspectFill: 填充
 - AliyunCropModeScaleAspectCut: 裁剪
 */
/****
 Crop modes.

 - AliyunCropCutModeScaleAspectFill: Fill mode.
 - AliyunCropModeScaleAspectCut: Cut mode.
 */
typedef NS_ENUM(NSInteger, AliyunCropCutMode) { AliyunCropCutModeScaleAspectFill = 0, AliyunCropModeScaleAspectCut = 1 };

/**
 裁剪回调协议
 */
/****
 The protocol of crop callbacks. 
 */
@protocol AliyunCropDelegate <NSObject>

/**
 裁剪失败回调

 @param error 错误码
 */
/****
 The callback when an error occurs during the cropping process.
 
 @param error The error code.
 */
- (void)cropOnError:(int)error;

/**
 裁剪进度回调

 @param progress 当前进度 0-1
 */
/****
 The callback that outputs the progress of the cropping process.
 
 @param progress The current cropping progress. Valid values: [0, 1]
 */
- (void)cropTaskOnProgress:(float)progress;

/**
 裁剪完成回调
 */
/****
 The callback when the cropping process is complete.
 */
- (void)cropTaskOnComplete;

/**
 主动取消或退后台时回调
 */
/****
 The callback when the cropping process is canceled.
 */
- (void)cropTaskOnCancel;

@end

/**
 裁剪类
 */
/****
 A crop class.
 */
@interface AliyunCrop : NSObject

/**
 裁剪回调
 */
/****
 The crop callback.
 */
@property(nonatomic, weak) id<AliyunCropDelegate> delegate;

/**
 视频/音乐源文件路径

 必选参数
 */
/****
 The path of the source video/audio file.
 Required.
 */
@property(nonatomic, copy) NSString *inputPath;

/**
 裁剪完成后的文件存放路径

 必选参数
 如果是多级目录，需要保证目录已经创建完成
 */
/****
 The path to save the cropped file.
 Required. Specify a valid path.
 */
@property(nonatomic, copy) NSString *outputPath;

/**
 裁剪后视频分辨率

 视频分辨率必须为偶数
 裁剪音乐时无需设置
 */
/****
 The resolution of the video after cropping.
 Even numbers only.
 Optional when cropping audio files.
 */
@property(nonatomic, assign) CGSize outputSize;

/**
 截取时间起点

 单位：秒
 */
/****
 The crop start time in seconds.
 */
@property(nonatomic, assign) float startTime;

/**
 截取时间终点

 单位：秒
 */
/****
 The crop end time in seconds.
 */
@property(nonatomic, assign) float endTime;

/**
 视频片段过渡动画时间

 无效接口，已废弃
 */
/****
 The transition duration of the video clip.
 Deprecated.
 */
@property(nonatomic, assign) long fadeDuration __deprecated_msg("deprecated");

/**
 裁剪模式

 裁剪音乐时无需设置
 */
/****
 The crop mode.
 Optional when cropping audio files.
 */
@property(nonatomic, assign) AliyunCropCutMode cropMode;

/**
 裁剪的有效区域

 保留的视频尺寸 (cropMode为0时 无效)
 裁剪音乐时无需设置
 单位：像素
 */
/****
 The crop rectangle.
 The resolution of the video to be kept. This setting only takes effect when the crop mode is set to 1.
 Optional when cropping audio files.
 Unit: pixels.
 */
@property(nonatomic, assign) CGRect rect;

/**
 视频质量

 默认值：AliyunVideoQualityMedium
 裁剪音乐时无需设置
 */
/****
 The video quality. Default value: AliyunVideoQualityMedium
 Optional when cropping audio files.
 */
@property(nonatomic, assign) AliyunVideoQuality videoQuality;

/**
 帧率

 默认：25
 裁剪音乐时无需设置
 */
/****
 The video frame rate. Default value: 25
 Optional when cropping audio files.
 */
@property(nonatomic, assign) int fps;

/**
 关键帧间隔

 默认：5
 裁剪音乐时无需设置
 */
/****
 The GOP size. Default value: 5
 Optional when cropping audio files.
 */
@property(nonatomic, assign) int gop;

/**
 编码方式

 软编：0
 硬编：1
 默认硬编
 */
/****
 The encoding mode.
 0: Software encoding.
 1: Hardware encoding.
 Default is hardware encoding.
 */
@property(nonatomic, assign) int encodeMode; 

/**
 码率

 单位：bps
 裁剪音乐时无需设置
 */
/****
 The video bitrate.
 Unit: bit/s
 Optional when cropping audio files.
 */
@property(nonatomic, assign) int bitrate;

/**
 是否启用gpu裁剪

 裁剪音乐时无需设置
 */
/****
 Whether to enable GPU cropping.
 Optional when cropping audio files.
 */
@property(nonatomic, assign) BOOL useHW;

/**
 是否开启优化

 开启后只裁剪时间将不走编解码
 裁剪音乐时无需设置
 默认关闭
 */
/****
 Whether to enable optimization. 
 When set to true, video is cropped without decoding or encoding.
 Optional when cropping audio files.
 Default is false.
 */
@property(nonatomic, assign) BOOL shouldOptimize;

/**
 背景颜色

 视频填充模式下有效
 裁剪音乐时无需设置
 */
/****
 The background color.
 This setting only takes effect when the crop mode is set to 0.
 Optional when cropping audio files.
 */
@property(nonatomic, strong) UIColor *fillBackgroundColor;

/**
 初始化裁剪

 @param delegate AliyunCropDelegate代理
 @return AliyunCrop
 */
/****
 Initializer.

 @param delegate The AliyunCropDelegate object.
 @return AliyunCrop
 */
- (instancetype)initWithDelegate:(id<AliyunCropDelegate>)delegate;

/**
 开始裁剪
 */
/****
 Starts cropping.
 */
- (int)startCrop;

/**
 取消裁剪
 */
/****
 Cancels cropping.
 */
- (void)cancel;

/**
 版本号

 @return 版本号
 */
/****
 Gets the SDK version.

 @return The SDK version.
 */
+ (NSString *)version __deprecated_msg("deprecated");

@end
