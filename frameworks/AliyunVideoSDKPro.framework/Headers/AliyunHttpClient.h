//
//  AliyunHttpClient.h
//  qurecorder
//
//  Created by Vienta on 2017/1/13.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AliyunHttpClient : NSObject


- (id)initWithBaseUrl:(NSString *)urlString;

- (void)GET:(NSString *)path
 parameters:(NSDictionary *)parameters
completionHandler:(void (^)(NSURLResponse *response, id responseObject,  NSError * error))completionHandler;

- (void)download:(NSString *)remotePath
     destination:(NSString *)destination
        progress:(void (^)(NSProgress*downloadProgress))downloadProgressBlock
completionHandler:(void(^)(NSURL *filePath, NSError *error))completionHandler;


@end
