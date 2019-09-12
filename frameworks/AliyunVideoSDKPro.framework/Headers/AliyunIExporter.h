//
//  AliyunIExporter.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/24.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunVideoParam.h"
#import <Foundation/Foundation.h>

@protocol AliyunIExporter <NSObject>
/**
 添加片尾水印

 @param image 水印图片
 @return 返回值为片尾id或者错误码 详细：如果返回值范围为 >0  && < ALIVC_FRAMEWORK_ERROR_START， 则为片尾水印id；否则为错误码。
 */
/****
 Adds a watermark to the end of the video.
 
 @param image The watermark image.
 @return The watermark id or an error code.
 */
- (int)setTailWaterMark:(UIImage *)image frame:(CGRect)frame duration:(CGFloat)duration __deprecated_msg("use setWaterMark:(AliyunEffectImage *)waterMark in AliyunEditor");

/**
 设置水印

 @param waterMark 水印
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 图片类型不支持 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED
 */
/****
 Sets a watermark.
 
 @param waterMark The watermark image.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the exporter's state is incorrect.
 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST if the image file does not exist.
 ALIVC_SVIDEO_EDITOR_VIEW_TYPE_NOT_SUPPORTED if the image type is not supported.
 */
- (int)setWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置片尾水印

 @param waterMark 片尾水印
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 文件不存在 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
/****
 Sets a watermark to the end of the video.
 
 @param waterMark The watermark image.
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the exporter's state is incorrect.
 ALIVC_SVIDEO_EDITOR_FILE_NOT_EXIST if the image file does not exist.
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_RENDER_ERROR_INVALID_OPTION
 */
- (int)setTailWaterMark:(AliyunEffectImage *)waterMark;

/**
 设置编码模式

 iOS强制硬编
 @param encodeMode 编码模式 参见AliyunVideoParam中codecType的定义
 */
/****
 Sets the encoding mode.
 
 Hardware encoding is required in iOS.
 @param encodeMode The encoding mode. See the codecType in AliyunVideoParam.
 */
- (void)setEncodeMode:(AliyunVideoCodecType)encodeMode;

/**
 设置视频输出参数

 @param videoParam 视频输出参数
 */
/****
 Sets the video output parameter.
 
 @param videoParam The output parameter.
 */
- (void)setVideoParam:(AliyunVideoParam *)videoParam;

/**
 设置退后台是否取消导出合成

 默认值NO:退后台暂停合成，回到前台继续合成,YES:退后台取消合成
 @param flag flag
 */
/****
 Sets whether to cancel exporting when the app is set to run in the background.
 
 YES indicates cancel exporting. No indicates pause exporting. Default is NO.
 @param flag
 */
- (void)setCancelExportInResignActive:(BOOL)flag;

/**
 开始导出视频

 @param outputPath 导出视频文件路径，需要保证多级目录文件夹已经创建
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 参数不正确 ALIVC_COMMON_INVALID_PARAM
 组件初始化失败 ALIVC_SVIDEO_EDITOR_INIT_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_CREATE_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_RE_CREATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
/****
 Starts exporting.
 
 @param outputPath The video output path. 
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the exporter's state is incorrect.
 ALIVC_COMMON_INVALID_PARAM if the parameter setting is incorrect.
 ALIVC_SVIDEO_EDITOR_INIT_FAILED if an error occurred during component initialization.
 ALIVC_FRAMEWORK_AUDIO_PROCESS_CREATE_FAILED
 ALIVC_FRAMEWORK_AUDIO_PROCESS_RE_CREATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 */
- (int)startExport:(NSString *)outputPath;

/**
 暂停导出视频

 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
/****
 Pauses exporting.
 
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the exporter's state is incorrect.
 */
- (int)pauseExport;

/**
 继续导出视频

 @return 
>>>>>>> release/svideo_v3.10.0
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
/****
 Resumes exporting.
 
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the exporter's state is incorrect.
 */
- (int)resumeExport;

/**
 取消导出视频
 
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
/****
 Cancels exporting.
 
 @return
 ALIVC_COMMON_RETURN_SUCCESS if the invocation is successful.
 ALIVC_COMMON_INVALID_STATE if the exporter's state is incorrect.
 */
-(int)cancelExport;

@end
