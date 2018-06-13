//
//  AliyunIPlayerCallback.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/15.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AliyunIPlayerCallback <NSObject>

/**
 开始播放
 */
- (void)playerDidStart;

/**
 播放结束
 */
- (void)playerDidEnd;


/**
 seek结束
 */
- (void)seekDidEnd;

/**
 播放进度

 @param playSec 播放时间
 @param streamSec 播放流时间
 */
- (void)playProgress:(double)playSec streamProgress:(double)streamSec;
/**
 播放异常

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
- (void)playError:(int)errorCode;

@optional
/**
 播放进度
 
 @param sec 单位：s
 */
- (void)playProgress:(double)sec;


@end

@protocol AliyunIRenderCallback <NSObject>

@optional

/**
 自定义渲染接口
 
 @param srcTexture 原始视频帧纹理id
 @param size 原始视频帧纹理size
 @return 返回纹理id
 */
- (int)customRender:(int)srcTexture size:(CGSize)size;

@end
