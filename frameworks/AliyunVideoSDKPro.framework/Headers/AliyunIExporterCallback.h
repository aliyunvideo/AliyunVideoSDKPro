//
//  AliyunIExporterCallback.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/16.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 编辑合成导出回调协议
 */
/****
 The protocol of export callbacks.
 */
@protocol AliyunIExporterCallback <NSObject>

/**
 导出结束

 @param outputPath 输出文件路径
 */
/****
 The callback when the exporting is complete.
 
 @param outputPath The output path.
 */
- (void)exporterDidEnd:(NSString *)outputPath;

/**
 导出取消
 */
/****
 The callback when the exporting is canceled.
 */
- (void)exporterDidCancel;

/**
 导出进度

 @param progress 0-1
 */
/****
 The callback that outputs the exporting progress.
 
 @param progress Valid values:[0, 1]
 */
- (void)exportProgress:(float)progress;

/**
 导出异常

 @param errorCode 错误码
 状态错误 ALIVC_FRAMEWORK_MEDIA_POOL_WRONG_STATE
 DEMUXER重复创建 ALIVC_FRAMEWORK_DEMUXER_INIT_MULTI_TIMES
 DEMUXER打开失败 ALIVC_FRAMEWORK_DEMUXER_OPEN_FILE_FAILED
 DEMUXER获取流信息失败 ALIVC_FRAMEWORK_DEMUXER_FIND_STREAM_INFO_FAILED
 解码器创建失败 ALIVC_FRAMEWORK_AUDIO_DECODER_CREATE_DECODER_FAILED
 解码器状态错误 ALIVC_FRAMEWORK_AUDIO_DECODER_ERROR_STATE
 解码器输入错误 ALIVC_FRAMEWORK_AUDIO_DECODER_ERROR_INPUT
 解码器参数SPSPPS为空 ALIVC_FRAMEWORK_VIDEO_DECODER_SPS_PPS_NULL,
 解码H264参数创建失败 ALIVC_FRAMEWORK_VIDEO_DECODER_CREATE_H264_PARAM_SET_FAILED
 解码HEVC参数创建失败 ALIVC_FRAMEWORK_VIDEO_DECODER_CREATE_HEVC_PARAM_SET_FAILED
 缓存数据已满 ALIVC_FRAMEWORK_MEDIA_POOL_CACHE_DATA_SIZE_OVERFLOW
 解码器内部返回错误码
 */
/****
 The callback when an error occurs.
 
 @param errorCode The error code.
 ALIVC_FRAMEWORK_MEDIA_POOL_WRONG_STATE indicates that the exporter's state is incorrect.
 ALIVC_FRAMEWORK_DEMUXER_INIT_MULTI_TIMES indicates that DEMUXER is initialized multiple times.
 ALIVC_FRAMEWORK_DEMUXER_OPEN_FILE_FAILED indicates that an error occurred while starting DEMUXER.
 ALIVC_FRAMEWORK_DEMUXER_FIND_STREAM_INFO_FAILED indicates that DEMUXER failed to obtain stream information.
 ALIVC_FRAMEWORK_AUDIO_DECODER_CREATE_DECODER_FAILED indicates that an error occurred while creating the decoder.
 ALIVC_FRAMEWORK_AUDIO_DECODER_ERROR_STATE indicates that the decoder state is incorrect.
 ALIVC_FRAMEWORK_AUDIO_DECODER_ERROR_INPUT indicates that the decoder input is incorrect.
 ALIVC_FRAMEWORK_VIDEO_DECODER_SPS_PPS_NULL indicates that the SPSPPS parameter of the decoder is null.
 ALIVC_FRAMEWORK_VIDEO_DECODER_CREATE_H264_PARAM_SET_FAILED indicates that an error occurred while creating H264 decoding parameters.
 ALIVC_FRAMEWORK_VIDEO_DECODER_CREATE_HEVC_PARAM_SET_FAILED indicates that an error occurred while creating HEVC decoding parameters.
 ALIVC_FRAMEWORK_MEDIA_POOL_CACHE_DATA_SIZE_OVERFLOW indicates that the cache memory is full.
 */
- (void)exportError:(int)errorCode;

#pragma mark - It is not recommended to use the following methods.

/**
 开始导出
 */
/****
 The callback when the exporting is started.
 */
- (void)exporterDidStart __deprecated_msg("deprecated");

@optional
/**
 导出结束 建议使用exporterDidEnd:(NSString *)outputPath方法
 */
/****
 The callback when the exporting is complete. It is recommended to use exporterDidEnd:(NSString *)outputPath instead.
 */
- (void)exporterDidEnd __deprecated_msg("use -(void)exporterDidEnd:(NSString *)outputPath");

@end
