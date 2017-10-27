//
//  AliyunIExporter.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/24.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunVideoParam.h"

@protocol AliyunIExporter <NSObject>
/**
 添加片尾水印
 
 @param image 水印图片
 */
- (void)setTailWaterMark:(UIImage *)image frame:(CGRect)frame duration:(CGFloat)duration;

/**
 开始导出视频
 
 @param outputPath 导出路径
 */
- (int)startExport:(NSString *)outputPath;

/**
 取消导出视频
 */
-(void)cancelExport;

@end
