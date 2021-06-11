//
//  AliyunViewRecordSource.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/4/21.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunVideoRecordController.h"

/**
 视图源 API_AVAILABLE(3.22.0)
 */
/**
The Record soruce of view / layer API_AVAILABLE(3.22.0)
 */
@interface AliyunViewRecordSource : NSObject<AliyunRecordDataSource, AliyunRecordSourceFPS>
/**
 是否混合了avplayer API_AVAILABLE(3.22.0)
 如果使用initWithTargetView，但没有设置混合avplayer，默认忽略视图内avplayer内容
 */
/**
 is mix avplayer in view API_AVAILABLE(3.22.0)
 in using initWithTargetView, it will ignore avplayer content if mixAVPlayer is NO
 */
@property (nonatomic, assign) BOOL mixAVPlayer;
/**
 不在主线程进行采集（不能采集包含GPU内容，如GLView） API_AVAILABLE(3.22.0)
 默认YES; 不在主线程采集
 */
/**
 capture not in mainThread (can not capture content in gpu, eg. glview) API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) BOOL captureInBackground;
/**
 采集的目标图层 API_AVAILABLE(3.22.0)
 */
/**
 The layer of capture target API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) CALayer *targetLayer;
/**
 使用视图初始化 API_AVAILABLE(3.22.0)
 
 @param view 采集的目标视图
 @param fps 采集的频率
 */
/**
 Init with view API_AVAILABLE(3.22.0)
 
 @param view The target of capture view
 @param fps The fps of capture
 */
- (instancetype) initWithTargetView:(UIView *)view fps:(int)fps;
/**
 使用avplayerlayer初始化 API_AVAILABLE(3.22.0)
 
 @param layer 视频播放图层
 @param fps 采集的帧率
 */
/**
 using AVPlayerLayer to init API_AVAILABLE(3.22.0)
 
 @param layer The target AVPlayerLayer of capture
 @param fps The fps of capture
 */
- (instancetype) initWithAVPlayerLayer:(AVPlayerLayer *)layer fps:(int)fps;
@end


/**
 视图源控制器 API_AVAILABLE(3.22.0)
 */
/**
 The Controller of view record API_AVAILABLE(3.22.0)
 */
@protocol AliyunViewRecordController <AliyunVideoBaseRecordController>
/**
 视图源 API_AVAILABLE(3.22.0)
 */
/**
The record source of view API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunViewRecordSource *viewSource;
@end
