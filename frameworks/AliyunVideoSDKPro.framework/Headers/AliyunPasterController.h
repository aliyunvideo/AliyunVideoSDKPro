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
typedef NS_ENUM(NSInteger, AliyunPasterEffectType) {
    AliyunPasterEffectTypeNormal = 0,
    AliyunPasterEffectTypeSubtitle = 1,
    AliyunPasterEffectTypeCaption = 2,
};

/**
 动图控制器类
 */
@interface AliyunPasterController : NSObject<AliyunPasterUIEventProtocol>


/**
 设置动图的view

 @warning:一定要设置
 */
@property (nonatomic, strong) UIView *pasterView;

/**
 动图类型
 */
@property (nonatomic, assign, readonly) AliyunPasterEffectType pasterType;

/**
 动图的旋转角度

 单位：弧度
 */
@property (nonatomic, assign) CGFloat pasterRotate;

/**
 动图的位置(x,y)
 */
@property (nonatomic, assign) CGPoint pasterPosition;

/**
 动图的宽高
 */
@property (nonatomic, assign) CGSize pasterSize;

/**
 动图的位置大小
 */
@property (nonatomic, assign) CGRect pasterFrame;

/**
 动图镜像
 */
@property (nonatomic, assign) BOOL mirror;

/**
 文字内容
 */
@property (nonatomic, copy) NSString *subtitle;

/**
 文字位置

 相对于动图本身的位置大小
 */
@property (nonatomic, assign) CGRect subtitleFrame;

/**
 文字的后台配置字体
 */
@property (nonatomic, copy, readonly) NSString *subtitleConfigFontName;

/**
 文字的后台配置字体的id
 */
@property (nonatomic, assign, readonly) NSInteger subtitleConfigFontId;

/**
 文字是否描边
 */
@property (nonatomic, assign) BOOL subtitleStroke;

/**
 文字颜色
 */
@property (nonatomic, strong) UIColor *subtitleColor;

/**
 文字描边颜色
 */
@property (nonatomic, strong) UIColor *subtitleStrokeColor;

/**
 文字的背景颜色
 */
@property (nonatomic, strong) UIColor *subtitleBackgroundColor;

/**
 文字字体
 */
@property (nonatomic, copy) NSString *subtitleFontName;

/**
 关键帧图片
 */
@property (nonatomic, strong, readonly) UIImage *kernelImage;

/**
 动图开始时间

 单位：秒
 */
@property (nonatomic, assign) CGFloat pasterStartTime;

/**
 动图结束时间

 单位：秒
 */
@property (nonatomic, assign) CGFloat pasterEndTime;

/**
 动图持续时间

 单位：秒
 */
@property (nonatomic, assign) CGFloat pasterDuration;

/**
 动图最小持续时间

 单位：秒
 */
@property (nonatomic, assign) CGFloat pasterMinDuration;

/**
 编辑区域
 */
@property (nonatomic, assign) CGSize displaySize;

/**
 视频输出分辨率
 */
@property (nonatomic, assign) CGSize outputSize;

/**
 预览大小
 */
@property (nonatomic, assign) CGSize previewRenderSize;

- (NSString *)getIconPath;

/**
 关键帧图片

 @return 图片路径
 */
- (NSString *)getKernelImagePath;

/**
 序列帧

 @return 序列帧集合
 */
- (NSArray<AliyunEffectPasterFrameItem *> *)frames;

/**
 原始时间

 @return 时间 单位：秒
 */
- (CGFloat)originDuration;

/**
 文字原始时长

 相对于动图
 @return 时间 单位：秒
 */
- (CGFloat)originTextDuration;

/**
 文字开始出现的时间 相对于动图

 @return 时间 单位：秒
 */
- (CGFloat)originTextBeginTime;

/**
 唯一id

 @return id
 */
- (int)eid;

/**
 开始编辑 将要进入编辑状态
 */
- (void)editWillStart;

/**
 开始编辑 进入编辑状态
 */
- (void)editDidStart;

/**
 开始编辑 进入编辑
 */
- (void)editProcess;

/**
 完成编辑
 */
- (void)editCompleted;

/**
 字幕编辑完成

 @param image 字幕的图片
 */
- (void)editCompletedWithImage:(UIImage *)image;

/**
 获取effectPaster

 @return effectPaster
 */
- (id)getEffectPaster;


@end
