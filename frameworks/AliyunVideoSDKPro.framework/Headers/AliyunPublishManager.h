//
//  AliyunPublishManager.h
//  QUSDK
//
//  Created by Worthy on 2017/10/27.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEditor.h"
#import "AliyunVodPublishManager.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 上传视频信息设置类
 */
/****
 A class that defines video upload parameters.
 */
__attribute__((deprecated)) @interface AliyunUploadSVideoInfo : NSObject

/**
 视频点播参数，标题
 */
/****
 The ApsaraVideo VOD parameter: title.
 */
@property (nonatomic, copy) NSString* title;

/**
 视频点播参数，标签
 */
/****
 The ApsaraVideo VOD parameter: tags. 
 */
@property (nonatomic, copy) NSString* tags;

/**
 视频点播参数，描述
 */
/****
 The ApsaraVideo VOD parameter: description.
 */
@property (nonatomic, copy) NSString* desc;

/**
 视频点播参数，分类
 */
/****
 The ApsaraVideo VOD parameter: category.
 */
@property (nonatomic, strong) NSNumber* cateId;

/**
 视频点播参数，isProcess
 */
/****
 The ApsaraVideo VOD parameter: isProcess.
 */
@property (nonatomic, assign) BOOL isProcess;

/**
 视频点播参数，是否现显示水印
 */
/****
 The ApsaraVideo VOD parameter: whether to show watermarks.
 */
@property (nonatomic, assign) BOOL isShowWaterMark;

/**
 视频点播参数，优先级
 */
/****
 The ApsaraVideo VOD parameter: priority.
 */
@property (nonatomic, strong) NSNumber* priority;

/**
 视频点播参数，存储位置
 */
/****
 The ApsaraVideo VOD parameter: storage location.
 */
@property (nonatomic, copy) NSString* storageLocation;

/**
 视频点播参数，转码模版组id
 */
/****
 The ApsaraVideo VOD parameter: transcoding template group id.
 */
@property (nonatomic, copy) NSString* templateGroupId;

@end

/**
 上传回调协议
 */
/****
 The protocol of upload callbacks.
 */
__attribute__((deprecated)) @protocol AliyunIUploadCallback <NSObject>

/**
 上传成功

 @param vid 视频vid
 @param imageUrl 图片路径
 */
/****
 The callback when the upload is successful.

 @param vid The VID of the video.
 @param imageUrl The path of the thumbnail.
 */
- (void)uploadSuccessWithVid:(NSString *)vid imageUrl:(NSString *)imageUrl;

/**
 上传失败

 @param code 错误码
 @param message 错误日志
 */
/****
 The callback when an error occurs during upload.

 @param code The error code.
 @param message The error message.
 */
- (void)uploadFailedWithCode:(NSString *)code message:(NSString *)message;

/**
 上传进度

 @param uploadedSize 已上传的文件大小
 @param totalSize 文件总大小
 */
/****
 The callback that outputs the upload progress.

 @param uploadedSize The uploaded file size.
 @param totalSize The total file size.
 */
- (void)uploadProgressWithUploadedSize:(long long)uploadedSize totalSize:(long long)totalSize;

/**
 token过期
 */
/****
 The callback when the token expires.
 */
- (void)uploadTokenExpired;

/**
 上传超时，开始重试
 */
/****
 The callback when the upload is retried.
 */
- (void)uploadRetry;

/**
 重试结束，继续上传
 */
/****
 The callback when the retry is successful.
 */
- (void)uploadRetryResume;

@end

/**
 导出合成与上传管理器

 已废弃，请使用AliyunVodPublishManager代替
 */
/****
 A class that defines publish managers.

 Deprecated. Replaced by AliyunVodPublishManager.
 */
__attribute__((deprecated)) @interface AliyunPublishManager : NSObject

/**
 导出回调
 */
/****
 The export callback.
 */
@property (nonatomic, weak) id<AliyunIExporterCallback> exportCallback;

/**
 上传回调
 */
/****
 The upload callback.
 */
@property (nonatomic, weak) id<AliyunIUploadCallback> uploadCallback;

/**
 导出视频路径
 */
/****
 The video output path.
 */
@property (nonatomic, copy) NSString *outputPath;

/**
 上传是否转码,默认值YES
 */
/****
 Whether to enable transcoding. Default is YES.
 */
@property (nonatomic, assign) BOOL transcode;

/**
 上传超时重试次数,默认值INT_MAX
 */
/****
 The maximum number of retries. Default is INT_MAX.
 */
@property (nonatomic, assign) uint32_t maxRetryCount;

/**
 上传超时重试间隔，默认30秒
 */
/****
 The time interval between retries. Default is 30 seconds.
 */
@property (nonatomic, assign) NSTimeInterval timeoutIntervalForRequest;

/**
 设置水印

 @param waterMark 水印
 */
/****
 Sets a watermark.
 
 @param waterMark The watermark image.
 */
- (int)setWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置片尾水印

 @param waterMark 片尾水印
 */
/****
 Sets a watermark to the end of the video.
 
 @param waterMark The watermark image.
 */
- (int)setTailWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置片尾水印

 @param image 水印图片
 @param frame 水印位置
 @param duration 水印时长
 */
/****
 Sets a watermark to the end of the video.

 @param image The watermark image.
 @param frame The frame that contains the watermark. 
 @param duration The display duration of the watermark.
 */
- (void)setTailWaterMark:(UIImage *)image frame:(CGRect)frame duration:(CGFloat)duration __deprecated_msg("use setTailWaterMark:(AliyunEffectImage *)waterMark");

/**
 设置退后台是否取消导出合成

 默认值NO:退后台暂停合成，回到前台继续合成,YES:退后台取消合成
 @param flag flag
 */
/****
 Sets whether to cancel exporting when the app is set to run in the background.
 
 YES indicates cancel exporting. No indicates pause exporting. Default is NO.
 @param flag
 */
- (void)setCancelExportInResignActive:(BOOL)flag;

/**
 合成视频

 @param taskPath taskPath
 @param outputPath 输出视频路径
 @return 接口调用是否成功
 */
/****
 Starts exporting. 

 @param taskPath The path of the taskPath folder.
 @param outputPath The video output path. 
 @return Whether the invocation is successful.
 */
- (BOOL)exportWithTaskPath:(NSString *)taskPath outputPath:(NSString *)outputPath;

/**
 取消合成
 */
/****
 Cancels exporting.
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
/****
 Starts uploading.

 @param imagePath The path of the thumbnail.
 @param svideoInfo The description of the video.
 @param accessKeyId The temporary AccessKeyId returned by the server.
 @param accessKeySecret The temporary AccessKeySecret returned by the server.
 @param accessToken The STS token returned by the server.
 @return Whether the invocation is successful.
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
 @param accessToken 服务端返回的临时accessToken
 @param expireTime 服务端返回的过期时间
 */
/****
 Updates the STS token.

 @param accessKeyId The temporary AccessKeyId returned by the server.
 @param accessKeySecret The temporary AccessKeySecret returned by the server.
 @param accessToken The STS token returned by the server.
 @param expireTime The token expiration time returned by the server. 
 */
- (void)refreshWithAccessKeyId:(NSString *)accessKeyId
               accessKeySecret:(NSString *)accessKeySecret
                   accessToken:(NSString *)accessToken
                    expireTime:(NSString *)expireTime;

/**
 取消上传
 */
/****
 Cancels uploading.
 */
- (void)cancelUpload;

@end
