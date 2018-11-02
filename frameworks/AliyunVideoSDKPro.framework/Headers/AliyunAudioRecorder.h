//
//  AliyunAudioRecorder.h
//  AliyunVideoSDKPro
//
//  Created by Vienta on 2018/6/22.
//  Copyright © 2018年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunClip.h"

@protocol AliyunAudioRecorderDelegate<NSObject>

- (void)audioRecorderProgress:(float)second;

@end

@interface AliyunAudioRecorder : NSObject

@property (nonatomic, assign) BOOL isRecording;
@property (nonatomic, assign) id<AliyunAudioRecorderDelegate> delegate;

/**
 初始化

 @param outputPath 输出文件路径
 @return audiorecorder对象
 */
- (id)initWithOutputPath:(NSString *)outputPath;

/**
 开始录制
 */
- (void)startRecord;

/**
 停止录制
 */
- (void)stopRecord;


/**
 结束录制流程
 */
- (void)finishRecord;


/**
 所有片段

 @return 获取所有片段集合
 */
- (NSArray<AliyunClip *> *)allClips;


/**
 删除clip

 @param clip 音频片段
 */
- (void)deleteClip:(AliyunClip *)clip;

/**
 删除最后一段clip
 */
- (void)deleteLastClip;

/**
 音频录制的总时长 非录制过程中

 @return 时长
 */
- (float)totalDuration;



@end
