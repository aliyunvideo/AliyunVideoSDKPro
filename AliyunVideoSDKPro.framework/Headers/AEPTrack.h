//
//  AEPTrack.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEPVideoTrackClip.h"
#import "AEPAudioTrackClip.h"

/**
 轨道
 */
/**
 The Track
 */
@interface AEPTrack : NSObject

/**
 轨道ID
 */
/**
 The id of track
 */
@property (nonatomic, assign, readonly) int trackId;

@end


/**
 视频轨道
 */
/**
 The track of video
 */
@interface AEPVideoTrack : AEPTrack

/**
 视频持续时间
 */
/**
 The duration of video
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/**
 视频片段列表
 */
/**
 The list of video clip
 */
@property (nonatomic, copy, readonly) NSArray<AEPVideoTrackClip *> *clipList;

@end


/**
 音频轨道
 */
/**
 The track of audio
 */
@interface AEPAudioTrack : AEPTrack

/**
 音频持续时间
 */
/**
 The duration of audio
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/**
 音频片段列表
 */
/**
 The list of audio clip
 */
@property (nonatomic, copy, readonly) NSArray<AEPAudioTrackClip *> *clipList;

@end
