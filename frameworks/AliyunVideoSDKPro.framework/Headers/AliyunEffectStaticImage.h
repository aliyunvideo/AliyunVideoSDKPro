//
//  AliyunEffectStaticImage.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2017/10/13.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//  静态图片类
//  设置startTime（静态图片开始出现的时间）
//  endTime（静态图片消失的时间）
//  path（静态图片的资源文件路径）

#import "AliyunEffectPasterBase.h"
#import <UIKit/UIKit.h>

/**
 静态图片model类
 */
@interface AliyunEffectStaticImage : AliyunEffectPasterBase

/**
 内部调用方法

 @param dict dict
 @return AliyunEffectImage
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("已废弃");

@end
