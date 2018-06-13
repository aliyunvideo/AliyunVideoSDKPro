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
- (int)setTailWaterMark:(UIImage *)image frame:(CGRect)frame duration:(CGFloat)duration __deprecated_msg("use setWaterMark:(AliyunEffectImage *)waterMark in AliyunEditor");

/**
 设置水印
 
 @param waterMark 水印
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 * 图片类型不支持 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED
 */
- (int)setWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置片尾水印
 
 @param waterMark 片尾水印
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
- (int)setTailWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置编码模式
 iOS强制硬编
 @param encodeMode 编码模式 0:软编 1:硬编
 */
- (void)setEncodeMode:(int)encodeMode;

/**
 设置视频输出参数
 
 @param videoParam 视频输出参数
 */
- (void)setVideoParam:(AliyunVideoParam *)videoParam;

/**
 开始导出视频
 
 @param outputPath 导出路径
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 参数不正确 ALIVC_COMMON_INVALID_PARAM
 * 组件初始化失败 ALIVC_SVIDEO_EDITOR_INIT_FAILED
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_CREATE_FAILED
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_RE_CREATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)startExport:(NSString *)outputPath;

/**
 取消导出视频
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
-(int)cancelExport;

@end
