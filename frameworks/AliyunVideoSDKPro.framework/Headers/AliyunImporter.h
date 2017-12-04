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

@interface AliyunImporter : NSObject

- (instancetype)initWithPath:(NSString *)taskPath outputSize:(CGSize)outputSize;

/**
 设置视频输出参数
 
 @param videoParam 视频输出参数
 */
- (void)setVideoParam:(AliyunVideoParam *)videoParam;

/**
 添加视频路径
 
 @param videoPath 视频路径
 @param animDuration 转场动画时长,单位秒
 
 duartion为当前视频片段和上段视频片段间的转场时长，不能小于视频本身时长
 添加的第一段视频没有转场，duartion需要设为0
 */
- (void)addVideoWithPath:(NSString *)videoPath animDuration:(CGFloat)animDuration;



- (void)addVideoWithPath:(NSString *)videoPath startTime:(CGFloat)startTime duration:(CGFloat)duration animDuration:(CGFloat)animDuration;
/**
 增加图片

 @param image 照片
 @param duration 播放时间
 @param animDuration 动画过渡时间
 
 @return 图片路径
 */
- (NSString *)addImage:(UIImage *)image duration:(CGFloat)duration animDuration:(CGFloat)animDuration;

/**
 在taskPath目录下，生成配置文件

 */
- (void)generateProjectConfigure;

@end
