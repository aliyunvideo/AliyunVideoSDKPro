//
//  AliyunRecordController.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/4/26.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunRecordSource.h"

@protocol AliyunRecordController;
/**
 自定义数据源数据处理 API_AVAILABLE(3.22.0)
 */
/**
 The callback of custom handler record data API_AVAILABLE(3.22.0)
 */
@protocol AliyunRecordControllerCustomSourceHandler <NSObject>
@optional
/**
  API_AVAILABLE(3.22.0)
 数据流采集源返回的原始数据
 可用于做自定义的人脸识别
 */
/**
  API_AVAILABLE(3.22.0)
 The callback of data stream from capture
 can be used for facial recognition.
 */
- (void) onAliyunRecordController:(id<AliyunRecordController>)controller
               customHandleVideo:(CMSampleBufferRef)buffer
                withDisplayMatrix:(CATransform3D)transform;

/**
  API_AVAILABLE(3.22.0)
 数据流采集源返回的原始数据
 可用于做自定义的语音识别等
 */
/**
  API_AVAILABLE(3.22.0)
 The callback of data stream from capture
 can be used for voice recognition.
 */
- (void) onAliyunRecordController:(id<AliyunRecordController>)controller
          customHandleAudioBuffer:(CMSampleBufferRef)buffer;
@end

/**
 录制源的控制器 API_AVAILABLE(3.22.0)
 */
/**
 The Controller of record source API_AVAILABLE(3.22.0)
 */
@protocol AliyunRecordController <NSObject>
/**
 标记录制源是否已经准备好 API_AVAILABLE(3.22.0)
 */
/**
  The Flag of record is ready API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) BOOL isReady;
/**
 录制源 API_AVAILABLE(3.22.0)
 */
/**
 Resource source API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) id<AliyunRecordSource> source;
/**
 自定义数据处理回调 API_AVAILABLE(3.22.0)
 */
/**
 The callback of custom handler for capture data stream API_AVAILABLE(3.22.0)
 */
@property (nonatomic, weak) id<AliyunRecordControllerCustomSourceHandler> customHandler;
@end
