//
//  AliyunIPasterRender.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/10.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunEffectCaption.h"
#import "AliyunEffectPaster.h"
#import "AliyunEffectSubtitle.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 动图渲染协议
 */
@protocol AliyunIPasterRender <NSObject>

/**
 添加动图渲染

 @param paster 动图对象
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 解析动图失败 ALIVC_SVIDEO_EDITOR_PARSE_RESOURCE_FAILED
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)addGifPaster:(AliyunEffectPaster *)paster;

/**
 添加纯文字

 @param subtitle 纯文字动图对象
 @param textImage 文字截图
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)addSubtitlePaster:(AliyunEffectSubtitle *)subtitle textImage:(UIImage *)textImage;

/**
 添加字幕动图

 @param caption 字幕动图对象
 @param textImage 文字截图
 @return
 状态不正确 ALIVC_COMMON_INVALID_STATE
 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 解析动图失败 ALIVC_SVIDEO_EDITOR_PARSE_RESOURCE_FAILED
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)addCaptionPaster:(AliyunEffectCaption *)caption textImage:(UIImage *)textImage;

/**
 移除动图

 @param basePaster 动图对象
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)removePaster:(AliyunEffectPasterBase *)basePaster;

@end
