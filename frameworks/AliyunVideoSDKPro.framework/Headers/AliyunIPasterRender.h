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
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 * 解析动图失败 ALIVC_SVIDEO_EDITOR_PARSE_RESOURCE_FAILED
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)addGifPaster:(AliyunEffectPaster *)paster;


/**
 底层接口，添加纯文字

 @param subtitle 纯文字动图对象
 @param textImage 文字截图
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)addSubtitlePaster:(AliyunEffectSubtitle *)subtitle textImage:(UIImage *)textImage;

/**
 底层接口，添加字幕动图

 @param caption 字幕动图对象
 @param textImage 文字截图
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 * 解析动图失败 ALIVC_SVIDEO_EDITOR_PARSE_RESOURCE_FAILED
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)addCaptionPaster:(AliyunEffectCaption *)caption textImage:(UIImage *)textImage;

/**
 移除动图

 @param basePaster 动图对象
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)removePaster:(AliyunEffectPasterBase *)basePaster;

/**
 隐藏动图

 @param basePaster 动图对象
 */
- (int)hidePaster:(AliyunEffectPasterBase *)basePaster __deprecated_msg("will not use anymore");


/**
 显示普通动图

 @param paster 动图对象
 */
- (int)showGifPaster:(AliyunEffectPaster *)paster __deprecated_msg("will not use anymore");

/**
 显示纯文字动图

 @param subtitle 纯文字动图对象
 */
- (int)showSubtitlePaster:(AliyunEffectSubtitle *)subtitle __deprecated_msg("will not use anymore");

/**
 显示字幕动图

 @param caption 字幕动图对象
 */
- (int)showCaptionPaster:(AliyunEffectCaption *)caption __deprecated_msg("will not use anymore");

@end
