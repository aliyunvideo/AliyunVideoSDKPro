//
//  AliyunRecorder.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/4/20.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliyunRecorderConfig.h"
#import "AliyunClipManager.h"

/**
 录制状态 API_AVAILABLE(3.22.0)
 */
/**
 The State of recorder API_AVAILABLE(3.22.0)
 */
typedef NS_ENUM(NSUInteger, AliyunRecorderState) {
    /**
     空闲状态，等待录制 API_AVAILABLE(3.22.0)
     */
    /**
     Idle, waiting for record API_AVAILABLE(3.22.0)
     */
    AliyunRecorderState_Idle = 0,
    /**
     录制前加载；等待各个录制源首帧回调；收到全部回调后会自动变为recording状态 API_AVAILABLE(3.22.0)
     */
    /**
     Loading of record; wait the first frame of all record source; it will auto change to recording if got all first frame of all record source API_AVAILABLE(3.22.0)
     */
    AliyunRecorderState_LoadingForRecord,
    /**
     录制中 API_AVAILABLE(3.22.0)
     */
    /**
     recording API_AVAILABLE(3.22.0)
     */
    AliyunRecorderState_Recording,
    /**
     正在停止；等待内部缓冲处理完成会自动变为停止状态 API_AVAILABLE(3.22.0)
     */
    /**
     stopping, waiting for flush data in buffer, it will auto change to stop state if flush finish API_AVAILABLE(3.22.0)
     */
    AliyunRecorderState_Stopping,
    /**
     停止录制 API_AVAILABLE(3.22.0)
     */
    /**
     Stop recording API_AVAILABLE(3.22.0)
     */
    AliyunRecorderState_Stop,
    /**
     发生错误；可以通过cancel来把状态重置为idle API_AVAILABLE(3.22.0)
     */
    /**
     Error occurred; call cancel will reset the state to idle API_AVAILABLE(3.22.0)
     */
    AliyunRecorderState_Error,
    
    AliyunRecorderState_Max,
};

@class AliyunRecorder;
/**
 录制事件回调 API_AVAILABLE(3.22.0)
 */
/**
 The Callback of recorder event API_AVAILABLE(3.22.0)
 */
@protocol AliyunRecorderDelegate <NSObject>
@optional
/**
 录制状态发生改变 API_AVAILABLE(3.22.0)
 */
/**
 The State of recorder has been change API_AVAILABLE(3.22.0)
 */
- (void) onAliyunRecorder:(AliyunRecorder *)recorder stateDidChange:(AliyunRecorderState)state;
/**
 预览状态发生改变 API_AVAILABLE(3.22.0)
 */
/**
 The preview state of recorder has been change API_AVAILABLE(3.22.0)
 */
- (void) onAliyunRecorder:(AliyunRecorder *)recorder previewStateDidChange:(BOOL)isPreviewing;
/**
  录制进度发生改变 API_AVAILABLE(3.22.0)
 */
/**
  The progress of recorder has been change API_AVAILABLE(3.22.0)
 */
- (void) onAliyunRecorder:(AliyunRecorder *)recorder progressWithDuration:(CGFloat)duration;
/**
  录制发生了错误 API_AVAILABLE(3.22.0)
 */
/**
 Error of record occurred API_AVAILABLE(3.22.0)
 */
- (void) onAliyunRecorder:(AliyunRecorder *)recorder occursError:(NSError *)error;
@end

/**
 自定义渲染回调 API_AVAILABLE(3.22.0)
 */
/**
 The callback of custom render API_AVAILABLE(3.22.0)
 */
@protocol AliyunRecorderCustomRender <NSObject>
@optional
/**
 通过CMSampleBuffer自定义渲染，并返回结果的CVPixelBufferRef API_AVAILABLE(3.22.0)
 */
/**
 custom render from cmsamplebuffer to cvpixelbufferref API_AVAILABLE(3.22.0)
 */
- (CVPixelBufferRef) onAliyunRecorderCustomRenderToPixelBuffer:(AliyunRecorder *)recorder
                                              withSampleBuffer:(CMSampleBufferRef)sampleBuffer;
/**
 通过CMSampleBuffer自定义渲染，并返回结果的纹理ID API_AVAILABLE(3.22.0)
 */
/**
 custom render from cmsamplebuffer to texture id API_AVAILABLE(3.22.0)
 */
- (int) onAliyunRecorderCustomRenderToTexture:(AliyunRecorder *)recorder
                             withSampleBuffer:(CMSampleBufferRef)sampleBuffer;
/**
 通过纹理ID渲染，并返回结果的纹理ID API_AVAILABLE(3.22.0)
 
 @param textureId 纹理id
 @param size 纹理大小
 */
/**
 custom render from texture id to texture id API_AVAILABLE(3.22.0)
 
 @param textureid the id of texture in opengl
 @param size the size of texture
 */
- (int) onAliyunRecorderCustomRenderToTexture:(AliyunRecorder *)recorder
                             withSrcTextureId:(int)textureId
                                         size:(CGSize)size;

/**
 建议销毁自定义渲染相关 API_AVAILABLE(3.22.0)
 */
/**
 suggest to destory the resource of custom render API_AVAILABLE(3.22.0)
 */
- (void) onAliyunRecorderDidDestory:(AliyunRecorder *)recorder;
@end

@interface AliyunRecorder : NSObject
/**
 是否正在录制 API_AVAILABLE(3.22.0)
 */
/**
 is in recording state API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) BOOL isRecording;
/**
 是否正在预览 API_AVAILABLE(3.22.0)
 */
/**
 is in previewing API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) BOOL isPreviewing;
/**
 录制状态 API_AVAILABLE(3.22.0)
 */
/**
 the state of recorder API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunRecorderState state;
/**
 录制事件回调 API_AVAILABLE(3.22.0)
 */
/**
 The callback of recorder event API_AVAILABLE(3.22.0)
 */
@property (nonatomic, weak) id<AliyunRecorderDelegate> delegate;
/**
 自定义渲染 API_AVAILABLE(3.22.0)
 */
/**
 The custom render API_AVAILABLE(3.22.0)
 */
@property (nonatomic, weak) id<AliyunRecorderCustomRender> customRender;

/**
 录制输出配置 API_AVAILABLE(3.22.0)
 */
/**
 The config of output video API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunRecorderConfig *config;
/**
 录制速率 API_AVAILABLE(3.22.0)
 */
/**
 The rate of recording API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) CGFloat rate;
/**
 片段管理器 API_AVAILABLE(3.22.0)
 */
/**
 The manager of video clip API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunClipManager *clipManager;

/**
 初始化 API_AVAILABLE(3.22.0)
 
 @param config 输出视频配置
 */
/**
 Init API_AVAILABLE(3.22.0)
 
 @param config the config of output video param
 */
- (instancetype) initWithConfig:(AliyunRecorderConfig *)config;

/**
 API_AVAILABLE(3.22.0)
 录制准备；一些录制源可能需要在这阶段去做权限申请之类；如果不调用会在开始录制或者开始预览时调用
 @return 准备是否成功
 */
/**
 API_AVAILABLE(3.22.0)
 prepare for record; some record source may be need auth in this step; if you not call this, inner will call in startRecord or startPreview
 @return is success or not
 */
- (BOOL) prepare;

/**
 开始预览 API_AVAILABLE(3.22.0)
 */
/**
 start preview API_AVAILABLE(3.22.0)
 */
- (int) startPreview;
/**
 结束预览 API_AVAILABLE(3.22.0)
 */
/**
 stop preview API_AVAILABLE(3.22.0)
 */
- (void) stopPreview;

/**
 开始录制 API_AVAILABLE(3.22.0)
 */
/**
 start record API_AVAILABLE(3.22.0)
 */
- (int) startRecord;
/**
 结束录制 API_AVAILABLE(3.22.0)
 */
/**
 stop record API_AVAILABLE(3.22.0)
 */
- (void) stopRecord;

/**
 结束录制 API_AVAILABLE(3.22.0)
 
 @param completion 结束完成的回调；结束录制需要对多段录制进行异步拼接；拼接完成会调用此回调
 */
/**
 Finish record API_AVAILABLE(3.22.0)
 
 @param completion the callback of finishRecord; finish record need merge multi record clip async. it will call this function if merge finish
 */
- (void) finishRecord:(void(^)(NSString *outputPath, NSError *error))completion;

/**
 取消录制；删除之前录制片段，状态重置为idle API_AVAILABLE(3.22.0)
 */
/**
 Cancel; it will delete all the clip resource that record before. and change the state to idle API_AVAILABLE(3.22.0)
 */
- (void) cancel;
@end
