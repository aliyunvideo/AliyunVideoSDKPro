//
//  AliyunAudioRecorder.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/6/22.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunClip.h"
#import <Foundation/Foundation.h>

/**
 音频录制回调协议
 */
/****
 The protocol of audio recording callbacks. 
 */
@protocol AliyunAudioRecorderDelegate<NSObject>

/**
 录制进度

 @param second 秒
 */
/****
 Gets the progress of the recording.

 @param second The duration of the recorded audio. 
 */
- (void)audioRecorderProgress:(float)second;

@end

/**
 音频录制类
 */
/****
 A class that defines audio recorders.
 */
__deprecated_msg("deprecated") @interface AliyunAudioRecorder : NSObject

/**
 是否正在录制
 */
/****
 Whether or not the recording is in progress.
 */
@property (nonatomic, assign) BOOL isRecording;

/**
 录制回调类
 */
/****
 The recording callback.
 */
@property (nonatomic, assign) id<AliyunAudioRecorderDelegate> delegate;

/**
 初始化

 @param outputPath 输出文件路径
 @return audiorecorder对象
 */
/****
 Initializer.

 @param outputPath The file output path.
 @return An audiorecorder object.
 */
- (id)initWithOutputPath:(NSString *)outputPath;

/**
 开始录制
 */
/****
 Starts recording.
 */
- (void)startRecord;

/**
 停止录制
 */
/****
 Stops recording.
 */
- (void)stopRecord;

/**
 结束录制流程
 */
/****
 Finishes the recording process.
 */
- (void)finishRecord;

/**
 所有片段

 @return 获取所有片段集合
 */
/****
 Gets all recorded clips.

 @return The array of all recorded clips.
 */
- (NSArray<AliyunClip *> *)allClips;

/**
 删除clip

 @param clip 音频片段
 */
/****
 Deletes a clip.

 @param clip The audio clip to be deleted.
 */
- (void)deleteClip:(AliyunClip *)clip;

/**
 删除最后一段clip
 */
/****
 Deletes the last clip.
 */
- (void)deleteLastClip;

/**
 音频录制的总时长 非录制过程中

 @return 时长
 */
/****
 Gets the total duration of the recorded audio.

 @return The total duration of the recorded audio.
 */
- (float)totalDuration;

@end
