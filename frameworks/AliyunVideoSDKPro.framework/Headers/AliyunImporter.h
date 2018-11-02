//
//  QUIImportor.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/14.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliyunVideoParam.h"
#import <Photos/PHAsset.h>
#import "AliyunIClipConstructor.h"

@interface AliyunImporter : NSObject <AliyunIClipConstructor>

/**
 初始化AliyunImporter

 @param taskPath taskPath文件夹地址，保证文件夹已存在
 @param outputSize 导出视频分辨率设置，必须为偶数
 @return AliyunImporter
 */
- (instancetype)initWithPath:(NSString *)taskPath outputSize:(CGSize)outputSize;

/**
 设置视频输出参数
 
 @param videoParam 视频输出参数
 */
- (void)setVideoParam:(AliyunVideoParam *)videoParam;

/**
 在taskPath目录下，生成配置文件

 */
- (void)generateProjectConfigure;

@end
