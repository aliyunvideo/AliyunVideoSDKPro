//
//  AliyunIExporterCallback.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/16.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AliyunIExporterCallback <NSObject>

/**
 开始导出
 */
- (void)exporterDidStart;

/**
 导出结束
 */
- (void)exporterDidEnd;


/**
 导出取消
 */
- (void)exporterDidCancel;

/**
 导出进度
 
 @param progress 0-1
 */
- (void)exportProgress:(float)progress;


/**
 导出异常
 
 @param errorCode 错误码
 */
- (void)exportError:(int)errorCode;

@end
