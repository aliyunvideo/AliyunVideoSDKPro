//
//  AliyunIExporterCallback.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/16.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AliyunIExporterCallback <NSObject>

/**
 开始导出
 */
- (void)exporterDidStart;

/**
 导出结束
 @param outputPath 输出文件路径
 */
- (void)exporterDidEnd:(NSString *)outputPath;

/**
 导出取消
 */
- (void)exporterDidCancel;

/**
 导出进度
 
 @param progress 0-1
 */
- (void)exportProgress:(float)progress;


/**
 导出异常
 
 @param errorCode 错误码
 *状态错误 ALIVC_FRAMEWORK_MEDIA_POOL_WRONG_STATE
 *DEMUXER重复创建 ALIVC_FRAMEWORK_DEMUXER_INIT_MULTI_TIMES
 *DEMUXER打开失败 ALIVC_FRAMEWORK_DEMUXER_OPEN_FILE_FAILED
 *DEMUXER获取流信息失败 ALIVC_FRAMEWORK_DEMUXER_FIND_STREAM_INFO_FAILED
 *解码器创建失败 ALIVC_FRAMEWORK_AUDIO_DECODER_CREATE_DECODER_FAILED
 *解码器状态错误 ALIVC_FRAMEWORK_AUDIO_DECODER_ERROR_STATE
 *解码器输入错误 ALIVC_FRAMEWORK_AUDIO_DECODER_ERROR_INPUT
 *解码器参数SPSPPS为空 ALIVC_FRAMEWORK_VIDEO_DECODER_SPS_PPS_NULL,
 *解码H264参数创建失败 ALIVC_FRAMEWORK_VIDEO_DECODER_CREATE_H264_PARAM_SET_FAILED
 *解码HEVC参数创建失败 ALIVC_FRAMEWORK_VIDEO_DECODER_CREATE_HEVC_PARAM_SET_FAILED
 *缓存数据已满 ALIVC_FRAMEWORK_MEDIA_POOL_CACHE_DATA_SIZE_OVERFLOW
 *解码器内部返回错误码
 
 */
- (void)exportError:(int)errorCode;


@optional
/**
 导出结束 建议使用exporterDidEnd:(NSString *)outputPath方法
 */
- (void)exporterDidEnd __deprecated_msg("use -(void)exporterDidEnd:(NSString *)outputPath");

@end
