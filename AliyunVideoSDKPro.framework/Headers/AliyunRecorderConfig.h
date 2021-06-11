//
//  AliyunRecorderConfig.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/4/26.
//  Copyright © 2021 aliyun. All rights reserved.
//

#ifndef AliyunRecorderConfig_h
#define AliyunRecorderConfig_h

#import "AliyunVideoParam.h"
#import "AliyunRecorderSticker.h"
#import "AliyunCameraRecordSource.h"
#import "AliyunViewRecordSource.h"
#import "AliyunAudioRecordController.h"
#import "AliyunMicRecordSource.h"
#import "AliyunPlayerRecordSource.h"

/**
 编码模式 API_AVAILABLE(3.22.0)
 */
/**
 The mode of encode API_AVAILABLE(3.22.0)
 */
typedef NS_ENUM(NSUInteger, AliyunRecorderEncodeMode) {
    /**
     硬编码 API_AVAILABLE(3.22.0)
     */
    /**
     encode using hardware API_AVAILABLE(3.22.0)
     */
    AliyunRecorderEncodeMode_HardCoding,
    /**
     软编码 API_AVAILABLE(3.22.0)
     */
    /**
     encode using software API_AVAILABLE(3.22.0)
     */
    AliyunRecorderEncodeMode_SoftCoding,
};

/**
 视频配置参数 API_AVAILABLE(3.22.0)
 */
/**
 The Config param of video API_AVAILABLE(3.22.0)
 */
@interface AliyunRecorderVideoConfig : NSObject
/**
 编码模式，默认为硬编码 API_AVAILABLE(3.22.0)
 */
/**
 The mode of encode; default is hardcoding API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) AliyunRecorderEncodeMode encodeMode;
/**
 旋转角度 API_AVAILABLE(3.22.0)
 */
/**
 The rotate API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) int rotate;
/**
 分辨率；默认为 720x1280 API_AVAILABLE(3.22.0)
 */
/**
 resolution; default is 720x1280 API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) CGSize resolution;
/**
 裁剪模式；默认为AliyunScaleModeFit API_AVAILABLE(3.22.0)
 */
/**
 The mode of scale; default is AliyunScaleModeFit API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) AliyunScaleMode scaleMode;
/**
 码率 API_AVAILABLE(3.22.0)
 */
/**
 the rate of bit pre second API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) int bitrate;
/**
 视频质量；默认为 AliyunVideoQualityHight API_AVAILABLE(3.22.0)
 */
/**
 The quality of video; default is AliyunVideoQualityHight API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) AliyunVideoQuality videoQuality;
/**
 关键帧间隔 API_AVAILABLE(3.22.0)
 */
/**
 The group of picture API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) int gop;
/**
 帧率 API_AVAILABLE(3.22.0)
 */
/**
 frame rate API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) int fps;

/**
 参数是否有效 API_AVAILABLE(3.22.0)
 */
/**
 is param valid or not API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) BOOL isValid;
@end

/**
 背景图信息 API_AVAILABLE(3.22.0)
 */
/**
 The Info of background API_AVAILABLE(3.22.0)
 */
@interface AliyunRecorderBackgroundInfo : NSObject
/**
 背景颜色 API_AVAILABLE(3.22.0)
 */
/**
 The color of background API_AVAILABLE(3.22.0)
 */
@property (nonatomic, strong) UIColor *color;
/**
 背景图片 API_AVAILABLE(3.22.0)
 */
/**
 The image of background API_AVAILABLE(3.22.0)
 */
@property (nonatomic, strong) UIImage *image;
/**
 渲染模式 API_AVAILABLE(3.22.0)
 */
/**
 The mode of render API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) AliyunRenderMode renderMode;
@end

/**
 录制的配置 API_AVAILABLE(3.22.0)
 */
/**
 The config of record API_AVAILABLE(3.22.0)
 */
@interface AliyunRecorderConfig : NSObject
/**
 输出MP4的文件路径 API_AVAILABLE(3.22.0)
 */
/**
 The path of output mp4 API_AVAILABLE(3.22.0)
 */
@property (nonatomic, copy) NSString *outuptPath;
/**
 录制任务临时路径 API_AVAILABLE(3.22.0)
 */
/**
 The tmp path of recorder task API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) NSString *taskPath;
/**
 输出视频配置 API_AVAILABLE(3.22.0)
 */
/**
 The Config of output video API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunRecorderVideoConfig *videoConfig;
/**
 背景信息 API_AVAILABLE(3.22.0)
 */
/**
 The Info of background API_AVAILABLE(3.22.0)
 */
@property (nonatomic, strong) AliyunRecorderBackgroundInfo *bgInfo;

/**
 麦克风控制器（如果设置了背景音乐则为空） API_AVAILABLE(3.22.0)
 */
/**
 The controller of mic (it will be nil if set the bg music) API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) id<AliyunMicRecordController> microphoneController;
/**
 视频控制器 API_AVAILABLE(3.22.0)
 */
/**
 The controllers of video API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) NSArray<id<AliyunVideoBaseRecordController>> *videoRecordControllers;

/**
 初始化 API_AVAILABLE(3.22.0)
 
 @param videoConfig 输出视频配置
 @param outputPath 最终输出mp4路径
 */
- (instancetype) initWithVideoConfig:(AliyunRecorderVideoConfig *)videoConfig
                          outputPath:(NSString *)outputPath;

/**
 API_AVAILABLE(3.22.0)
 添加摄像头源（只能添加一个，多次调用返回同一个控制器）
 @param layout 摄像头源在输出视频的位置布局
 */
/**
 API_AVAILABLE(3.22.0)
 add camera record source (can not add multi, if you call multi it will return same controller)
 
 @param layout the layout of camera source in the output video
 */
- (id<AliyunCameraRecordController>) addCamera:(AliyunVideoRecordLayoutParam *)layout;
/**
 添加视图源 API_AVAILABLE(3.22.0)
 
 @param source 视图源
 @param layout 视图源在输出视频的位置布局
 */
/**
 add source from view API_AVAILABLE(3.22.0)
 
 @param source the source of view
 @param layout the layout of view source in the output video
 */
- (id<AliyunViewRecordController>) addViewSource:(AliyunViewRecordSource *)source
                                          layout:(AliyunVideoRecordLayoutParam *)layout;

/**
 添加MV源 API_AVAILABLE(3.22.0)
 
 @param source MV源
 @param layout MV源在输出视频的位置布局
 */
/**
 add source from video API_AVAILABLE(3.22.0)
 
 @param source the source of mv
 @param layout the layout of mv source in th output video
 */
- (id<AliyunPlayerRecordController>) addMVSource:(AliyunPlayerRecordSource *)source
                                          layout:(AliyunVideoRecordLayoutParam *)layout;

/**
 删除视频源 API_AVAILABLE(3.22.0)
 
 @param videoId 视频源唯一标识，对应controller里的videoId
 */
/**
 remove video API_AVAILABLE(3.22.0)
 
 @param videoId The id of video in the controller.videoid
 */
- (BOOL) removeVideo:(int)videoId;

/**
 添加水印 API_AVAILABLE(3.22.0)
 
 @param waterMark 水印
 */
/**
 add water mark API_AVAILABLE(3.22.0)
 
 @param waterMark The sticker info for water mark
 */
- (void) addWaterMark:(AliyunRecorderImageSticker *)waterMark;

/**
 移除水印 API_AVAILABLE(3.22.0)
 
 @param waterMarkId 贴纸的ID
 */
/**
 remove water mark API_AVAILABLE(3.22.0)
 
 @param waterMarkId the id of water mark
 */
- (void) removeWaterMark:(int)waterMarkId;

/**
 设置背景音乐 API_AVAILABLE(3.22.0)
 
 @param filePath 背景音乐文件
 @param startTime 从哪里开始截取背景音乐
 @param duration 截取多长的音乐
 */
/**
 Set background music API_AVAILABLE(3.22.0)
 
 @param filePath the path of music resource
 @param start the start time in music file
 @param duration the duration clip from music file
 */
- (void) setBgMusicWithFile:(NSString *)filePath
                  startTime:(NSTimeInterval)startTime
                   duration:(NSTimeInterval)duration;

/**
 移除背景音乐 API_AVAILABLE(3.22.0)
 */
/**
 remove background music API_AVAILABLE(3.22.0)
 */
- (void) removeBgMusic;

@end

#endif /* AliyunRecorderConfig_h */
