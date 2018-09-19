//
//  AliyunVideoSDKInfo.h
//  QUSDK
//
//  Created by Worthy on 2017/5/23.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
// BUILD INFO
// AliyunAlivcCommitId:b3d30d0dd
// AliyunMediaCoreCommitId:a788df2e
// AliyunVideoSDKCommitId:68990121
// AliyunVideoSDKBuildId:3456115

#import <Foundation/Foundation.h>

@interface AliyunVideoSDKInfo : NSObject

+ (NSString *)version;

+ (NSString *)alivcCommitId;

+ (NSString *)mediaCoreCommitId;

+ (NSString *)videoSDKCommitId;

+ (NSString *)videoSDKBuildId;

+ (void)printSDKInfo;
@end
