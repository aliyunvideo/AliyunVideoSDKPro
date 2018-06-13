//
//  AliyunPasterManager.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/3.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliyunPasterController.h"
#import <CoreGraphics/CoreGraphics.h>

@protocol AliyunPasterManagerDelegate <NSObject>

- (void)pasterManagerWillDeletePasterController:(AliyunPasterController *)pasterController;

@end

@interface AliyunPasterManager : NSObject

@property (nonatomic, weak) id<AliyunPasterManagerDelegate> delegate;

/**
 设置编辑区域
 */
@property (nonatomic, assign) CGSize displaySize;

/**
 视频输出分辨率
 */
@property (nonatomic, assign) CGSize outputSize;

/**
 渲染时size
 */
@property (nonatomic, assign) CGSize previewRenderSize;

/**
 添加动图

 @param filePath 动图资源路径
 @param st 动图开始时间
 @param duration 动图持续时间
 @return 返回动图控制器
 */
- (AliyunPasterController *)addPaster:(NSString *)filePath startTime:(double)st duration:(double)duration;

/**
 添加字幕

 @param text 文字 如果为空 则会第一次会进入编辑  如果不为空 则直接显示 不会进入编辑状态
 @param bounds 大小
 @param st 字幕开始时间
 @param duration 字幕持续时间
 @return 返回动图控制器
 */
- (AliyunPasterController *)addSubtitle:(NSString *)text bounds:(CGRect)bounds startTime:(CGFloat)st duration:(CGFloat)duration;

/**
 删除动图控制器，在删除动图时调用

 @param pasterController 需要删除的动图控制器
 @return YES：删除成功  NO:删除失败
 */
- (BOOL)deletePasterController:(AliyunPasterController *)pasterController;


/**
 获取所有的动图控制器

 @return 动图控制器数组
 */
- (NSArray *)getAllPasterControllers;


/**
 通过id获取pasterController

 @param obj id
 @return pasterController
 */
- (AliyunPasterController *)getPasterControllerByObj:(id)obj;


/**
 动图上某个位置是否存在动图

 @param point 点击的位置
 @param time 当前视频播放的当前时间
 @return 若当前时刻该位置有动图，则返回动图控制器，否则，返回nil
 */
- (AliyunPasterController *)touchPoint:(CGPoint)point atTime:(double)time;


/**
 删除所有动图控制器，即删除所有动图
 */
- (void)removeAllPasterControllers;

/**
 删除所有的普通动图
 */
- (void)removeAllNormalPasterControllers;

/**
 删除所有的字幕动图
 */
- (void)removeAllCaptionPasterControllers;

/**
 删除所有的纯文字动图
 */
- (void)removeAllSubtitlePasterControllers;


/**
 获取当前正在编辑的动图控制器
 
 @return 动图控制器
 */
- (AliyunPasterController *)getCurrentEditPasterController;



@end
