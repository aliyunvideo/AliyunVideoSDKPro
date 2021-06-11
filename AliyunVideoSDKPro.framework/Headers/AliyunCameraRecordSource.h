//
//  AliyunCameraRecordSource.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/4/21.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunVideoRecordController.h"

/**
 摄像头输出图像格式 API_AVAILABLE(3.22.0)
 */
/**
 the output pixel format of camera API_AVAILABLE(3.22.0)
 */
typedef NS_ENUM(NSInteger, AliyunRecordCameraPixelFormat) {
    /**
     参考 kCVPixelFormatType_420YpCbCr8BiPlanarFullRange API_AVAILABLE(3.22.0)
     */
    /**
     Same as kCVPixelFormatType_420YpCbCr8BiPlanarFullRange API_AVAILABLE(3.22.0)
     */
    AliyunRecordCameraPixelFormat_420PF,
    /**
     参考 kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange API_AVAILABLE(3.22.0)
     */
    /**
     Same as kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange API_AVAILABLE(3.22.0)
     */
    AliyunRecordCameraPixelFormat_420PV,
    /**
     参考 kCVPixelFormatType_32BGRA API_AVAILABLE(3.22.0)
     */
    /**
     Same as kCVPixelFormatType_32BGRA API_AVAILABLE(3.22.0)
     */
    AliyunRecordCameraPixelFormat_BGRA,
};

/**
 摄像头采集的清晰度 API_AVAILABLE(3.22.0)
 */
/**
 The resolution of camera API_AVAILABLE(3.22.0)
 */
typedef NS_ENUM(NSUInteger, AliyunRecordCameraResolution) {
    /**
     参考 AVCaptureSessionPreset352x288 API_AVAILABLE(3.22.0)
     */
    /**
     Same as AVCaptureSessionPreset352x288 API_AVAILABLE(3.22.0)
     */
    AliyunRecordCameraResolution_352x288 = 0,
    /**
     参考 AVCaptureSessionPreset640x480 API_AVAILABLE(3.22.0)
     */
    /**
     Same as AVCaptureSessionPreset640x480 API_AVAILABLE(3.22.0)
     */
    AliyunRecordCameraResolution_640x480,
    /**
     参考 AVCaptureSessionPresetiFrame960x540 API_AVAILABLE(3.22.0)
     */
    /**
      Same as AVCaptureSessionPresetiFrame960x540 API_AVAILABLE(3.22.0)
     */
    AliyunRecordCameraResolution_960x540,
    /**
     参考 AVCaptureSessionPresetiFrame1280x720 和 AVCaptureSessionPreset1280x720 API_AVAILABLE(3.22.0)
     */
    /**
     Same as AVCaptureSessionPresetiFrame1280x720 and AVCaptureSessionPreset1280x720 API_AVAILABLE(3.22.0)
     */
    AliyunRecordCameraResolution_1280x720,
    /**
     参考 AVCaptureSessionPreset1920x1080 API_AVAILABLE(3.22.0)
     */
    /**
     Same as AVCaptureSessionPreset1920x1080 API_AVAILABLE(3.22.0)
     */
    AliyunRecordCameraResolution_1920x1080,
};

/**
 摄像头录制源 API_AVAILABLE(3.22.0)
 */
/**
 The source of camera record API_AVAILABLE(3.22.0)
 */
@interface AliyunCameraRecordSource : NSObject<AliyunRecordDataSource, AliyunRecordSourceFPS, AliyunVideoSourceOrientation>
/**
 视频输出像素格式 API_AVAILABLE(3.22.0)
 */
/**
 the pixel format of camera output API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunRecordCameraPixelFormat pixelFormat;
/**
 摄像头采集分辨率 API_AVAILABLE(3.22.0)
 */
/**
 The resolution of camera capture API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) AliyunRecordCameraResolution resolution;
/**
 建议的采集分辨率 API_AVAILABLE(3.22.0)
 */
/**
 The suggest resolution of capture API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunRecordCameraResolution suggestResolution;

/**
 是否支持手电筒 API_AVAILABLE(3.22.0)
 */
/**
 is support torch API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) BOOL hasTorch;
/**
 手电筒模式 API_AVAILABLE(3.22.0)
 */
/**
 the mode of torch API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) AVCaptureTorchMode torchMode;

/**
 是否支持闪光灯 API_AVAILABLE(3.22.0)
 */
/**
 is support flash API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) BOOL hasFlash;
/**
 闪光灯模式 API_AVAILABLE(3.22.0)
 */
/**
 the mode of flash API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) AVCaptureFlashMode flashMode;

/**
 是否处于镜像模式 API_AVAILABLE(3.22.0)
 */
/**
 is mirror capture API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) BOOL isVideoMirror;
/**
 使用前置或后置摄像头 API_AVAILABLE(3.22.0)
 */
/**
 front or back camera be use API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) AVCaptureDevicePosition position;

/**
 曝光率 API_AVAILABLE(3.22.0)
 */
/**
 exposure value API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) CGFloat exposureValue;
/**
 采集方向 API_AVAILABLE(3.22.0)
 */
/**
 the orientation of capture API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) UIDeviceOrientation orientation;

/**
 前置摄像头是否支持变焦 API_AVAILABLE(3.22.0)
 */
/**
 is support video zoom for front camera API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) BOOL isSupportVideoZoomForFront;
/**
 焦距 API_AVAILABLE(3.22.0)
 */
/**
 the video zoom factor API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) CGFloat videoZoomFactor;
/**
 最大焦距 API_AVAILABLE(3.22.0)
 */
/**
 the max value of video zoom factor API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) CGFloat videoMaxZoomFactor;

/**
 初始化 API_AVAILABLE(3.22.0)
 
 @param pixelFormat 像素值格式
 @param fps 帧率
 */
/**
 Init API_AVAILABLE(3.22.0)
 
 @param pixelFormat the format of pixel
 @param fps the capture frequency pre second
 */
- (instancetype) initWithPixelFormat:(AliyunRecordCameraPixelFormat)pixelFormat fps:(int)fps;

/**
 手动调整焦点 API_AVAILABLE(3.22.0)
 
 @param focusPoint 焦点位置(归一化）
 */
/**
 adjust force point API_AVAILABLE(3.22.0)
 
 @param focusPoint the focus point in normalized
 */
- (void) adjustForceWithNormalizedPoint:(CGPoint)focusPoint;
@end

/**
 摄像头控制器 API_AVAILABLE(3.22.0)
 */
/**
 The controller of camera API_AVAILABLE(3.22.0)
 */
@protocol AliyunCameraRecordController<AliyunVideoRecordController>
/**
 摄像头源 API_AVAILABLE(3.22.0)
 */
/**
 The Camera source API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunCameraRecordSource *camera;
@end
