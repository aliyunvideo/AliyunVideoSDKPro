//
//  AliyunEffectStaticImage.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2017/10/13.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.

#import "AliyunEffectPasterBase.h"
#import <UIKit/UIKit.h>

/**
 静态图片model类
 */
/****
 A model class that creates images.
 */
@interface AliyunEffectStaticImage : AliyunEffectPasterBase

/**
 内部调用方法

 @param dict dict
 @return AliyunEffectImage
 */
/****
 Internal method.

 @param dict The initialization parameter.
 @return AliyunEffectImage
 */
- (id)initWithRestore:(NSDictionary *)dict __deprecated_msg("deprecated");

@end
