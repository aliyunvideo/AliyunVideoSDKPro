//
//  AliyunCrop.h
//  qurecorder
//
//  Created by dangshuai on 17/1/13.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunVideoParam.h"
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, AliyunCropCutMode) {
    AliyunCropCutModeScaleAspectFill = 0,     // 填充黑边
    AliyunCropModeScaleAspectCut = 1          // 裁剪画面
};



@protocol AliyunCropDelegate <NSObject>

/**
 裁剪失败时错误回调

 @param error 错误码
 */
- (void)cropOnError:(int)error;

/**
 裁剪进度回调

 @param progress 当前进度
 */
- (void)cropTaskOnProgress:(float)progress;

/**
 退出回调  
 裁剪完成时回调
 */
- (void)cropTaskOnComplete;
/**
 取消回调
 主动取消或退后台时回调
 */
- (void)cropTaskOnCancel;

@end

@interface AliyunCrop : NSObject

@property (nonatomic, weak) id<AliyunCropDelegate> delegate;
/**
 视频/音乐源文件路径
 */
@property (nonatomic, copy) NSString *inputPath;

/**
 裁剪完成后的文件存放路径
 */
@property (nonatomic, copy) NSString *outputPath;

/**
 裁剪后视频尺寸
 */
@property (nonatomic, assign) CGSize outputSize;

/**
 截取时间起点(单位：秒)
 */
@property (nonatomic, assign) float startTime;

/**
 截取时间终点(单位：秒)
 */
@property (nonatomic, assign) float endTime;

/**
 视频片段过渡动画时间(单位：秒)
 */
@property (nonatomic, assign) long fadeDuration;

/**
 裁剪模式
 */
@property (nonatomic, assign) AliyunCropCutMode cropMode;

/**
 保留的视频尺寸 (cropMode为0时 无效) 裁剪的有效区域
 */
@property (nonatomic, assign) CGRect rect;


/**
 视频质量 默认：AliyunVideoQualityMedium
 */
@property (nonatomic, assign) AliyunVideoQuality videoQuality;

/**
 帧率 默认：25
 */
@property (nonatomic, assign) int fps;

/**
 关键帧间隔 默认：5
 */
@property (nonatomic, assign) int gop;

/**
 编码方式 0软编   1硬编
 */
@property (nonatomic, assign) int encodeMode;  // 0软编   1硬编

/**
 码率
 */
@property (nonatomic, assign) int bitrate;

/**
 是否启用gpu裁剪
 */
@property (nonatomic, assign) BOOL useHW;

/**
 视频填充模式下，填充的背景颜色
 */
@property (nonatomic, strong) UIColor *fillBackgroundColor;

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

