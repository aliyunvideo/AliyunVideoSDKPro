//
//  AliyunIPlayerCallback.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/15.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 播放器回调协议
 */
/****
 The protocol of player callbacks.
 */
@protocol AliyunIPlayerCallback <NSObject>

/**
 播放结束
 */
/****
 The callback when playback ends.
 */
- (void)playerDidEnd;

/**
 播放进度

 @param playSec 播放时间
 @param streamSec 播放流时间
 */
/****
 The callback that outputs the playback progress.

 @param playSec The position on the playback timeline.
 @param streamSec The position on the video stream.
 */
- (void)playProgress:(double)playSec streamProgress:(double)streamSec;

/**
 播放异常

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
 ALIVC_FRAMEWORK_MEDIA_POOL_WRONG_STATE indicates that the player's state is incorrect.
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
- (void)playError:(int)errorCode;

#pragma mark - It is not recommended to use the following methods.

/**
 seek结束
 */
/****
 The callback when the execution of seek completes.
 */
- (void)seekDidEnd __deprecated_msg("deprecated");

/**
 开始播放
 已废弃
 */
/****
 The callback when playback is started.
 Deprecated.
 */
- (void)playerDidStart __deprecated_msg("deprecated");

@optional

/**
 播放进度

 @param sec 单位：s
 */
/****
 The callback that outputs the playback progress.
 
 @param sec Unit: seconds.
 */
- (void)playProgress:(double)sec;

@end

/**
 渲染回调协议
 */
/****
 The protocol of render callbacks.
 */
@protocol AliyunIRenderCallback <NSObject>

@optional

/**
 自定义渲染接口,渲染前纹理回调

 @param srcTexture 原始视频帧纹理id
 @param size 原始视频帧纹理size
 @return 返回纹理id
 */
/****
 The callback that outputs the texture id before adding custom effects to the video.
 
 @param srcTexture The old texture id.
 @param size The old texture size.
 @return The texture id.
 */
- (int)customRender:(int)srcTexture size:(CGSize)size;

/**
 自定义渲染接口，渲染后纹理回调

 @param srcTexture 原始视频帧纹理id
 @param size 原始视频帧纹理size
 @return 返回纹理id
 */
/****
 The callback that outputs the texture id after adding custom effects to the video.
 
 @param srcTexture The old texture id.
 @param size The old texture size.
 @return The texture id.
 */
- (int)textureRender:(int)srcTexture size:(CGSize)size;

@end
