//
//  AEPTimeline.h
//  AliyunVideoSDKPro
//
//  Created by Bingo on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEPTrack.h"
#import "AEPStickerTrack.h"
#import "AEPEffectTrack.h"
#import "AEPGlobalTrack.h"

/**
 时间线
 */
/**
 The timeline of editor project
 */
@interface AEPTimeline : NSObject

/**
 持续时间，秒
 */
/**
 The duration of video, (second)
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/**
 视频轨道
 */
/**
 The tracks of video
 */
@property (nonatomic, copy, readonly) NSArray<AEPVideoTrack *> *videoTracks;

/**
 音频轨道
 */
/**
The tracks of audio
 */
@property (nonatomic, copy, readonly) NSArray<AEPAudioTrack *> *audioTracks;

/**
 贴纸轨道
 */
/**
 The tracks of stickers
 */
@property (nonatomic, copy, readonly) NSArray<AEPStickerTrack *> *stickerTracks;

/**
 效果轨道
 */
/**
 The tracks of effect
 */
@property (nonatomic, copy, readonly) NSArray<AEPEffectTrack *> *effectTracks;

/**
 涂鸦
 */
/**
The Paint
 */
@property (nonatomic, strong, readonly) AEPGlobalPaintTrack *paintTrack;

/**
 水印
 */
/**
 The watermark
 */
@property (nonatomic, strong, readonly) AEPGlobalWatermarkTrack *watermark;

/**
 尾部水印
 */
/**
 The tail water
 */
@property (nonatomic, strong, readonly) AEPGlobalTailWatermarkTrack *tailWatermark;
@end
