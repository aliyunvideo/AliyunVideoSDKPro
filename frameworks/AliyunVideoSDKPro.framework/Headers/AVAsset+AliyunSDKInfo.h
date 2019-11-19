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
@interface AVAsset (AliyunSDKInfo)

/**
 获取asset显示的宽高

 @return size
 */
- (CGSize)aliyunNaturalSize;

/**
 获取asset帧率

 @return 帧率
 */
- (CGFloat)aliyunFrameRate;

/**
 获取asset码率

 @return 码率，单位：bps
 */
- (CGFloat)aliyunBitrate;

/**
 获取asset时长

 @return 时长，单位：秒
 */
- (CGFloat)aliyunDuration;

/**
 获取asset视频流时长

 @return 时长，单位：秒
 */
- (CGFloat)aliyunVideoDuration;

/**
 获取asset音频流时长

 @return 时长，单位：秒
 */
- (CGFloat)aliyunAudioDuration;

/**
 获取关键帧间隔

 该方法耗时
 @return 关键帧间隔
 */
- (CGFloat)aliyunEstimatedKeyframeInterval __deprecated_msg("deprecated");

@end
