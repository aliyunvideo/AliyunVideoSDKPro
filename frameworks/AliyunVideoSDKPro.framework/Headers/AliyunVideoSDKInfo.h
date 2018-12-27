//
//  AliyunVideoSDKInfo.h
//  QUSDK
//
//  Created by Worthy on 2017/5/23.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
// BUILD INFO
// AliyunAlivcCommitId:c1cd3f40b
// AliyunMediaCoreCommitId:bd6b7473
// AliyunVideoSDKCommitId:1b5a823b
// AliyunVideoSDKBuildId:10788273

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AlivcLogLevel) {
    AlivcLogVerbose = 2,
    AlivcLogDebug,
    AlivcLogInfo,
    AlivcLogWarn,
    AlivcLogError,
    AlivcLogFatal
};

@interface AliyunVideoSDKInfo : NSObject

/**
 获取版本号

 @return 版本号
 */
+ (NSString *)version;

/**
 获取alivc commit id
 版本build相关，开发者无需关心
 @return alivc commit id
 */
+ (NSString *)alivcCommitId;

/**
 获取mediacore commit id
 版本build相关，开发者无需关心
 @return mediacore commit id
 */
+ (NSString *)mediaCoreCommitId;

/**
 获取video sdk commid id
 版本build相关，开发者无需关心
 @return video sdk commid id
 */
+ (NSString *)videoSDKCommitId;

/**
 获取build id
 版本build相关，开发者无需关心
 @return build id
 */
+ (NSString *)videoSDKBuildId;

/**
 打印版本信息
 */
+ (void)printSDKInfo;

/**
 注册SDK
 */
+(void)registerSDK;

/**
 设置日志等级

 @param level 日志等级
 默认值AlivcLogError，只有在报错时才有日志
 调试阶段可以设置为AlivcLogVerbose或AlivcLogDebug
 */
+ (void)setLogLevel:(AlivcLogLevel)level;


@end
