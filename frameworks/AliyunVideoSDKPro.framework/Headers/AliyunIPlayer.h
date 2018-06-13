//
//  AliyunIPlayer.h
//  AliyunVideo
//
//  Created by Worthy on 2017/3/10.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AliyunIPlayer <NSObject>


/**
 开始播放
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 参数不正确 ALIVC_COMMON_INVALID_PARAM
 * 初始化异常返回 ALIVC_FRAMEWORK_AUDIO_RENDER_INIT_SPEAKER_FAILED
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_RENDER_ERROR_EDITORLAYOUT_INVALID_SIZE
 * ALIVC_FRAMEWORK_VIDEO_ENCODER_ERROR_STATE
 */
- (int)play;

/**
 seek到某一时间点
 
 @param time 时间，单位：秒
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * seek在最小间隔区间中 ALIVC_SVIDEO_EDITOR_SEEK_IN_OFFSET
 * ALIVC_FRAMEWORK_AUDIO_PROCESS_SEEK_FAILED
 */
-(int)seek:(float)time;

/**
 暂停播放
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)pause;

/**
 继续播放
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)resume;

/**
 是否正在播放

 @return 正在播放
 */
- (BOOL)isPlaying;

/**
 重新开始播放
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 * 参数不正确 ALIVC_COMMON_INVALID_PARAM
 * 初始化异常返回 ALIVC_FRAMEWORK_AUDIO_RENDER_INIT_SPEAKER_FAILED
 * 状态错误 ALIVC_FRAMEWORK_VIDEO_ENCODER_ERROR_STATE
 * ALIVC_FRAMEWORK_RENDER_ERROR_SCENE_INVALID
 * ALIVC_FRAMEWORK_RENDER_ERROR_EDITORLAYOUT_INVALID_SIZE

 */
- (int)replay;

/**
 停止播放
 * 正常返回 ALIVC_COMMON_RETURN_SUCCESS
 * 状态不正确 ALIVC_COMMON_INVALID_STATE
 */
- (int)stop;

/**
 获取总时长，单位：秒
 @return 总时长
 */
- (double)getDuration;

/**
 获取当前播放时间，单位：秒
 */
- (double)getCurrentTime;

/**
 获取原始视频流时长，单位：秒
 @return 总时长
 */
- (double)getStreamDuration;

/**
 获取原始视频流播放时间，单位：秒
 */
- (double)getCurrentStreamTime;


/**
 设置播放器激活状态
 
 @param active
 接收到系统Active通知，调用该方法设置播放器是否active
 UIApplicationDidBecomeActiveNotification
 UIApplicationWillResignActiveNotification
 处于active状态，播放器可以响应play方法
 处于inactive状态，播放器不可以响应play方法
 SDK内部会注册这两个通知处理active状态
 如果用户要在UIApplicationDidBecomeActiveNotification回调中调play方法
 由于无法保证通知接收的先后顺序，需要先调用该方法保证处于播放器active状态
 */
- (void)setActive:(BOOL)active __deprecated_msg("deprecated");


/**
 设置播放器的刷新频率 默认30帧/s 最大60帧/s 建议不低于20帧/s

 @param fps 帧
 */
- (void)setRefreshFps:(int)fps __deprecated_msg("deprecated");


@end
