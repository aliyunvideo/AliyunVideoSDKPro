//
//  AlivcMixComposer.h
//  AliyunVideoSDK
//
//  Created by Vienta on 2019/5/13.
//  Copyright © 2019 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunMixTrack.h"
#import "AliyunVideoParam.h"

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@protocol AlivcMixComposerDelegate <NSObject>

- (void)mixComposerOnProgress:(float)progress;
- (void)mixComposerDidComplete;
- (void)mixComposerDidError:(int)error;

@end

/**
 VideoJoiner
 */
@interface AliyunMixComposer : NSObject

@property(nonatomic, weak) id<AlivcMixComposerDelegate> delegate;

/**
 视频最终导出分辨率
 */
@property(nonatomic, assign) CGSize outputSize;

/**
 视频最终导出路径 必须设置
 */
@property(nonatomic, copy) NSString *outputPath;

/**
 码率 bps
 */
@property(nonatomic, assign) NSInteger bitrate;

/**
 视频质量
 */
@property(nonatomic, assign) AliyunVideoQuality videoQuality;

/**
 帧率，这里指的是平均帧率 默认：30
 */
@property(nonatomic, assign) CGFloat fps;

/**
 关键帧间隔 默认：5
 */
@property(nonatomic, assign) NSInteger gop;

/**
 初始化合拍视频轨道

 @param trackDisplayFrame 该轨道的分辨率（参考坐标为视频导出分辨率，例如导出分辨率为960*960，trackDisplayFrame设置为(0,0,480,960)说明该轨道占据了左半部分区域）
 @return AlivcMixTrack对象
 */
- (AliyunMixTrack *)createTrack:(CGRect)trackDisplayFrame;

/**
 指定以某个轨道的时长作为最终合成视频的时长

 @param referenceTrack 轨道
 */
- (void)setOutputDurationReferenceTrack:(AliyunMixTrack *)referenceTrack;

/**
 指定以某个轨道的音频作为最终合成视频的音频

 @param referenceTrack 轨道
 */
- (void)setOutputAudioReferenceTrack:(AliyunMixTrack *)referenceTrack;

/**
 开始合成

 @return 返回值
 */
- (int)start;

/**
 暂停合成

 @return 返回值
 */
- (int)pause;

/**
 恢复以继续合成

 @return 返回值
 */
- (int)resume;

/**
 取消合成

 @return 返回值
 */
- (int)cancel;

@end
