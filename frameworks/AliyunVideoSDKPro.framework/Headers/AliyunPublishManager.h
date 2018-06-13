//
//  AliyunPublishManager.h
//  QUSDK
//
//  Created by Worthy on 2017/10/27.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "AliyunEditor.h"

@protocol AliyunIUploadCallback <NSObject>

/**
 上传成功

 @param vid 视频vid
 @param imageUrl 图片路径
 */
- (void)uploadSuccessWithVid:(NSString *)vid imageUrl:(NSString *)imageUrl;

/**
 上传失败

 @param code 错误码
 @param message 错误日志
 */
- (void)uploadFailedWithCode:(NSString *)code message:(NSString *)message;

/**
 上传进度

 @param uploadedSize 已上传的文件大小
 @param totalSize 文件总大小
 */
- (void)uploadProgressWithUploadedSize:(long long)uploadedSize totalSize:(long long)totalSize;

/**
 token过期
 */
- (void)uploadTokenExpired;

/**
 开始重试
 */
- (void)uploadRetry;

/**
 重试完成，继续上传
 */
- (void)uploadRetryResume;

@end

@interface AliyunUploadSVideoInfo : NSObject
@property (nonatomic, strong) NSString* title;
@property (nonatomic, strong) NSString* tags;
@property (nonatomic, strong) NSString* desc;
@property (nonatomic, strong) NSNumber* cateId;
@end

@interface AliyunPublishManager : NSObject

@property (nonatomic, weak) id<AliyunIExporterCallback> exportCallback;
@property (nonatomic, weak) id<AliyunIUploadCallback> uploadCallback;

@property (nonatomic, copy, readonly) NSString *outputPath;

@property (nonatomic, assign) BOOL transcode;

@property (nonatomic, assign) uint32_t maxRetryCount;

@property (nonatomic, assign) NSTimeInterval timeoutIntervalForRequest;


/**
 设置水印
 
 @param waterMark 水印
 */
- (int)setWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置片尾水印
 
 @param waterMark 片尾水印
 */
- (int)setTailWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置片尾水印

 @param image 水印图片
 @param frame 水印位置
 @param duration 水印时长
 */
- (void)setTailWaterMark:(UIImage *)image frame:(CGRect)frame duration:(CGFloat)duration __deprecated_msg("use setTailWaterMark:(AliyunEffectImage *)waterMark");

/**
 合成视频

 @param taskPath taskPath
 @param outputPath 输出视频路径
 @return 接口调用是否成功
 */
- (BOOL)exportWithTaskPath:(NSString *)taskPath outputPath:(NSString *)outputPath;

/**
 取消合成
 */
- (void)cancelExport;


/**
 上传视频

 @param imagePath 视频缩略图
 @param svideoInfo 视频描述信息
 @param accessKeyId 服务端返回的临时accessKeyId
 @param accessKeySecret 服务端返回的临时accessKeySecret
 @param accessToken 服务端返回的临时accessToken
 @return 接口调用是否成功
 */
- (BOOL)uploadWithImagePath:(NSString *)imagePath
                 svideoInfo:(AliyunUploadSVideoInfo *)svideoInfo
                accessKeyId:(NSString *)accessKeyId
            accessKeySecret:(NSString *)accessKeySecret
                accessToken:(NSString *)accessToken;

/**
 刷新sts

 @param accessKeyId 服务端返回的临时accessKeyId
 @param accessKeySecret 服务端返回的临时accessKeySecret
 @param accessToken 服务端返回的临时accessKeySecret
 @param expireTime 服务端返回的过期时间
 */
- (void)refreshWithAccessKeyId:(NSString *)accessKeyId
               accessKeySecret:(NSString *)accessKeySecret
                   accessToken:(NSString *)accessToken
                    expireTime:(NSString *)expireTime;

/**
 取消上传
 */
- (void)cancelUpload;

@end
