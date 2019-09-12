//
//  AliyunVideoSDKInfo.h
//  QUSDK
//
//  Created by Worthy on 2017/5/23.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
// BUILD INFO
// AliyunAlivcCommitId:0eb5d17
// AliyunMediaCoreCommitId:3a28d16
// AliyunVideoSDKCommitId:38cfd89
// AliyunVideoSDKBuildId:11986171

#import <Foundation/Foundation.h>

/**
 专业版
 */
extern NSString *const kAliyunVideoSDKModulePro;

/**
 标准版
 */
extern NSString *const kAliyunVideoSDKModuleStandard;

/**
 基础版
 */
extern NSString *const kAliyunVideoSDKModuleBasic;


/**
 log等级

 - AlivcLogVerbose: Verbose
 - AlivcLogDebug: Debug
 - AlivcLogInfo: Info
 - AlivcLogWarn: Warn
 - AlivcLogError: Error
 - AlivcLogFatal: Fatal
 */
/****
 Log levels.

 - AlivcLogVerbose: Verbose
 - AlivcLogDebug: Debug
 - AlivcLogInfo: Info
 - AlivcLogWarn: Warn
 - AlivcLogError: Error
 - AlivcLogFatal: Fatal
 */
typedef NS_ENUM(NSInteger, AlivcLogLevel)
{
    AlivcLogVerbose = 2,
    AlivcLogDebug,
    AlivcLogInfo,
    AlivcLogWarn,
    AlivcLogError,
    AlivcLogFatal
};


/**
 debug日志等级

 - AlivcDebugLogClose: Close
 - AlivcDebugLogNormal: Normal
 - AlivcDebugLogAll: All
 */
typedef NS_ENUM(NSInteger, AlivcDebugLogLevel)
{
    AlivcDebugLogClose = 1,
    AlivcDebugLogNormal = 2,
    AlivcDebugLogAll = 3,
};

/**
 sdk基础信息与设置类
 */
/****
 A class that defines basic SDK settings.
 */
@interface AliyunVideoSDKInfo : NSObject

    /**
     获取版本号

     @return 版本号
     */
    /****
     Gets the SDK version.

     @return The SDK version.
     */
+ (NSString *)version;

/**
 获取module

 kAliyunModulePro
 kAliyunModuleStandard
 kAliyunModuleBasic
 @return module类型
 */
+ (NSString *)module;

/**
 获取版本号code

 @return 版本号code
 */
/****
 Gets the SDK version code.

 @return The SDK version code.
 */
+ (int)versionCode;


/**
 获取alivc commit id
 版本build相关，开发者无需关心
 @return alivc commit id
 */
/****
 Gets the alivc commit id.

 @return The alivc commit id.
 */
+ (NSString *)alivcCommitId;

/**
 获取mediacore commit id
 版本build相关，开发者无需关心
 @return mediacore commit id
 */
/****
 Gets the mediacore commit id.

 @return The mediacore commit id.
 */
+ (NSString *)mediaCoreCommitId;

/**
 获取video sdk commit id
 版本build相关，开发者无需关心
 @return video sdk commit id
 */
/****
 Gets the video SDK commit id.

 @return The video SDK commit id.
 */
+ (NSString *)videoSDKCommitId;

/**
 获取build id
 版本build相关，开发者无需关心
 @return build id
 */
/****
 Gets the build id.

 @return The build id.
 */
+ (NSString *)videoSDKBuildId;

/**
 打印版本信息
 */
/****
 Prints the SDK version.
 */
+ (void)printSDKInfo;

/**
 注册SDK
 目前无需调用
 */
/****
 Registers the SDK.
 */
+ (void)registerSDK;

/**
 设置日志等级

 @param level 日志等级
 默认值AlivcLogError，只有在报错时才有日志
 调试阶段可以设置为AlivcLogVerbose或AlivcLogDebug
 */
/****
 Sets the log level.

 @param level The log level.
 Default is AlivcLogError. Logs are generated when errors occur.
 It is recommended to set the log level to AlivcLogVerbose or AlivcLogDebug during debugging.
 */
+ (void)setLogLevel:(AlivcLogLevel)level;

/**
 设置debug日志等级
 
 @param level debug日志等级
 用于设置debug日志上传等级，默认值AlivcDebugLogNormal
 */
+ (void)setDebugLogLevel:(AlivcDebugLogLevel)level;

/**
 设置用户id
 设置业务层用户id，用于线上用户反馈问题的日志排查

 @param userId 用户id
 */
/****
 Sets the user id.
 The user id is used for troubleshooting issues reported by users.

 @param userId The user id.
 */
+ (void)setUserId:(NSString *)userId;

/**
 获取用户id

 @return 用户id
 */
/****
 Gets the user id.

 @return The user id.
 */
+ (NSString *)userId;

/**
 设备信息上传

 @param conanUpload 是否上传
 */
/****
 Sets whether to upload device information.

 @param conanUpload Whether to upload device information.
 */
+ (void)setDeviceInfoUpload:(BOOL)conanUpload;

/**
 获取设备信息上传

 @return 结果
 */
/****
 Gets whether to upload device information.

 @return Whether to upload device information.
 */
+ (BOOL)deviceInfoUpload;

@end
