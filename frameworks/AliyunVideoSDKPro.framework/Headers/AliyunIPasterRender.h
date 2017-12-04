//
//  AliyunIPasterRender.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/10.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliyunEffectPaster.h"
#import "AliyunEffectCaption.h"
#import "AliyunEffectSubtitle.h"

@protocol AliyunIPasterRender <NSObject>

/**
 底层接口，添加动图渲染

 @param paster 动图对象
 
 */
- (int)addGifPaster:(AliyunEffectPaster *)paster;


/**
 底层接口，添加纯文字

 @param subtitle 纯文字动图对象
 @param textImage 文字截图
 */
- (int)addSubtitlePaster:(AliyunEffectSubtitle *)subtitle textImage:(UIImage *)textImage;

/**
 底层接口，添加字幕动图

 @param caption 字幕动图对象
 @param textImage 文字截图
 */
- (int)addCaptionPaster:(AliyunEffectCaption *)caption textImage:(UIImage *)textImage;

/**
 移除动图

 @param basePaster 动图对象
 */
- (void)removePaster:(AliyunEffectPasterBase *)basePaster;

/**
 隐藏动图

 @param basePaster 动图对象
 */
- (void)hidePaster:(AliyunEffectPasterBase *)basePaster;


/**
 显示普通动图

 @param paster 动图对象
 */
- (void)showGifPaster:(AliyunEffectPaster *)paster;

/**
 显示纯文字动图

 @param subtitle 纯文字动图对象
 */
- (void)showSubtitlePaster:(AliyunEffectSubtitle *)subtitle;

/**
 显示字幕动图

 @param caption 字幕动图对象
 */
- (void)showCaptionPaster:(AliyunEffectCaption *)caption;

@end
