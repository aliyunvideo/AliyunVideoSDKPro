//
//  AliyunVideoRecordController.h
//  AliyunVideoSDKPro
//
//  Created by coder.pi on 2021/4/26.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import "AliyunRecordController.h"
#import "AliyunFacePoint.h"
#import "AliyunEffectFilter.h"
#import "AliyunRenderModel.h"
#import "AliyunImageStickerController.h"
#import "AliyunGifStickerController.h"
#import <UIKit/UIKit.h>

/**
 根据机器方向判断旋转的协议 API_AVAILABLE(3.22.0)
 */
/**
 The protocol of rotate follow the device orientation API_AVAILABLE(3.22.0)
 */
@protocol AliyunVideoSourceOrientation <NSObject>
@optional
/**
 计算旋转到对应方向的角度 API_AVAILABLE(3.22.0)
 */
/**
 Calculate the roate to the orientation API_AVAILABLE(3.22.0)
 */
- (int) rotateToOrientation:(UIDeviceOrientation)orientation;
/**
  API_AVAILABLE(3.22.0)
 当前重力方向的旋转角度
 用于人脸识别
 */
/**
  API_AVAILABLE(3.22.0)
 current rotate for the direction of gravity
 be used for face facial recognition
 */
- (int) rotateToGravity;
/**
 更新重力方向 API_AVAILABLE(3.22.0)
 */
/**
 update the direction of gravity API_AVAILABLE(3.22.0)
 */
- (void) updateGravityRotate:(UIDeviceOrientation)orientation;
@end

/**
 视频源布局参数 API_AVAILABLE(3.22.0)
 */
/**
 The param of video layout API_AVAILABLE(3.22.0)
 */
@interface AliyunVideoRecordLayoutParam : AliyunRenderModel
/**
 视频层级 API_AVAILABLE(3.22.0)
 */
/**
 The layer level of video API_AVAILABLE(3.22.0)
 */
@property (nonatomic, assign) int zPosition;
/**
  API_AVAILABLE(3.22.0)
 初始化
 @param mode 渲染模式
 */
- (instancetype) initWithRenderMode:(AliyunRenderMode)mode;
/**
 设置自适应方式 API_AVAILABLE(3.22.0)
 */
/**
 set the strategy of autoresizing
 */
- (void) setAutoresizingMask:(UIViewAutoresizing)mask;
@end

/**
 视频源的边框信息 API_AVAILABLE(3.22.0)
 */
/**
 The border info of video API_AVAILABLE(3.22.0)
 */
@interface AliyunVideoRecordBorderInfo : NSObject
/**
 边框的颜色（透明度无效） API_AVAILABLE(3.22.0)
 */
/**
 The color of border(ignore alpha) API_AVAILABLE(3.22.0)
 */
@property (nonatomic, strong) UIColor *color;
/**
 边框的宽度，基于整体输出视频分辨率的像素值 API_AVAILABLE(3.22.0)
 */
/**
  API_AVAILABLE(3.22.0)
 The width of border
 base on the resolution of output video
 */
@property (nonatomic, assign) CGFloat width;
/**
 边框的圆角半径，基于整体输出分辨率的像素值 API_AVAILABLE(3.22.0)
 */
/**
  API_AVAILABLE(3.22.0)
 The radius of border corner
 base on the resolution of output video
 */
@property (nonatomic, assign) CGFloat cornerRadius;
@end

/**
 基础视频控制器 API_AVAILABLE(3.22.0)
 */
/**
 The base controller of video source API_AVAILABLE(3.22.0)
 */
@protocol AliyunVideoBaseRecordController <AliyunRecordController>
/**
 视频源标识 API_AVAILABLE(3.22.0)
 */
/**
 the id of video API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) int videoId;
/**
 边框信息 API_AVAILABLE(3.22.0)
 */
/**
 the info of border API_AVAILABLE(3.22.0)
 */
@property (nonatomic, strong) AliyunVideoRecordBorderInfo *borderInfo;
/**
 布局参数 API_AVAILABLE(3.22.0)
 */
/**
 the param of layout API_AVAILABLE(3.22.0)
 */
@property (nonatomic, readonly) AliyunVideoRecordLayoutParam *layoutParam;
@end


/**
 全功能的视频控制器 API_AVAILABLE(3.22.0)
 */
/**
 The full function controller of video API_AVAILABLE(3.22.0)
 */
@protocol AliyunVideoRecordController<AliyunVideoBaseRecordController>
/**
  API_AVAILABLE(3.22.0)
 预览视图

 必须设置
 */
/**
  API_AVAILABLE(3.22.0)
 preview
 
 must be setup
 */
@property (nonatomic, weak) UIView *preview;

/**
 录制的视频是否左右翻转（只影响输出，不影响预览） API_AVAILABLE(3.22.0)
 */
/**
 Horizontal flip for the video (only effect on output, not for preview) API_AVAILABLE(3.22.0)
 */
@property(nonatomic, assign) BOOL isVideoMirror;

/**
  旋转角度,0,90,180,270 API_AVAILABLE(3.22.0)
 */
/**
 rotation, 0, 90, 180, 270 API_AVAILABLE(3.22.0)
 */
@property(nonatomic, assign) int rotation;

/**
 美颜状态是否开启 API_AVAILABLE(3.22.0)
 */
/**
 Whether beauty mode is enabled or not. API_AVAILABLE(3.22.0)
 */
@property(nonatomic, assign) BOOL beautifyStatus;

/**
 设置美颜度 [0,100] API_AVAILABLE(3.22.0)
 */
/**
 The beauty level. Valid values: [0, 100] API_AVAILABLE(3.22.0)
 */
@property(nonatomic, assign) int beautifyValue;

/**
  API_AVAILABLE(3.22.0)
 是否开启人脸识别

 使用自带人脸识别，开启该功能，系统会在检测到有人脸动图加入时自动进行追踪显示
 */
/**
  API_AVAILABLE(3.22.0)
 Whether facial recognition is enabled.

 When facial recognition is enabled, the movements of human faces are automatically detected and tracked.
 */
@property(nonatomic, assign) BOOL useFaceDetect;

/**
  API_AVAILABLE(3.22.0)
 设置识别人脸的个数 当设置值小于1时，默认为1；当设置值大于3时，默认为3

 最大是3个 最小是1个  如果不需要检测人脸 使用:useFaceDetect = NO
 */
/**
  API_AVAILABLE(3.22.0)
 Sets the maximum number of faces that can be recognized at the same time. Valid values: 1, 2, and 3.

 To disable facial recognition, set useFaceDetect to NO.
 */
@property(nonatomic, assign) int faceDetectCount;

/**
  API_AVAILABLE(3.22.0)
 人脸数量的回调

 在useFaceDetect开启的状态下生效
 */
/**
  API_AVAILABLE(3.22.0)
 The callback that outputs the number of human faces.

 This parameter only takes effect when useFaceDetect is set to YES.
 */
@property(nonatomic, copy) void (^faceNumbersCallback)(int num);

/**
  API_AVAILABLE(3.22.0)
 是否同步贴合人脸

 同步贴合人脸动图会在同步线程执行，优点是贴合性强，缺点是性能差的设备会有卡顿现象
 非同步贴合人脸动图，有点是画面流畅但贴图贴合性不强
 默认是YES，6及以下机型建议异步，6以上建议同步
 */
/**
  API_AVAILABLE(3.22.0)
 Whether to synchronize with the movements of human faces.

 When enabled, the movements of human faces are dynamically synchronized to the video. For models that have poor capabilities, video stuttering may occur.
 When disabled, the movements of human faces are not dynamically synchronized to the video. This ensures smooth video recording.
 Default is YES. It is recommended to select Yes for iPhone models above 6.
 */
@property(nonatomic, assign) BOOL faceDectectSync;

/**
  API_AVAILABLE(3.22.0)
 人脸追踪 用户可以选择其他人脸识别库，但是传进来的数据须封装成AliyunFacePoint

 @param facePoints 人脸点数组
 */
/**
  API_AVAILABLE(3.22.0)
 Tracks human faces. External face recognition libraries are allowed if face data is represented using AliyunFacePoint.

 @param facePoints The face coordinate in an array.
 */
- (void)faceTrack:(NSArray<AliyunFacePoint *> *)facePoints;

/**
  API_AVAILABLE(3.22.0)
 拍摄一张图片 异步获取

 image 采集的渲染后图片
 rawImage 采集的原始图片
 */
/**
  API_AVAILABLE(3.22.0)
 Takes a picture asynchronously.

 image The image after rendering.
 rawImage The original image.
 */
- (void)takePhoto:(void (^)(UIImage *image, UIImage *rawImage))handler;

/**
  API_AVAILABLE(3.22.0)
  添加人脸贴图
 
  @param configDirectory 人脸贴图配置文件夹路径
 */
/**
  API_AVAILABLE(3.22.0)
 Add sticker for face
 
  @param configDirectory the config directory of  face sticker
 */
- (int) applyFaceSticker:(NSString *)configDirectory;

/**
  API_AVAILABLE(3.22.0)
  删除人脸贴图
 */
/**
  API_AVAILABLE(3.22.0)
 delete sticker of face
 */
- (void) deleteFaceSticker;

/**
  API_AVAILABLE(3.22.0)
 添加动图

 @param configDirectory 动图配置文件夹路径
 */
/**
  API_AVAILABLE(3.22.0)
 add gif sticker
 
 @param configDirectory the config directory of  gif sticker
 */
- (AliyunGifStickerController *) addGifStickerWithConfig:(NSString *)configDirectory;

/**
 添加图片 API_AVAILABLE(3.22.0)

 @param image 图片
 */
/**
 add image sticker API_AVAILABLE(3.22.0)
 
 @param imagePath the imagePath of sticker
 */
- (AliyunImageStickerController *) addImageSticker:(NSString *)imagePath;

/**
 删除贴纸 API_AVAILABLE(3.22.0)

 @param stickerId 贴纸id
 */
/**
 delete sticker API_AVAILABLE(3.22.0)
 
 @param stickerId the id of sticker
 */
- (void)deleteSticker:(int)stickerId;

/**
 添加滤镜 API_AVAILABLE(3.22.0)

 @param filter 滤镜
 */
/**
 add filter API_AVAILABLE(3.22.0)
 
 @param filter the filter of video
 */
- (int)applyFilter:(AliyunEffectFilter *)filter;

/**
 删除滤镜 API_AVAILABLE(3.22.0)
 */
/**
 Removes a filter. API_AVAILABLE(3.22.0)
 */
- (void)deleteFilter;

/**
 添加动效滤镜 API_AVAILABLE(3.22.0)

 @param filter 滤镜
 @return 返回值
 */
/**
 Applies an animated filter. API_AVAILABLE(3.22.0)

 @param filter The filter to be applied.
 @return A return value.
 */
- (int)applyAnimationFilter:(AliyunEffectFilter *)filter;

/**
 更新动效滤镜 API_AVAILABLE(3.22.0)

 @param filter 滤镜
 @return 返回值
 */
/**
 update an animated filter. API_AVAILABLE(3.22.0)

 @param filter The filter to be applied.
 @return A return value.
 */
- (int)updateAnimationFilter:(AliyunEffectFilter *)filter;

/**
 删除动效滤镜 API_AVAILABLE(3.22.0)
 */
/**
 Removes an animated filter. API_AVAILABLE(3.22.0)
 */
- (void)deleteAnimationFilter;


@end
