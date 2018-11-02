//
//  AliyunVideoSDKInfo.h
//  QUSDK
//
//  Created by Worthy on 2017/5/23.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
// BUILD INFO
// AliyunAlivcCommitId:aa7d517e3
// AliyunMediaCoreCommitId:40c7dc02
// AliyunVideoSDKCommitId:578bebdd
// AliyunVideoSDKBuildId:3459463

#import <Foundation/Foundation.h>

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

@end
