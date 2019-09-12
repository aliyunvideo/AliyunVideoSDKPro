//
//  AliyunHttpClient.h
//  qurecorder
//
//  Created by Vienta on 2017/1/13.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.

#import <Foundation/Foundation.h>

/**
 http请求封装类
 已废弃
 @return AliyunHttpClient
 */
/****
 A class that defines HTTP requests.
 Deprecated.
 @return AliyunHttpClient
 */
__attribute__ ((deprecated("deprecated")))
@interface AliyunHttpClient : NSObject

/**
 初始化

 @param urlString 请求url
 @return AliyunHttpClient
 */
/****
 Initializer.

 @param urlString The request URL.
 @return AliyunHttpClient
 */
- (id)initWithBaseUrl:(NSString *)urlString __deprecated_msg("deprecated");

/**
 get请求

 @param path 请求路径
 @param parameters 参数
 @param completionHandler 完成回调
 */
/****
 Creates a GET request.

 @param path The request path.
 @param parameters The request parameters.
 @param completionHandler The callback.
 */
- (void)GET:(NSString *)path
 parameters:(NSDictionary *)parameters
completionHandler:(void (^)(NSURLResponse *response, id responseObject,  NSError * error))completionHandler __deprecated_msg("deprecated");

/**
 下载请求

 @param remotePath 请求路径
 @param destination 本地保存路径
 @param downloadProgressBlock 参数
 @param completionHandler 完成回调
 */
/****
 Downloads a request.

 @param remotePath The request path.
 @param destination The local storage path.
 @param downloadProgressBlock The download progress parameter.
 @param completionHandler The callback.
 */
- (void)download:(NSString *)remotePath
     destination:(NSString *)destination
        progress:(void (^)(NSProgress*downloadProgress))downloadProgressBlock
completionHandler:(void(^)(NSURL *filePath, NSError *error))completionHandler __deprecated_msg("deprecated");

@end
