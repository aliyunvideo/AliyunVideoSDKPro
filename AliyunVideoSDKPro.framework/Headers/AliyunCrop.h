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
typedef NS_ENUM(NSInteger, AliyunCropCutMode) { AliyunCropCutModeScaleAspectFill = 0, AliyunCropModeScaleAspectCut = 1 };

/**
 裁剪回调协议
 */
@protocol AliyunCropDelegate <NSObject>

/**
 裁剪失败回调

 @param error 错误码
 */
- (void)cropOnError:(int)error;

/**
 裁剪进度回调

 @param progress 当前进度 0-1
 */
- (void)cropTaskOnProgress:(float)progress;

/**
 裁剪完成回调
 */
- (void)cropTaskOnComplete;

/**
 主动取消或退后台时回调
 */
- (void)cropTaskOnCancel;

@end

/**
 裁剪类
 */
@interface AliyunCrop : NSObject

/**
 裁剪回调
 */
@property(nonatomic, weak) id<AliyunCropDelegate> delegate;

/**
 视频/音乐源文件路径

 必选参数
 */
@property(nonatomic, copy) NSString *inputPath;

/**
 裁剪完成后的文件存放路径

 必选参数
 如果是多级目录，需要保证目录已经创建完成
 */
@property(nonatomic, copy) NSString *outputPath;

/**
 裁剪后视频分辨率

 视频分辨率必须为偶数
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) CGSize outputSize;

/**
 截取时间起点

 单位：秒
 */
@property(nonatomic, assign) float startTime;

/**
 截取时间终点

 单位：秒
 */
@property(nonatomic, assign) float endTime;

/**
 视频片段过渡动画时间

 无效接口，已废弃
 */
@property(nonatomic, assign) long fadeDuration __deprecated_msg("deprecated");

/**
 裁剪模式

 裁剪音乐时无需设置
 */
@property(nonatomic, assign) AliyunCropCutMode cropMode;

/**
 裁剪的有效区域

 保留的视频尺寸 (cropMode为0时 无效)
 裁剪音乐时无需设置
 单位：像素
 */
@property(nonatomic, assign) CGRect rect;

/**
 视频质量

 默认值：AliyunVideoQualityMedium
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) AliyunVideoQuality videoQuality;

/**
 帧率

 默认：25
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) int fps;

/**
 关键帧间隔

 默认：5
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) int gop;

/**
 编码方式

 软编：0
 硬编：1
 默认硬编
 */
@property(nonatomic, assign) int encodeMode; 

/**
 码率

 单位：bps
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) int bitrate;

/**
 是否启用gpu裁剪

 裁剪音乐时无需设置
 */
@property(nonatomic, assign) BOOL useHW;

/**
 是否开启优化

 开启后只裁剪时间将不走编解码
 裁剪音乐时无需设置
 默认关闭
 */
@property(nonatomic, assign) BOOL shouldOptimize;

/**
 背景颜色

 视频填充模式下有效
 裁剪音乐时无需设置
 */
@property(nonatomic, strong) UIColor *fillBackgroundColor;

/**
 初始化裁剪

 @param delegate AliyunCropDelegate代理
 @return AliyunCrop
 */
- (instancetype)initWithDelegate:(id<AliyunCropDelegate>)delegate;

/**
 开始裁剪
 */
- (int)startCrop;

/**
 取消裁剪
 */
- (void)cancel;

/**
 版本号

 @return 版本号
 */
+ (NSString *)version __deprecated_msg("deprecated");

@end
