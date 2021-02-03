//
//  AlivcMixTrack.h
//  AliyunVideoSDK
//
//  Created by Vienta on 2019/5/13.
//  Copyright © 2019 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunMixStream.h"
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@interface AliyunMixTrack : NSObject

/**
 标记该轨道的时长是否作为最终合成视频的时长
 API_AVAILABLE(3.19.0)
 */
@property(nonatomic, assign) BOOL outputDurationReferenceTrack;

/**
 标记该轨道的音频是否输出
 API_AVAILABLE(3.19.0)
 */
@property(nonatomic, assign) BOOL outputAudioReferenceTrack;


/**
 音量输出大小（多路混音时生效，单路设置无效）
 范围：[0-100]
 API_AVAILABLE(3.19.0)
 */
@property(nonatomic, assign) int outputAudioWeight;

/**
 向该轨道加入视频

 @param stream 视频
 */
- (void)addStream:(AliyunMixStream *)stream;

@end
