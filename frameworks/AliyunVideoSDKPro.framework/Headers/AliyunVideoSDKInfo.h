//
//  AliyunVideoSDKInfo.h
//  QUSDK
//
//  Created by Worthy on 2017/5/23.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
// BUILD INFO
// AliyunAlivcCommitId:61c74b281
// AliyunMediaCoreCommitId:3ef3e847
// AliyunVideoSDKCommitId:f7f4fd71
// AliyunVideoSDKBuildId:3453961

#import <Foundation/Foundation.h>

@interface AliyunVideoSDKInfo : NSObject

+ (NSString *)version;

+ (NSString *)alivcCommitId;

+ (NSString *)mediaCoreCommitId;

+ (NSString *)videoSDKCommitId;

+ (NSString *)videoSDKBuildId;

+ (void)printSDKInfo;
@end
