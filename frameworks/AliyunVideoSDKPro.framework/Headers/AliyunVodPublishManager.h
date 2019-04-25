//
//  AliyunVodPublishManager.h
//  AliyunVideoSDKPro
//
//  Created by Worthy Zhang on 2018/12/28.
//  Copyright © 2018 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunEditor.h"

NS_ASSUME_NONNULL_BEGIN
@class AliyunVodPublishManager;
@protocol AliyunIVodUploadCallback <NSObject>

- (void)publishManagerUploadSuccess:(AliyunVodPublishManager *)manager;

- (void)publishManager:(AliyunVodPublishManager *)manager uploadFailedWithCode:(NSString *)code message:(NSString *)message;

- (void)publishManager:(AliyunVodPublishManager *)manager uploadProgressWithUploadedSize:(long long)uploadedSize totalSize:(long long)totalSize;

- (void)publishManagerUploadTokenExpired:(AliyunVodPublishManager *)manager;

- (void)publishManagerUploadRetry:(AliyunVodPublishManager *)manager;

- (void)publishManagerUploadRetryResume:(AliyunVodPublishManager *)manager;

@end

typedef NS_OPTIONS(NSInteger, AliyunVodUploadState) {
    AliyunVodUploadImage,
    AliyunVodUploadVideo,
};


@interface AliyunVodPublishManager : NSObject

@property (nonatomic, weak) id<AliyunIExporterCallback> exportCallback;

@property (nonatomic, weak) id<AliyunIVodUploadCallback> uploadCallback;

@property (nonatomic, assign) AliyunVodUploadState uploadState;

@property (nonatomic, copy) NSString *videotPath;

@property (nonatomic, copy) NSString *imagePath;

#pragma mark - export

/**
 合成导出视频

 @param taskPath taskPath
 @param outputPath 导出视频路径
 @return 返回值
 */
- (int)exportWithTaskPath:(NSString *)taskPath outputPath:(NSString *)outputPath;

- (int)pauseExport;

- (int)resumeExport;

- (int)cancelExport;

#pragma mark - upload

/**
 上传封面

 @param imagePath 封面图片路径
 @param vodUploadAddress 点播上传地址
 @param vodUploadAuth 点播上传凭证
 @return 返回值
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
- (int)uploadVideoWithPath:(NSString *)videoPath
              uploadAddress:(NSString *)vodUploadAddress
                 uploadAuth:(NSString *)vodUploadAuth;

- (int)pauseUpload;

- (int)resumeUpload;

- (int)cancelUpload;

- (int)refreshWithUploadAuth:(NSString *)vodUploadAuth;

@end

NS_ASSUME_NONNULL_END
