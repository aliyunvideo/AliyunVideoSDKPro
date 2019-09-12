//
//  AliyunPasterController.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/3.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunPasterUIEventProtocol.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class AliyunEffectPasterFrameItem;

/**
 动图类型

 - AliyunPasterEffectTypeNormal: 仅动图
 - AliyunPasterEffectTypeSubtitle: 仅文
 - AliyunPasterEffectTypeCaption: 动图+文字
 */
/****
 Sticker types.

 - AliyunPasterEffectTypeNormal: Sticker.
 - AliyunPasterEffectTypeSubtitle: Standard caption.
 - AliyunPasterEffectTypeCaption: Animated caption.
 */
typedef NS_ENUM(NSInteger, AliyunPasterEffectType) {
    AliyunPasterEffectTypeNormal = 0,
    AliyunPasterEffectTypeSubtitle = 1,
    AliyunPasterEffectTypeCaption = 2,
};

/**
 动图控制器类
 */
/****
 A class that defines sticker controllers.
 */
@interface AliyunPasterController : NSObject<AliyunPasterUIEventProtocol>


/**
 设置动图的view

 @warning:一定要设置
 */
/****
 The view of the sticker.
 
 @warning: This parameter is required.
 */
@property (nonatomic, strong) UIView *pasterView;

/**
 动图类型
 */
/****
 The sticker type.
 */
@property (nonatomic, assign, readonly) AliyunPasterEffectType pasterType;

/**
 动图的旋转角度

 单位：弧度
 */
/****
 The rotation angle of the sticker.
 
 Unit: radians.
 */
@property (nonatomic, assign) CGFloat pasterRotate;

/**
 动图的位置(x,y)
 */
/****
 The position of the sticker in the screen.
 */
@property (nonatomic, assign) CGPoint pasterPosition;

/**
 动图的宽高
 */
/****
 The size of the sticker.
 */
@property (nonatomic, assign) CGSize pasterSize;

/**
 动图的位置大小
 */
/****
 The size of the sticker in the screen.
 */
@property (nonatomic, assign) CGRect pasterFrame;

/**
 动图镜像
 */
/****
 Whether to flip the sticker.
 */
@property (nonatomic, assign) BOOL mirror;

/**
 文字内容
 */
/****
 The text contents.
 */
@property (nonatomic, copy) NSString *subtitle;

/**
 文字位置

 相对于动图本身的位置大小
 */
/****
 The position of the text relative to the background sticker.
 
 */
@property (nonatomic, assign) CGRect subtitleFrame;

/**
 文字的后台配置字体
 */
/****
 The text font name.
 */
@property (nonatomic, copy, readonly) NSString *subtitleConfigFontName;

/**
 文字的后台配置字体的id
 */
/****
 The text font id.
 */
@property (nonatomic, assign, readonly) NSInteger subtitleConfigFontId;

/**
 文字是否描边
 */
/****
 Whether the text is stroked.
 */
@property (nonatomic, assign) BOOL subtitleStroke;

/**
 文字颜色
 */
/****
 The text color.
 */
@property (nonatomic, strong) UIColor *subtitleColor;

/**
 文字描边颜色
 */
/****
 The text stroke color.
 */
@property (nonatomic, strong) UIColor *subtitleStrokeColor;

/**
 文字的背景颜色
 */
/****
 The text background color.
 */
@property (nonatomic, strong) UIColor *subtitleBackgroundColor;

/**
 文字字体
 */
/****
 The text font.
 */
@property (nonatomic, copy) NSString *subtitleFontName;

/**
 关键帧图片
 */
/****
 The key frame image.
 */
@property (nonatomic, strong, readonly) UIImage *kernelImage;

/**
 动图开始时间

 单位：秒
 */
/****
 The time when the sticker appears.
 
 Unit: seconds.
 */
@property (nonatomic, assign) CGFloat pasterStartTime;

/**
 动图结束时间

 单位：秒
 */
/****
 The time when the sticker disappears.
 
 Unit: seconds.
 */
@property (nonatomic, assign) CGFloat pasterEndTime;

/**
 动图持续时间

 单位：秒
 */
/****
 The display duration of the sticker.
 
 Unit: seconds.
 */
@property (nonatomic, assign) CGFloat pasterDuration;

/**
 动图最小持续时间

 单位：秒
 */
/****
 The minimum display duration of the sticker.
 
 Unit: seconds.
 */
@property (nonatomic, assign) CGFloat pasterMinDuration;

/**
 编辑区域
 */
/****
 The display area of the sticker.
 */
@property (nonatomic, assign) CGSize displaySize;

/**
 视频输出分辨率
 */
/****
 The video export resolution. 
 */
@property (nonatomic, assign) CGSize outputSize;

/**
 预览大小
 */
/****
 The preview size.
 */
@property (nonatomic, assign) CGSize previewRenderSize;

- (NSString *)getIconPath;

/**
 关键帧图片

 @return 图片路径
 */
/****
 Gets the key frame image.

 @return The image path.
 */
- (NSString *)getKernelImagePath;

/**
 序列帧

 @return 序列帧集合
 */
/****
 Gets the frames of the sticker.

 @return The frames represented as an array.
 */
- (NSArray<AliyunEffectPasterFrameItem *> *)frames;

/**
 原始时间

 @return 时间 单位：秒
 */
/****
 Gets the original display duration of the sticker.

 @return The time in seconds.
 */
- (CGFloat)originDuration;

/**
 文字原始时长

 相对于动图
 @return 时间 单位：秒
 */
/****
 Gets the original display duration of the text.
 
 This duration is relative to the duration of the sticker.
 @return The time in seconds.
 */
- (CGFloat)originTextDuration;

/**
 文字开始出现的时间 相对于动图

 @return 时间 单位：秒
 */
/****
 Gets the time when the text appears.
 
 This time is relative to the time when the sticker appears.
 @return The time in seconds.
 */
- (CGFloat)originTextBeginTime;

/**
 唯一id

 @return id
 */
/****
 Gets the sticker id.

 @return id
 */
- (int)eid;

/**
 开始编辑 将要进入编辑状态
 */
/****
 Sets the editing state to Starting.
 */
- (void)editWillStart;

/**
 开始编辑 进入编辑状态
 */
/****
 Sets the editing state to Started.
 */
- (void)editDidStart;

/**
 开始编辑 进入编辑
 */
/****
 Sets the editing state to In progress.
 */
- (void)editProcess;

/**
 完成编辑
 */
/****
 Finishes editing.
 */
- (void)editCompleted;

/**
 字幕编辑完成

 @param image 字幕的图片
 */
/****
 Finishes text editing.

 @param image The text background image.
 */
- (void)editCompletedWithImage:(UIImage *)image;

/**
 获取effectPaster

 @return effectPaster
 */
/****
 Gets the effectPaster object.

 @return effectPaster
 */
- (id)getEffectPaster;


@end
