//
//  AliyunPublishManager.h
//  QUSDK
//
//  Created by Worthy on 2017/10/27.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliyunVodPublishManager.h"
#import "AliyunEditor.h"


@interface AliyunUploadSVideoInfo : NSObject
// 标题
@property (nonatomic, copy) NSString* title;
// 标签
@property (nonatomic, copy) NSString* tags;
// 描述
@property (nonatomic, copy) NSString* desc;
// 分类
@property (nonatomic, strong) NSNumber* cateId;

@property (nonatomic, assign) BOOL isProcess;
@property (nonatomic, assign) BOOL isShowWaterMark;
@property (nonatomic, strong) NSNumber* priority;
@property (nonatomic, copy) NSString* storageLocation;
@property (nonatomic, copy) NSString* templateGroupId;

@end


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
 上传超时，开始重试
 */
- (void)uploadRetry;

/**
 重试结束，继续上传
 */
- (void)uploadRetryResume;

@end

@interface AliyunPublishManager : NSObject

/**
 导出回调
 */
@property (nonatomic, weak) id<AliyunIExporterCallback> exportCallback;

/**
 上传回调
 */
@property (nonatomic, weak) id<AliyunIUploadCallback> uploadCallback;

/**
 导出视频路径
 */
@property (nonatomic, copy) NSString *outputPath;

/**
 上传是否转码,默认值YES
 */
@property (nonatomic, assign) BOOL transcode;


/**
 上传超时重试次数,默认值INT_MAX
 */
@property (nonatomic, assign) uint32_t maxRetryCount;


/**
 上传超时重试间隔，默认30秒
 */
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
 设置退后台是否取消导出合成
 
 默认值NO:退后台暂停合成，回到前台继续合成,YES:退后台取消合成
 @param flag flag
 */
- (void)setCancelExportInResignActive:(BOOL)flag;
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
