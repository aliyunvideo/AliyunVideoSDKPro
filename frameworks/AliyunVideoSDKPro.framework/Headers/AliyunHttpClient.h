//
//  AliyunHttpClient.h
//  qurecorder
//
//  Created by Vienta on 2017/1/13.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//  该接口已废弃不再维护，请自行封装HTTP请求接口或使用第三方库

#import <Foundation/Foundation.h>
__attribute__ ((deprecated("该接口已废弃不再维护，请自行封装HTTP请求接口或使用第三方库")))
@interface AliyunHttpClient : NSObject


- (id)initWithBaseUrl:(NSString *)urlString __deprecated_msg("已废弃不再维护");

- (void)GET:(NSString *)path
 parameters:(NSDictionary *)parameters
completionHandler:(void (^)(NSURLResponse *response, id responseObject,  NSError * error))completionHandler __deprecated_msg("已废弃不再维护");

- (void)download:(NSString *)remotePath
     destination:(NSString *)destination
        progress:(void (^)(NSProgress*downloadProgress))downloadProgressBlock
completionHandler:(void(^)(NSURL *filePath, NSError *error))completionHandler __deprecated_msg("已废弃不再维护");


@end
