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

typedef NS_ENUM(NSInteger, AliyunCropCutMode) {
    AliyunCropCutModeScaleAspectFill = 0, // 填充黑边
    AliyunCropModeScaleAspectCut = 1      // 裁剪画面
};

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

@interface AliyunCrop : NSObject

@property(nonatomic, weak) id<AliyunCropDelegate> delegate;

/**
 视频/音乐源文件路径，必选参数
 */
@property(nonatomic, copy) NSString *inputPath;

/**
 裁剪完成后的文件存放路径，如果是多级目录，需要保证目录已经创建完成，必选参数
 */
@property(nonatomic, copy) NSString *outputPath;

/**
 裁剪后视频分辨率
 视频分辨率必须为偶数，裁剪音乐时无需设置
 */
@property(nonatomic, assign) CGSize outputSize;

/**
 截取时间起点(单位：秒)
 */
@property(nonatomic, assign) float startTime;

/**
 截取时间终点(单位：秒)
 */
@property(nonatomic, assign) float endTime;

/**
 视频片段过渡动画时间(单位：秒) 无效接口，已废弃
 */
@property(nonatomic, assign) long fadeDuration;

/**
 裁剪模式
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) AliyunCropCutMode cropMode;

/**
 保留的视频尺寸 (cropMode为0时 无效) 裁剪的有效区域
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) CGRect rect;

/**
 视频质量 默认：AliyunVideoQualityMedium
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) AliyunVideoQuality videoQuality;

/**
 帧率 默认：25
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) int fps;

/**
 关键帧间隔 默认：5
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) int gop;

/**
 编码方式

 0软编  1硬编  默认硬编
 */
@property(nonatomic, assign) int encodeMode; // 0软编   1硬编

/**
 码率 bps
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) int bitrate;

/**
 是否启用gpu裁剪
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) BOOL useHW;

/**
 是否开启优化，开启后只裁剪时间将不走编解码，默认关闭
 裁剪音乐时无需设置
 */
@property(nonatomic, assign) BOOL shouldOptimize;

/**
 视频填充模式下，填充的背景颜色
 裁剪音乐时无需设置
 */
@property(nonatomic, strong) UIColor *fillBackgroundColor;

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
+ (NSString *)version;

@end
