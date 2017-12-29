//
//  AliyunIRecorder.h
//  qupairecorder
//
//  Created by dangshuai on 16/12/28.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "AliyunFacePoint.h"
#import "AliyunEffect.h"
#import "AliyunClipManager.h"
#import "AliyunVideoParam.h"
#import "AliyunEffectPaster.h"
#import "AliyunEffectImage.h"
#import "AliyunEffectMusic.h"
#import "AliyunEffectFilter.h"

typedef NS_ENUM(NSInteger, AliyunIRecorderCameraPosition) {
    AliyunIRecorderCameraPositionFront = 0,
    AliyunIRecorderCameraPositionBack,
};

typedef NS_ENUM(NSInteger, AliyunIRecorderFlashMode) {
    AliyunIRecorderFlashModeOff  = 0,
    AliyunIRecorderFlashModeOn   = 1,
    AliyunIRecorderFlashModeAuto = 2
};

typedef NS_ENUM(NSInteger, AliyunIRecorderTorchMode) {
    AliyunIRecorderTorchModeOff  = 0,
    AliyunIRecorderTorchModeOn   = 1,
    AliyunIRecorderTorchModeAuto = 2,
};

typedef NS_ENUM(NSInteger, AliyunIRecorderDeviceAuthor) {
    AliyunIRecorderDeviceAuthorEnabled,
    AliyunIRecorderDeviceAuthorAudioDenied,
    AliyunIRecorderDeviceAuthorVideoDenied
};

typedef NS_ENUM(NSInteger, AliyunIRecorderVideoOutputPixelFormatType) {
    AliyunIRecorderVideoOutputPixelFormatType420f,
    AliyunIRecorderVideoOutputPixelFormatType420v,
    AliyunIRecorderVideoOutputPixelFormatTypeBGRA,
};

enum {
    AliyunIRecorderErrorCantStitch = 100,
    AliyunIRecorderErrorCameraInterrupt = 101,
};


@protocol AliyunIRecorderDelegate;

@interface AliyunIRecorder : NSObject
    
/**
 预览视图
 
 @warn 必须设置
 */
@property (nonatomic, strong) UIView *preview;

/**
 Delegate
 */
@property (nonatomic, weak) id <AliyunIRecorderDelegate> delegate;

/**
 美颜状态
 */
@property (nonatomic, assign) BOOL beautifyStatus;

/**
 设置美颜度 [0,100]
 */
@property (nonatomic, assign) int beautifyValue;

/**
 设备权限 包括麦克风和摄像头
 */
@property (nonatomic, assign, readonly) AliyunIRecorderDeviceAuthor authorizationStatus;

/**
 曝光值
 */
@property (nonatomic, assign) CGFloat exposureValue;

/**
 闪光灯是否可用
 */
@property (nonatomic, assign, readonly) BOOL hasFlash;

/**
 手电筒是否可用
 */
@property (nonatomic, assign, readonly) BOOL hasTorch;

/**
 闪光灯模式
 */
@property (nonatomic, assign, readonly) AliyunIRecorderFlashMode flashMode;

/**
 电筒模式
 */
@property (nonatomic, assign, readonly) AliyunIRecorderTorchMode torchMode;

/**
 摄像头位置
 */
@property (nonatomic, assign, readonly) AliyunIRecorderCameraPosition cameraPosition;


/**
 前置摄像头采集分辨率 默认:AVCaptureSessionPreset640x480  更多参数参见：AVCaptureSession.h
 */
@property (nonatomic, copy) NSString *frontCaptureSessionPreset;

/**
 后置摄像头采集分辨率 默认:AVCaptureSessionPreset640x480  更多参数参见：AVCaptureSession.h
 */
@property (nonatomic, copy) NSString *backCaptureSessionPreset;

/**
 摄像头角度
 */
@property (nonatomic, assign) int cameraRotate;

/**
 手动对焦点
 */
@property (nonatomic, assign) CGPoint focusPoint;

/**
 变焦系数
 
 前置摄像头时，该参数是无效的
 */
@property (nonatomic, assign) CGFloat videoZoomFactor;


/**
 最大变焦系数
 */
@property (nonatomic, assign, readonly) CGFloat videoMaxZoomFactor;

/**
 是否正在录制
 */
@property (nonatomic, assign, readonly) BOOL isRecording;

/**
 视频的输出路径
 */
@property (nonatomic, copy) NSString *outputPath;

/**
 视频缩略图路径
 */
@property (nonatomic, copy) NSString *thumbnailPath;


/**
 文件配置路径
 */
@property (nonatomic, copy) NSString *taskPath;


/**
 编码方式
 
 0软编  1硬编
 */
@property (nonatomic, assign) int encodeMode;

/**
 关键帧间隔
 
 建议1-300，默认5
 */
@property (nonatomic, assign) int GOP;

/**
 静音
 
 添加音乐后，静音无效
 */
@property (nonatomic, assign) BOOL mute;

/**
 视频质量
 */
@property (nonatomic, assign) AliyunVideoQuality videoQuality;


/**
 码率
 */
@property (nonatomic, assign) int bitrate;

/**
 视频片段管理
 */
@property (nonatomic, strong, readonly) AliyunClipManager *clipManager;

/**
 提供三种格式：
 kCVPixelFormatType_420YpCbCr8BiPlanarFullRange，
 kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange，
 kCVPixelFormatType_32BGRA，
 
 默认kCVPixelFormatType_420YpCbCr8BiPlanarFullRange格式 
 */
@property (nonatomic, assign) AliyunIRecorderVideoOutputPixelFormatType outputType;


/**
 使用自带人脸识别，开启该功能，系统会在检测到有人脸动图加入时自动进行追踪显示
 */
@property (nonatomic, assign) BOOL useFaceDetect;


/**
 设置识别人脸的个数  最大是3个 最小是1个  如果不需要检测人脸 使用:useFaceDetect = NO
 */
@property (nonatomic, assign) int faceDetectCount;


/**
 是否同步贴合人脸，默认同步。说明：同步贴合人脸动图会在同步线程执行，优点是贴合性强，缺点是性能差的设备会有卡顿现象；非同步贴合人脸动图，有点是画面流畅但贴图贴合性不强。默认是YES。6及以下机型适合异步，以上适合同步
 */
@property (nonatomic, assign) BOOL faceDectectSync;

/**
 人脸数量的回调，在useFaceDetect开启的状态下生效
 */
@property (nonatomic, copy) void (^faceNumbersCallback)(int num);


+ (NSString *)version;

/**
 初始化
 
 @param delegate 代理
 @param videoSize 视频分辨率
 @return AliyunIRecorder 对象
 */
- (instancetype)initWithDelegate:(id)delegate videoSize:(CGSize)videoSize;

/**
 开始预览
 
 @param cameraPosition 摄像头位置（前置、后置）
 */
- (void)startPreviewWithPositon:(AliyunIRecorderCameraPosition)cameraPosition;

/**
 开始预览 默认前置摄像头
 */
- (void)startPreview;

/**
 停止预览
 */
- (void)stopPreview;

/**
 切换摄像头
 
 @return 切换后的摄像头位置
 */
- (AliyunIRecorderCameraPosition)switchCameraPosition;

/**
 循环切换闪光灯模式 (适用于照片模式)
 默认为关 (off ---> on ---> auto)
 
 @return 切换后的闪光灯模式
 */
- (AliyunIRecorderFlashMode)switchFlashMode;

/**
 切换为指定闪光灯模式 (适用于照片模式)
 
 @param flashMode 指定模式
 
 @return  return YES if success
 */
- (BOOL)switchFlashWithMode:(AliyunIRecorderFlashMode)flashMode;

/**
 循环切换手电筒模式 (适用于视频模式)
 默认为关 (off ---> on ---> auto)
 
 @return 切换后的手电筒模式
 */
- (AliyunIRecorderTorchMode)switchTorchMode;

/**
 切换为指定手电筒模式 (适用于视频模式)
 
 @param torchMode 指定模式
 
 @return  return YES if success
 */
- (BOOL)switchTorchWithMode:(AliyunIRecorderTorchMode)torchMode;


/**
 改变视频分辨率

 @param videoSize 视频分辨率
 */
- (void)reStartPreviewWithVideoSize:(CGSize)videoSize;

/**
 开始录制
 */
- (int)startRecording;


/**
 停止录制
 
 是否已停止以回调为准
 */
- (void)stopRecording;

/**
 完成录制
 
 是否完成以回调为准
 */
- (void)finishRecording;

/**
 释放录制资源
 */
- (void)destroyRecorder;


/**
 人脸追踪 用户可以选择其他地方人人脸识别库，但是传进来的数据须封装成AliyunFacePoint

 @param facePoints 人脸点数组
 */
- (void)faceTrack:(NSArray<AliyunFacePoint *> *)facePoints;

/**
 添加动图

 @param paster 动图
 */
- (int)applyPaster:(AliyunEffectPaster *)paster;

/**
 添加滤镜

 @param filter 滤镜
 */
- (int)applyFilter:(AliyunEffectFilter *)filter;

/**
 添加水印

 @param image 水印
 */
- (int)applyImage:(AliyunEffectImage *)image;


/**
 添加音乐

 @param music 音乐
 @return 错误码
 */
- (int)applyMusic:(AliyunEffectMusic *)music;

/**
 设置录制速率
 
 @param rate 录制速率
 */
- (void)setRate:(CGFloat)rate;

/**
 删除效果

 @param paster 动图
 */
- (void)deletePaster:(AliyunEffectPaster *)paster;

/**
 删除滤镜
 */
- (void)deleteFilter;

/**
 删除水印

 @param image 水印
 */
- (void)deleteImage:(AliyunEffectImage *)image;

/**
 设置动图、水印的位置

 @param rect 位置(x,y,width,height)均为比例值  例如播放视频的view的size为(400,400),有动图位置为(50,50,100,100) 则rect参数为(0.125,0.125,0.25,0.25)
 @param effect 指定的效果 (目前支持水印和普通动图)
 */
- (void)setEffectView:(CGRect)rect effect:(AliyunEffect *)effect;


/**
 拍摄一张图片 异步获取
 */
- (void)takePhoto:(void (^)(UIImage *image, UIImage *rawImage))handler;


@end


@protocol AliyunIRecorderDelegate <NSObject>

@required

/**
 设备权限
 @param status 设备权限状态
 */
- (void)recorderDeviceAuthorization:(AliyunIRecorderDeviceAuthor)status;

@optional
/**
 摄像头返回的原始视频数据  开放出来的目的是用于做人脸识别

 @param sampleBuffer 视频数据
 */
- (void)recorderOutputVideoRawSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/**
 返回原始的音频数据 用来做语音识别一类的业务
 
 @param sampleBuffer 音频数据
 */
- (void)recorderOutputAudioRawSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/**

/**
 用户自定义渲染

 @param sampleBuffer 原始数据
 @return 用户自渲染后的PixelBuffer
 */
- (CVPixelBufferRef)customRenderedPixelBufferWithRawSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/**
 用户自定义渲染，开放pixelBuffer和纹理id给用户自渲染 （仅支持BGRA格式）

 @param pixelBuffer 摄像头数据
 @param textureName 摄像头数据纹理
 @return 自定义渲染后的纹理id
 */
- (NSInteger)recorderOutputVideoPixelBuffer:(CVPixelBufferRef)pixelBuffer textureName:(NSInteger)textureName;

/**
 用户自定义渲染接口
 
 @param srcTexture 原始视频帧纹理id
 @param size 原始视频帧纹理size
 @return 返回纹理id
 */
- (int)customRender:(int)srcTexture size:(CGSize)size;
/**

 录制实时时长

 @param duration 录制时长
 */
- (void)recorderVideoDuration:(CGFloat)duration;

/**
 摄像头返回的原始视频纹理
 摄像头数据格式为BGRA、YUV时都需实现
 
 @param textureName 原始纹理ID
 @return 处理后的纹理ID
 */
- (NSInteger)recorderOutputVideoTextureName:(NSInteger)textureName textureSize:(CGSize)textureSie;


/**
 摄像头返回的原始视频纹理  
 摄像头数据格式仅为YUV时须实现，反之不实现

 @param textureName  原始UV分量的纹理ID
 @return 处理后的纹理ID
 */
- (NSInteger)recorderOutputVideoUVTextureName:(NSInteger)textureName;

/**
 开始预览回调
 */
- (void)recorderDidStartPreview;

/**
 停止录制回调
 */
- (void)recorderDidStopRecording;

/**
 当录至最大时长时回调
 */
- (void)recorderDidStopWithMaxDuration;

/**
 结束录制回调
 */
- (void)recorderDidFinishRecording;

/**
 录制异常

 @param error 异常
 */
- (void)recoderError:(NSError *)error;

@end
