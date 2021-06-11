//
//  AliyunRecordSource.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/4/20.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

/**
 录制源的媒体类型 API_AVAILABLE(3.22.0)
 */
/**
 media type of record source API_AVAILABLE(3.22.0)
 */
typedef NS_ENUM(NSUInteger, AliyunRecordMediaType) {
    /**
     视频 API_AVAILABLE(3.22.0)
     */
    /**
     Video Type API_AVAILABLE(3.22.0)
     */
    AliyunRecordMediaType_Video = 1 << 0,
    /**
     音频 API_AVAILABLE(3.22.0)
     */
    /**
     Audio Type API_AVAILABLE(3.22.0)
     */
    AliyunRecordMediaType_Audio = 1 << 1,
};

/**
 录制源类型 API_AVAILABLE(3.22.0)
 */
/**
 type of record source API_AVAILABLE(3.22.0)
 */
typedef NS_ENUM(NSUInteger, AliyunRecordSourceType) {
    /**
     数据流类型的录制源 API_AVAILABLE(3.22.0)
     */
    /**
     Record Source of Data Stream API_AVAILABLE(3.22.0)
     */
    AliyunRecordSourceType_Data,
    /**
     文件类型的录制源 API_AVAILABLE(3.22.0)
     */
    /**
     Record Source of File API_AVAILABLE(3.22.0)
     */
    AliyunRecordSourceType_File,
};

/**
 录制源协议 API_AVAILABLE(3.22.0)
 */
/**
 The Protocol Of Record Source API_AVAILABLE(3.22.0)
 */
@protocol AliyunRecordSource <NSObject>
/**
 录制源的类型 API_AVAILABLE(3.22.0)
 */
/**
 Type of Record source API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunRecordSourceType sourceType;
/**
 录制源的媒体类型 API_AVAILABLE(3.22.0)
 */
/**
 Media of Record source API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunRecordMediaType mediaType;
/**
 是否正在采集 API_AVAILABLE(3.22.0)
 */
/**
 IsRunning API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) BOOL isRunning;
/**
 采集速率 API_AVAILABLE(3.22.0)
 */
/**
 The capture rate API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) CGFloat rate;
/**
  API_AVAILABLE(3.22.0)
 录制源准备
 例如摄像头、麦克风做一些权限申请
 */
/**
  API_AVAILABLE(3.22.0)
 prepare of record source
 eg. request device authorization for camera, mic
 */
- (BOOL) prepare;
/**
 开始采集 API_AVAILABLE(3.22.0)
 */
/**
 start capture API_AVAILABLE(3.22.0)
 */
- (void) start;
/**
 停止采集 API_AVAILABLE(3.22.0)
 */
/**
 stop catpure API_AVAILABLE(3.22.0)
 */
- (void) stop;
/**
  API_AVAILABLE(3.22.0)
 跳到指定时间，实时的录制源可忽略
 */
/**
  API_AVAILABLE(3.22.0)
 jump to the specified time.
 source of realtime will ignore
 */
- (void) seek:(NSTimeInterval)timeInSecond;
@end


@protocol AliyunRecordSource;
/**
 数据流的采集回调 API_AVAILABLE(3.22.0)
 */
/**
 callback of data stream capture API_AVAILABLE(3.22.0)
 */
@protocol AliyunRecordDataSourceDelegate <NSObject>
/**
 视频采集数据回调 API_AVAILABLE(3.22.0)
 */
/**
 The callback of video data stream API_AVAILABLE(3.22.0)
 */
- (BOOL) onAliyunRecordSource:(id<AliyunRecordSource>)source
         didOutputVideoBuffer:(CMSampleBufferRef)buffer
                displayMatrix:(CATransform3D)transform;

/**
 音频采集数据回调 API_AVAILABLE(3.22.0)
 */
/**
 The callback of audio data stream API_AVAILABLE(3.22.0)
 */
- (BOOL) onAliyunRecordSource:(id<AliyunRecordSource>)source
         didOutputAudioBuffer:(CMSampleBufferRef)buffer;
@end


/**
 数据流类型的采集源 API_AVAILABLE(3.22.0)
 */
/**
 Record source of data stream type API_AVAILABLE(3.22.0)
 */
@protocol AliyunRecordDataSource <AliyunRecordSource>
/**
 数据流采集源的回调 API_AVAILABLE(3.22.0)
 */
/**
 The callback of data stream API_AVAILABLE(3.22.0)
 */
@property (nonatomic, weak) id<AliyunRecordDataSourceDelegate> dataSourceDelegate;
@end

/**
 文件类型的采集源 API_AVAILABLE(3.22.0)
 */
/**
 Resource source of file type API_AVAILABLE(3.22.0)
 */
@protocol AliyunRecordFileSource <AliyunRecordSource>
/**
 文件路径 API_AVAILABLE(3.22.0)
 */
/**
 file path API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) NSString *filePath;
/**
 从文件的什么位置开始（秒） API_AVAILABLE(3.22.0)
 */
/**
 start offset time in the file API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) NSTimeInterval startTime;
/**
 参与采集的时间段 API_AVAILABLE(3.22.0)
 */
/**
 duration for capture in the file API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) NSTimeInterval duration;
@end

/**
 动态帧率的协议 API_AVAILABLE(3.22.0)
 */
/**
 The Project of dynamic fps API_AVAILABLE(3.22.0)
 */
@protocol AliyunRecordSourceFPS <NSObject>
/**
 设置的帧率 API_AVAILABLE(3.22.0)
 */
/**
 fps of preset API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) int fps;
/**
 最大能达到的帧率 API_AVAILABLE(3.22.0)
 */
/**
 the max fps of can reach API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) int maxFPS;
/**
 真实的帧率 API_AVAILABLE(3.22.0)
 */
/**
 the real fps API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) int realFPS;
@end
