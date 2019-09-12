//
//  AliyunEffectImage.h
//  qurecorder
//
//  Created by Vienta on 2017/1/7.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffectPasterBase.h"
#import <CoreGraphics/CoreGraphics.h>

/**
 图片效果model类
 */
/****
 A model class that defines images. 
 */
@interface AliyunEffectImage : AliyunEffectPasterBase

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
