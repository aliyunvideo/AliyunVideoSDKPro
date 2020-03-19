//
//  AliyunIPlayer.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/10.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 播放器协议
 */
@protocol AliyunIPlayer <NSObject>

/**
 开始播放
 
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 参数不正确 ALIVC_COMMON_INVALID_PARAM
 初始化异常返回 ALIVC_FRAMEWORK_AUDIO_RENDER_INIT_SPEAKER_FAILED
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_RENDER_ERROR_EDITORLAYOUT_INVALID_SIZE
 ALIVC_FRAMEWORK_VIDEO_ENCODER_ERROR_STATE
 */
- (int)play;

/**
 seek到某一时间点

 @param time 时间，单位：秒
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 ALIVC_FRAMEWORK_AUDIO_PROCESS_SEEK_FAILED
 */
- (int)seek:(float)time;

/**
 绘制一帧

 @param time time 时间，单位：秒
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS 
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
-(int)draw:(float)time;

/**
 暂停播放
 
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)pause;

/**
 继续播放

 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)resume;

/**
 是否正在播放

 @return 正在播放
 */
- (BOOL)isPlaying;

/**
 重新开始播放

 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 参数不正确 ALIVC_COMMON_INVALID_PARAM
 初始化异常返回 ALIVC_FRAMEWORK_AUDIO_RENDER_INIT_SPEAKER_FAILED
 状态错误 ALIVC_FRAMEWORK_VIDEO_ENCODER_ERROR_STATE
 ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 ALIVC_FRAMEWORK_RENDER_ERROR_EDITORLAYOUT_INVALID_SIZE

 */
- (int)replay;

/**
 停止播放
 
 @return
 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)stop;

/**
 获取总时长

 单位：秒
 @return 总时长
 */
- (double)getDuration;

/**
 获取当前播放时间

 单位：秒
 */
- (double)getCurrentTime;

/**
 获取原始视频流时长

 单位：秒
 @return 总时长
 */
- (double)getStreamDuration;

/**
 获取原始视频流播放时间

 单位：秒
 */
- (double)getCurrentStreamTime;

/**
 获取视频片段在播放时间轴上开始播放的时间

 @param idx 视频片段序列号
 @return 时间，单位：秒
 */
- (double)getClipStartTimeAtIndex:(int)idx;

/**
 设置播放器的刷新频率

 默认30帧/s 最大60帧/s 建议不低于20帧/s
 @param fps 帧
 */
- (void)setRefreshFps:(double)fps;

#pragma mark - It is not recommended to use the following method.

/**
 设置播放器激活状态

 @param active

 */
- (void)setActive:(BOOL)active __deprecated_msg("deprecated");

@end
