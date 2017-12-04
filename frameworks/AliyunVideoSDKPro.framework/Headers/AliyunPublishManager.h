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

- (void)uploadSuccessWithVid:(NSString *)vid imageUrl:(NSString *)imageUrl;

- (void)uploadFailedWithCode:(NSString *)code message:(NSString *)message;

- (void)uploadProgressWithUploadedSize:(long long)uploadedSize totalSize:(long long)totalSize;

- (void)uploadTokenExpired;

- (void)uploadRetry;

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


- (void)setTailWaterMark:(UIImage *)image frame:(CGRect)frame duration:(CGFloat)duration;

- (BOOL)exportWithTaskPath:(NSString *)taskPath outputPath:(NSString *)outputPath;

- (void)cancelExport;


- (BOOL)uploadWithImagePath:(NSString *)imagePath
                 svideoInfo:(AliyunUploadSVideoInfo *)svideoInfo
                accessKeyId:(NSString *)accessKeyId
            accessKeySecret:(NSString *)accessKeySecret
                accessToken:(NSString *)accessToken;

- (void)refreshWithAccessKeyId:(NSString *)accessKeyId
               accessKeySecret:(NSString *)accessKeySecret
                   accessToken:(NSString *)accessToken
                    expireTime:(NSString *)expireTime;

- (void)cancelUpload;

@end
