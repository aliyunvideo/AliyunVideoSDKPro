//
//  AliyunVodPublishManager.h
//  AliyunVideoSDKPro
//
//  Created by Worthy Zhang on 2018/12/28.
//  Copyright © 2018 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEditor.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class AliyunVodPublishManager;

/**
 上传回调类
 */
/****
 A class that defines upload callbacks.
 */
@protocol AliyunIVodUploadCallback <NSObject>

/**
 上传成功

 @param manager AliyunVodPublishManager
 */
/****
 The callback when the upload is successful.

 @param manager AliyunVodPublishManager
 */
- (void)publishManagerUploadSuccess:(AliyunVodPublishManager *)manager;

/**
 上传失败

 @param manager AliyunVodPublishManager
 @param code 错误码
 @param message 错误描述
 */
/****
 The callback when an error occurs during upload.

 @param manager AliyunVodPublishManager
 @param code The error code.
 @param message The error message.
 */
- (void)publishManager:(AliyunVodPublishManager *)manager uploadFailedWithCode:(NSString *)code message:(NSString *)message;

/**
 上传进度

 @param manager AliyunVodPublishManager
 @param uploadedSize 已上传数据大小
 @param totalSize 所有数据大小
 */
/****
 The callback that outputs the upload progress.

 @param manager AliyunVodPublishManager
 @param uploadedSize The uploaded file size.
 @param totalSize The total file size.
 */
- (void)publishManager:(AliyunVodPublishManager *)manager uploadProgressWithUploadedSize:(long long)uploadedSize totalSize:(long long)totalSize;

/**
 上传token过期

 @param manager AliyunVodPublishManager
 */
/****
 The callback when the token expires.

 @param manager AliyunVodPublishManager
 */
- (void)publishManagerUploadTokenExpired:(AliyunVodPublishManager *)manager;

/**
 上传超时，开始尝试重试

 @param manager AliyunVodPublishManager
 */
/****
 The callback when the upload is retried.

 @param manager AliyunVodPublishManager
 */
- (void)publishManagerUploadRetry:(AliyunVodPublishManager *)manager;

/**
 重试成功，开始继续上传

 @param manager AliyunVodPublishManager
 */
/****
 The callback when the retry is successful.

 @param manager AliyunVodPublishManager
 */
- (void)publishManagerUploadRetryResume:(AliyunVodPublishManager *)manager;

@end

/**
 上传状态

 - AliyunVodUploadImage: 上传图片
 - AliyunVodUploadVideo: 上传视频
 */
/****
 Upload types.

 - AliyunVodUploadImage: Image upload
 - AliyunVodUploadVideo: Video upload
 */
typedef NS_OPTIONS(NSInteger, AliyunVodUploadState) {
    AliyunVodUploadImage,
    AliyunVodUploadVideo,
};

/**
 发布管理器
 */
/****
 A class that defines publish managers.
 */
@interface AliyunVodPublishManager : NSObject

/**
 合成导出回调类
 */
/****
 The export callback.
 */
@property (nonatomic, weak) id<AliyunIExporterCallback> exportCallback;

/**
 上传回调类
 */
/****
 The upload callback.
 */
@property (nonatomic, weak) id<AliyunIVodUploadCallback> uploadCallback;

/**
 当前上传状态
 */
/****
 The upload state.
 */
@property (nonatomic, assign) AliyunVodUploadState uploadState;

/**
 上传视频本地路径
 */
/****
 The path of the video to be uploaded.
 */
@property (nonatomic, copy) NSString *videotPath;

/**
 上传图片本地路径
 */
/****
 The path of the image to be uploaded.
 */
@property (nonatomic, copy) NSString *imagePath;

#pragma mark - export

/**
 合成导出视频

 @param taskPath taskPath
 @param outputPath 导出视频路径
 @return 返回值
 */
/****
 Starts exporting.

 @param taskPath The path of the taskPath folder.
 @param outputPath The video output path.
 @return A return value.
 */
- (int)exportWithTaskPath:(NSString *)taskPath outputPath:(NSString *)outputPath;

/**
 暂停合成导出

 @return 返回值
 */
/****
 Pauses exporting.

 @return A return value.
 */
- (int)pauseExport;

/**
 继续合成导出

 @return 返回值
 */
/****
 Resumes exporting.

 @return A return value.
 */
- (int)resumeExport;

/**
 取消合成导出

 @return 返回值
 */
/****
 Cancels exporting.

 @return A return value.
 */
- (int)cancelExport;

#pragma mark - upload

/**
 上传封面

 @param imagePath 封面图片路径
 @param vodUploadAddress 点播上传地址
 @param vodUploadAuth 点播上传凭证
 @return 返回值
 */
/****
 Uploads a thumbnail.

 @param imagePath The path of the thumbnail image.
 @param vodUploadAddress The upload URL.
 @param vodUploadAuth The upload credential.
 @return A return value.
 */
- (int)uploadImageWithPath:(NSString *)imagePath
              uploadAddress:(NSString *)vodUploadAddress
                 uploadAuth:(NSString *)vodUploadAuth;

/**
 上传视频

 @param videoPath 视频路径
 @param vodUploadAddress 点播上传地址
 @param vodUploadAuth 点播上传凭证
 @return 返回值
 */
/****
 Uploads a video.

 @param videoPath The path of the video.
 @param vodUploadAddress The upload URL.
 @param vodUploadAuth The upload credential.
 @return A return value.
 */
- (int)uploadVideoWithPath:(NSString *)videoPath
              uploadAddress:(NSString *)vodUploadAddress
                 uploadAuth:(NSString *)vodUploadAuth;

/**
 暂停上传

 @return 返回值
 */
/****
 Pauses uploading.

 @return A return value.
 */
- (int)pauseUpload;

/**
 继续上传

 @return 返回值
 */
/****
 Resumes uploading.

 @return A return value.
 */
- (int)resumeUpload;

/**
 取消上传

 @return 返回值
 */
/****
 Cancels uploading.

 @return A return value.
 */
- (int)cancelUpload;

/**
 刷新上传凭证

 @param vodUploadAuth 新的上传凭证
 @return 返回值
 */
/****
 Updates the upload credential.

 @param vodUploadAuth The new upload credential.
 @return A return value.
 */
- (int)refreshWithUploadAuth:(NSString *)vodUploadAuth;

@end

NS_ASSUME_NONNULL_END
