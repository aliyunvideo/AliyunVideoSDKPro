//
//  AliyunIRecorder.h
//  qupairecorder
//
//  Created by dangshuai on 16/12/28.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunClipManager.h"
#import "AliyunEffect.h"
#import "AliyunEffectFilter.h"
#import "AliyunEffectImage.h"
#import "AliyunEffectMV.h"
#import "AliyunEffectMusic.h"
#import "AliyunEffectPaster.h"
#import "AliyunFacePoint.h"
#import "AliyunVideoParam.h"
#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h> 

typedef NS_ENUM(NSInteger, AliyunIRecorderCameraPosition) {
    AliyunIRecorderCameraPositionFront = 0,
    AliyunIRecorderCameraPositionBack,
};

typedef NS_ENUM(NSInteger, AliyunIRecorderFlashMode) { AliyunIRecorderFlashModeOff = 0, AliyunIRecorderFlashModeOn = 1, AliyunIRecorderFlashModeAuto = 2 };

typedef NS_ENUM(NSInteger, AliyunIRecorderTorchMode) {
    AliyunIRecorderTorchModeOff = 0,
    AliyunIRecorderTorchModeOn = 1,
    AliyunIRecorderTorchModeAuto = 2,
};

typedef NS_ENUM(NSInteger, AliyunIRecorderDeviceAuthor) { AliyunIRecorderDeviceAuthorEnabled, AliyunIRecorderDeviceAuthorAudioDenied, AliyunIRecorderDeviceAuthorVideoDenied };

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

/**
 录制类，提供录制能力，短视频的核心类之一
 */
/****
 A class that defines recorders.
 */
@interface AliyunIRecorder : NSObject

/**
 预览视图

 必须设置
 */
/****
 The preview view.

 Required.
 */
@property(nonatomic, strong) UIView *preview;

/**
 视频的输出路径

 必须设置
 */
/****
 The video output path.

 Required.
 */
@property(nonatomic, copy) NSString *outputPath;

/**
 taskPath文件夹路径

 需要保证文件夹已经创建，必须设置
 */
/****
 The path of the taskPath folder.

 Required. Enter a valid path.
 */
@property(nonatomic, copy) NSString *taskPath;

/**
 Delegate
 */
/****
 The delegate.
 */
@property(nonatomic, weak) id<AliyunIRecorderDelegate> delegate;

/**
 美颜状态是否开启
 */
/****
 Whether beauty mode is enabled or not. 
 */
@property(nonatomic, assign) BOOL beautifyStatus;

/**
 设置美颜度 [0,100]
 */
/****
 The beauty level. Valid values: [0, 100]
 */
@property(nonatomic, assign) int beautifyValue;

/**
 曝光值 [0,1]
 */
/****
 The exposure level. Valid values: [0, 1]
 */
@property(nonatomic, assign) CGFloat exposureValue;

/**
 前置摄像头采集分辨率

 默认:AVCaptureSessionPreset640x480  更多参数参见：AVCaptureSession.h
 */
/****
 The capture resolution of the front camera.

 Default value: AVCaptureSessionPreset640x480  For more parameters, see: AVCaptureSession.h
 */
@property(nonatomic, copy) NSString *frontCaptureSessionPreset;

/**
 后置摄像头采集分辨率

 默认:AVCaptureSessionPreset1280x720  更多参数参见：AVCaptureSession.h
 */
/****
 The capture resolution of the rear camera.

 Default value: AVCaptureSessionPreset1280x720  For more parameters, see: AVCaptureSession.h
 */
@property(nonatomic, copy) NSString *backCaptureSessionPreset;

/**
 摄像头角度
 */
/****
 The rotation angle of the camera.
 */
@property(nonatomic, assign) int cameraRotate;

/**
 手动对焦点，相对预览视图的位置
 */
/****
 The focus point on the preview.
 */
@property(nonatomic, assign) CGPoint focusPoint;

/**
 调整变焦倍数

 每次调用videoZoomFactor,实际变焦值zoom为设定的1/100
 例：调用videoZoomFactor = 10.0f，实际zoom += 0.1f
 例：调用videoZoomFactor = -5.0f，实际zoom -= 0.05f
 前置摄像头时，该参数是无效的
 */
/****
 The zoom factor.

 The actual value is one hundredth of the specified value.
 For example, when videoZoomFactor is set to 10.0f, the actual zoom is += 0.1f.
 When videoZoomFactor is set to -5.0f, the actual zoom is -= 0.05f
 This parameter does not apply to the front camera.
 */
@property(nonatomic, assign) CGFloat videoZoomFactor;

/**
 编码方式

 0软编  1硬编  iOS强制硬编
 */
/****
 The encoding mode.

 0 indicates software encoding. 1 indicates hardware encoding.
 Hardware encoding is required in iOS.
 */
@property(nonatomic, assign) int encodeMode;

/**
 关键帧间隔,有效区间[0, 9000]，其中0和1都表示全I帧

 默认5
 */
/****
 The GOP size. Valid values: [0, 9,000]. Both 0 and 1 indicate full I-frames.

 Default value: 5
 */
@property(nonatomic, assign) int GOP;

/**
 录制帧率, 取值区间(0,30]，区间外的值将视为无效值，依然使用默认值。

 默认25
 */
/****
 The recording frame rate. Valid values: (0, 30] 
 The default value is used if an invalid value is specified.

 Default value: 25
 */
@property(nonatomic, assign) int recordFps;

/**
 是否静音

 添加音乐后，静音无效
 */
/****
 Whether the recording is muted or not.

 This parameter is invalid if music is added.
 */
@property(nonatomic, assign) BOOL mute;

/**
 视频质量，设置bitrate参数后，该参数无效
 */
/****
 The video quality. This parameter is invalid if the bitrate parameter is set.
 */
@property(nonatomic, assign) AliyunVideoQuality videoQuality;

/**
 输出视频码率 bps  最小值200000bps 最大值20000000bps
 */
/****
 The video output bitrate in bit/s. Valid values: [200,000, 20,000,000]
 */
@property(nonatomic, assign) int bitrate;

/**
 提供三种格式：如果设置不是此三值，将会视情况分配此三种格式中的一种
 kCVPixelFormatType_420YpCbCr8BiPlanarFullRange，
 kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange，
 kCVPixelFormatType_32BGRA，
 默认kCVPixelFormatType_420YpCbCr8BiPlanarFullRange格式
 */
/****
 The pixel format. Select one from the following three formats:
 kCVPixelFormatType_420YpCbCr8BiPlanarFullRange
 kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange
 kCVPixelFormatType_32BGRA
 Default is kCVPixelFormatType_420YpCbCr8BiPlanarFullRange.
 */
@property(nonatomic, assign) AliyunIRecorderVideoOutputPixelFormatType outputType;

/**
 是否开启人脸识别

 使用自带人脸识别，开启该功能，系统会在检测到有人脸动图加入时自动进行追踪显示
 */
/****
 Whether facial recognition is enabled. 

 When facial recognition is enabled, the movements of human faces are automatically detected and tracked.
 */
@property(nonatomic, assign) BOOL useFaceDetect;

/**
 设置识别人脸的个数 当设置值小于1时，默认为1；当设置值大于3时，默认为3

 最大是3个 最小是1个  如果不需要检测人脸 使用:useFaceDetect = NO
 */
/****
 Sets the maximum number of faces that can be recognized at the same time. Valid values: 1, 2, and 3.

 To disable facial recognition, set useFaceDetect to NO.
 */
@property(nonatomic, assign) int faceDetectCount;

/**
 是否同步贴合人脸

 同步贴合人脸动图会在同步线程执行，优点是贴合性强，缺点是性能差的设备会有卡顿现象
 非同步贴合人脸动图，有点是画面流畅但贴图贴合性不强
 默认是YES，6及以下机型建议异步，6以上建议同步
 */
/****
 Whether to synchronize with the movements of human faces.

 When enabled, the movements of human faces are dynamically synchronized to the video. For models that have poor capabilities, video stuttering may occur. 
 When disabled, the movements of human faces are not dynamically synchronized to the video. This ensures smooth video recording. 
 Default is YES. It is recommended to select Yes for iPhone models above 6. 
 */
@property(nonatomic, assign) BOOL faceDectectSync;

/**
 设备权限

 包括麦克风和摄像头权限
 */
/****
 The device permissions.

 Microphone and camera permissions. 
 */
@property(nonatomic, assign, readonly) AliyunIRecorderDeviceAuthor authorizationStatus;

/**
 手电筒是否可用
 */
/****
 Whether the torch is available. 
 */
@property(nonatomic, assign, readonly) BOOL hasTorch;

/**
 电筒模式
 */
/****
 The torch mode.
 */
@property(nonatomic, assign, readonly) AliyunIRecorderTorchMode torchMode;

/**
 获取摄像头位置
 */
/****
 The camera type.
 */
@property(nonatomic, assign, readonly) AliyunIRecorderCameraPosition cameraPosition;

/**
 获取最大变焦系数
 */
/****
 The maximum zoom factor.
 */
@property(nonatomic, assign, readonly) CGFloat videoMaxZoomFactor;

/**
 是否正在录制
 */
/****
 Whether the recording is in progress.
 */
@property(nonatomic, assign, readonly) BOOL isRecording;

/**
 获取视频片段管理器
 */
/****
 The clip manager.
 */
@property(nonatomic, strong, readonly) AliyunClipManager *clipManager;

/**
 获取版本号

 @return 版本号
 */
/****
 Gets the SDK version.

 @return The SDK version.
 */
+ (NSString *)version;

/**
 初始化

 @param delegate 代理
 @param videoSize 视频分辨率，必须为偶数，不能是奇数，不能使用屏幕分辨率
 建议使用的分辨率 320*480,540*960,720*1280
 @return AliyunIRecorder 对象
 */
/****
 Initializer.

 @param delegate The delegate.
 @param videoSize The video resolution. Even numbers only. Must not be set to the screen resolution.
 Recommended values: 320*480, 540*960, and 720*1280.
 @return An AliyunIRecorder object.
 */
- (instancetype)initWithDelegate:(id<AliyunIRecorderDelegate>)delegate videoSize:(CGSize)videoSize;

/**
 开始预览

 @param cameraPosition 摄像头位置（前置、后置）
 */
/****
 Starts preview.

 @param cameraPosition The camera type. Front camera or rear camera.
 */
- (void)startPreviewWithPositon:(AliyunIRecorderCameraPosition)cameraPosition;

/**
 开始预览 默认前置摄像头
 */
/****
 Starts preview. The front camera is used by default.
 */
- (void)startPreview;

/**
 停止预览
 */
/****
 Stops preview.
 */
- (void)stopPreview;

/**
 改变视频分辨率

 @param videoSize 视频分辨率
 */
/****
 Changes the video resolution.

 @param videoSize The new resolution.
 */
- (void)reStartPreviewWithVideoSize:(CGSize)videoSize;

/**
 开始录制
 */
/****
 Starts recording.
 */
- (int)startRecording;

/**
 停止录制

 是否已停止以回调为准
 */
/****
 Stops recording.

 The callback indicates whether the recording is successfully stopped.
 */
- (void)stopRecording;

/**
 完成录制

 是否完成以回调为准
 */
/****
 Finishes recording.

 The callback indicates whether the recording is successfully finished.
 */
- (void)finishRecording;

/**
 释放录制资源
 */
/****
 Releases resources.
 */
- (void)destroyRecorder;

/**
 拍摄一张图片 异步获取

 image 采集的渲染后图片
 rawImage 采集的原始图片
 */
/****
 Takes a picture asynchronously.

 image The image after rendering.
 rawImage The original image.
 */
- (void)takePhoto:(void (^)(UIImage *image, UIImage *rawImage))handler;

/**
 切换摄像头

 @return 切换后的摄像头位置
 */
/****
 Switches the camera.

 @return The type of the camera that is in use.
 */
- (AliyunIRecorderCameraPosition)switchCameraPosition;

/**
 循环切换手电筒模式
 默认为关 (off ---> on ---> auto)

 @return 切换后的手电筒模式
 */
/****
 Switches the torch mode.
 Default is off. The preset sequence of torch modes is: off ---> on ---> auto

 @return The torch mode to be used.
 */
- (AliyunIRecorderTorchMode)switchTorchMode;

/**
 切换为指定手电筒模式

 @param torchMode 指定模式

 @return  return YES if success
 */
/****
 Switches to a specified torch mode.

 @param torchMode The torch mode to be used.

 @return  YES if the invocation is successful.
 */
- (BOOL)switchTorchWithMode:(AliyunIRecorderTorchMode)torchMode;

/**
 人脸数量的回调

 在useFaceDetect开启的状态下生效
 */
/****
 The callback that outputs the number of human faces.

 This parameter only takes effect when useFaceDetect is set to YES.
 */
@property(nonatomic, copy) void (^faceNumbersCallback)(int num);

/**
 人脸追踪 用户可以选择其他人脸识别库，但是传进来的数据须封装成AliyunFacePoint

 @param facePoints 人脸点数组
 */
/****
 Tracks human faces. External face recognition libraries are allowed if face data is represented using AliyunFacePoint.

 @param facePoints The face coordinate in an array.
 */
- (void)faceTrack:(NSArray<AliyunFacePoint *> *)facePoints;

/**
 添加动图

 @param paster 动图
 */
/****
 Applies a sticker.

 @param paster The sticker to be applied.
 */
- (int)applyPaster:(AliyunEffectPaster *)paster;

/**
 添加滤镜

 @param filter 滤镜
 */
/****
 Applies a filter.

 @param filter The filter to be applied.
 */
- (int)applyFilter:(AliyunEffectFilter *)filter;

/**
 添加动效滤镜

 @param filter 滤镜
 @return 返回值
 */
/****
 Applies an animated filter.

 @param filter The filter to be applied.
 @return A return value.
 */
- (int)applyAnimationFilter:(AliyunEffectFilter *)filter;

/**
 添加mv

 @param mv mv
 @return 返回值
 只能在录制开始前调用，录制过程或录制完一段或多段后不能调用该接口
 Deprecated 不建议使用的API，未来版本将会移除
 */
/****
 Applies an MV effect.

 @param mv The MV effect to be applied.
 @return A return value.
 This method can only be called before recording is started.
 Deprecated.
 */
- (int)applyMV:(AliyunEffectMV *)mv __deprecated_msg("This method will not be supported any more. Do not use it.");

/**
 添加水印

 @param image 水印
 */
/****
 Applies a watermark.

 @param image The watermark image to be applied.
 */
- (int)applyImage:(AliyunEffectImage *)image;

/**
 添加音乐

 @param music 音乐
 @return 错误码
 只能在录制开始前调用，录制过程或录制完一段或多段后不能调用该接口
 */
/****
 Applies a music effect. 

 @param music The music effect to be applied.
 @return A return value.
 This method can only be called before recording is started.
 */
- (int)applyMusic:(AliyunEffectMusic *)music;

/**
 设置录制速率

 @param rate 录制速率 建议0.5-2之间
 */
/****
 Sets the recording speed.

 @param rate The recording speed. Recommended values: [0.5, 2.0]
 */
- (void)setRate:(CGFloat)rate;

/**
 删除效果

 @param paster 动图
 */
/****
 Removes a sticker.

 @param paster The sticker to be removed.
 */
- (void)deletePaster:(AliyunEffectPaster *)paster;

/**
 删除滤镜
 */
/****
 Removes a filter.
 */
- (void)deleteFilter;

/**
 删除动效滤镜
 */
/****
 Removes an animated filter.
 */
- (void)deleteAnimationFilter;

/**
 删除水印

 @param image 水印
 */
/****
 Removes a watermark.

 @param image The watermark image to be deleted.
 */
- (void)deleteImage:(AliyunEffectImage *)image;

/**
 设置动图、水印的位置

 @param rect 位置(x,y,width,height)均为比例值  例如播放视频的view的size为(400,400),有动图位置为(50,50,100,100) 则rect参数为(0.125,0.125,0.25,0.25)
 @param effect 指定的效果 (目前支持水印和普通动图)
 */
/****
 Sets the coordinate of a sticker or watermark.

 @param rect The coordinate, (x,y,width,height), is relative to the view size. If the view size is (400, 400), and the position of the sticker is (50, 50, 100, 100), the value of rect is set to (0.125,0.125,0.25,0.25).
 @param effect Currently, only stickers and watermarks are supported.
 */
- (void)setEffectView:(CGRect)rect effect:(AliyunEffect *)effect;

@end

/**
 录制回调协议
 */
/****
 The protocol of recording callbacks.
 */
@protocol AliyunIRecorderDelegate <NSObject>

@required

/**
 设备权限
 @param status 设备权限状态
 */
/****
 The callback that outputs the status of device permissions.
 @param status The status of device permissions.
 */
- (void)recorderDeviceAuthorization:(AliyunIRecorderDeviceAuthor)status;

@optional

/**
 摄像头返回的原始视频数据

 开放出来的目的是用于做人脸识别
 @param sampleBuffer 视频数据
 */
/****
 The callback that outputs the original video data captured by the camera.
 
 Original video data can be used for facial recognition.
 @param sampleBuffer Video data.
 */
- (void)recorderOutputVideoRawSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/**
 返回原始的音频数据

 用来做语音识别一类的业务
 @param sampleBuffer 音频数据
 */
/****
 The callback that outputs the original audio data.
 
 Original audio data can be used for voice recognition.
 @param sampleBuffer Audio data.
 */
- (void)recorderOutputAudioRawSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/**
 用户自定义渲染

 @param sampleBuffer 原始视频数据
 @return 用户自渲染后的PixelBuffer
 */
/****
 The callback for custom rendering. 

 @param sampleBuffer The original video data.
 @return The PixelBuffer after custom rendering is applied.
 */
- (CVPixelBufferRef)customRenderedPixelBufferWithRawSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/**
 用户自定义渲染

 开放pixelBuffer和纹理id给用户自渲染 （仅支持BGRA格式）
 @param pixelBuffer 摄像头数据
 @param textureName 摄像头数据纹理
 @return 自定义渲染后的纹理id
 */
/****
 The callback for custom rendering.
 
 Original video data and texture id are provided for custom rendering. Video data must be in BGRA format.
 @param pixelBuffer The data captured by the camera.
 @param textureName The original texture id. 
 @return The texture id after custom rendering is applied.
 */
- (NSInteger)recorderOutputVideoPixelBuffer:(CVPixelBufferRef)pixelBuffer textureName:(NSInteger)textureName;

/**
 用户自定义渲染接口

 @param srcTexture 原始视频帧纹理id
 @param size 原始视频帧纹理size
 @return 返回纹理id
 */
/****
 The callback for custom rendering.

 @param srcTexture The texture id of the original video.
 @param size The texture size of the original video.
 @return The texture id after custom rendering is applied.
 */
- (int)customRender:(int)srcTexture size:(CGSize)size;

/**
 录制实时时长

 @param duration 录制时长
 */
/****
 The callback that outputs the recording duration.

 @param duration The duration of recording.
 */
- (void)recorderVideoDuration:(CGFloat)duration;

/**
 摄像头返回的原始视频纹理

 摄像头数据格式为BGRA、YUV时都需实现
 @param textureName 原始纹理ID
 @return 处理后的纹理ID
 */
/****
 The callback that outputs the video texture returned by the camera.
 
 This callback must be implemented when the video data is in BGRA or YUV format.
 @param textureName The original texture id.
 @return The texture id after rendering.
 */
- (NSInteger)recorderOutputVideoTextureName:(NSInteger)textureName textureSize:(CGSize)textureSie;

/**
 摄像头返回的原始视频纹理

 摄像头数据格式仅为YUV时须实现，反之不实现
 @param textureName  原始UV分量的纹理ID
 @return 处理后的纹理ID
 */
/****
 The callback that outputs the video texture returned by the camera.
 
 This callback must be implemented when the video data is in YUV format.
 @param textureName The texture id of the original UV components.  
 @return The texture id after rendering.
 */
- (NSInteger)recorderOutputVideoUVTextureName:(NSInteger)textureName;

/**
 开始预览回调
 */
/****
 The callback when preview is started.
 */
- (void)recorderDidStartPreview;

/**
 停止录制回调
 */
/****
 The callback when recording is stopped.
 */
- (void)recorderDidStopRecording;

/**
 当录至最大时长时回调
 */
/****
 The callback when the maximum recording duration is reached.
 */
- (void)recorderDidStopWithMaxDuration;

/**
 结束录制回调
 */
/****
 The callback when recording is finished.
 */
- (void)recorderDidFinishRecording;

/**
 录制异常

 @param error 异常
 */
/****
 The callback when an error occurs during recording.

 @param error The error.
 */
- (void)recoderError:(NSError *)error;

@end
