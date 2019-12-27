//
//  AliyunVideoSDKInfo.h
//  QUSDK
//
//  Created by Worthy on 2017/5/23.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
// BUILD INFO
// AliyunAlivcCommitId:f39bc3b
// AliyunMediaCoreCommitId:9adad7f
// AliyunVideoSDKCommitId:469f907
// AliyunVideoSDKBuildId:12452510

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
@interface AliyunVideoSDKInfo : NSObject

    /**
     获取版本号

     @return 版本号
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
+ (int)versionCode;


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
 获取video sdk commit id
 版本build相关，开发者无需关心
 @return video sdk commit id
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
 目前无需调用
 */
+ (void)registerSDK;

/**
 设置日志等级

 @param level 日志等级
 默认值AlivcLogError，只有在报错时才有日志
 调试阶段可以设置为AlivcLogVerbose或AlivcLogDebug
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
+ (void)setUserId:(NSString *)userId;

/**
 获取用户id

 @return 用户id
 */
+ (NSString *)userId;

/**
 设备信息上传

 @param conanUpload 是否上传
 */
+ (void)setDeviceInfoUpload:(BOOL)conanUpload;

/**
 获取设备信息上传

 @return 结果
 */
+ (BOOL)deviceInfoUpload;

@end
