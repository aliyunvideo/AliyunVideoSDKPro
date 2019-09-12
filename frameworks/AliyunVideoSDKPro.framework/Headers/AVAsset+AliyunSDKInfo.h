//
//  AVAsset+AliyunSDKInfo.h
//  QUSDK
//
//  Created by Worthy on 2017/9/29.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

/**
 AVAsset扩展Category
 */
/****
 This class extends Category.
 */
@interface AVAsset (AliyunSDKInfo)

/**
 获取asset显示的宽高

 @return size
 */
/****
 Gets the size of the asset.

 @return The size.
 */
- (CGSize)aliyunNaturalSize;

/**
 获取asset帧率

 @return 帧率
 */
/****
 Gets the frame rate of the asset.

 @return The frame rate.
 */
- (CGFloat)aliyunFrameRate;

/**
 获取asset码率

 @return 码率，单位：bps
 */
/****
 Gets the bitrate of the asset.

 @return The bitrate in bit/s.
 */
- (CGFloat)aliyunBitrate;

/**
 获取asset时长

 @return 时长，单位：秒
 */
/****
 Gets the duration of the asset.

 @return The duration in seconds.
 */
- (CGFloat)aliyunDuration;

/**
 获取asset视频流时长

 @return 时长，单位：秒
 */
/****
 Gets the duration of the video stream in the asset.

 @return The duration in seconds.
 */
- (CGFloat)aliyunVideoDuration;

/**
 获取asset音频流时长

 @return 时长，单位：秒
 */
/****
 Gets the duration of the audio stream in the asset.

 @return The duration in seconds.
 */
- (CGFloat)aliyunAudioDuration;

/**
 获取关键帧间隔

 该方法耗时
 @return 关键帧间隔
 */
/****
 Gets the key frame interval.
 
 This method may take some time.
 @return The key frame interval.
 */
- (CGFloat)aliyunEstimatedKeyframeInterval __deprecated_msg("deprecated");

@end
