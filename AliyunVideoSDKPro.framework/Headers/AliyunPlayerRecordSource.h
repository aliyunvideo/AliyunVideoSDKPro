//
//  AliyunPlayerRecordSource.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/5/19.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunViewRecordSource.h"

/**
 视频播放器源 API_AVAILABLE(3.22.0)
 */
/**
 The record source of video player API_AVAILABLE(3.22.0)
 */
@interface AliyunPlayerRecordSource : AliyunViewRecordSource
/**
 内容适配策略 API_AVAILABLE(3.22.0)
 */
/**
 The strategy of conent render API_AVAILABLE(3.22.0)
 */
@property (nonatomic, copy) AVLayerVideoGravity gravity;
/**
 视频的分辨率 API_AVAILABLE(3.22.0)
 */
/**
 The Resolution of video API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) CGSize resolution;
/**
 视频时长(秒） API_AVAILABLE(3.22.0)
 */
/**
 The duration of video in second API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) NSTimeInterval duration; // second

/**
 目标视频 API_AVAILABLE(3.23.0)
 */
/**
 The target asset API_AVAILABLE(3.23.0)
 */
@property (nonatomic, readonly) AVAsset *targetAsset;

/**
  API_AVAILABLE(3.22.0)
 @param asset 视频资源
 @param fps 采集频率
 */
- (instancetype) initWithAsset:(AVAsset *)asset fps:(int)fps;
@end

/**
 视频播放的录制控制器 API_AVAILABLE(3.22.0)
 */
/**
 The Record controller of video player API_AVAILABLE(3.22.0)
 */
@protocol AliyunPlayerRecordController<AliyunVideoBaseRecordController>
/**
  API_AVAILABLE(3.22.0)
 预览视图

 必须设置
 */
@property (nonatomic, weak) UIView *preview;

/**
 视频播放源 API_AVAILABLE(3.22.0)
 */
/**
 The Source of video player API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunPlayerRecordSource *player;
@end
