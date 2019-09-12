//
//  AliyunPasterManager.h
//  AliyunVideo
//
//  Created by Vienta on 2017/3/3.
//  Copyright (C) 2010-2017 Alibaba Group Holding Limited. All rights reserved.
//

#import "AliyunPasterController.h"
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

/**
 动图管理器协议
 */
/****
 The protocol of sticker managers.
 */
@protocol AliyunPasterManagerDelegate <NSObject>

/**
 动图控制器即将被删除

 @param pasterController 动图控制器
 */
/****
 The callback that outputs the sticker controller to be deleted.

 @param pasterController The sticker controller to be deleted.
 */
- (void)pasterManagerWillDeletePasterController:(AliyunPasterController *)pasterController;

@end

/**
 动图管理器
 */
/****
 A class that defines sticker managers.
 */
@interface AliyunPasterManager : NSObject

/**
 动图管理器回调
 */
/****
 The callback of sticker managers.
 */
@property (nonatomic, weak) id<AliyunPasterManagerDelegate> delegate;

/**
 设置编辑区域
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
 渲染时size
 */
/****
 The preview size.
 */
@property (nonatomic, assign) CGSize previewRenderSize;

/**
 添加动图

 @param filePath 动图资源路径
 @param st 动图开始时间
 @param duration 动图持续时间
 @return 返回动图控制器
 */
/****
 Adds a sticker.

 @param filePath The path of the sticker file.
 @param st The time when the sticker appears.
 @param duration The display duration of the sticker.
 @return The sticker controller.
 */
- (AliyunPasterController *)addPaster:(NSString *)filePath startTime:(double)st duration:(double)duration;

/**
 添加字幕

 @param text 文字
 @param bounds 大小
 @param st 字幕开始时间
 @param duration 字幕持续时间
 @return 返回动图控制器
 */
/****
 Adds a caption.

 @param text The text contents. 
 @param bounds The size of the text display area.
 @param st The time when the caption appears.
 @param duration The display duration of the caption.
 @return The sticker controller.
 */
- (AliyunPasterController *)addSubtitle:(NSString *)text bounds:(CGRect)bounds startTime:(CGFloat)st duration:(CGFloat)duration;

/**
 获取所有的动图控制器

 @return 动图控制器数组
 */
/****
 Gets all sticker controllers.

 @return The sticker controllers in an array.
 */
- (NSArray *)getAllPasterControllers;

/**
 通过id获取pasterController

 @param obj id
 @return pasterController
 */
/****
 Gets a sticker controller by id.

 @param The id of a sticker controller.
 @return pasterController
 */
- (AliyunPasterController *)getPasterControllerByObj:(id)obj;

/**
 动图显示区域上某个位置是否存在动图

 @param point 点击的位置
 @param time 当前视频播放的当前时间
 @return 若当前时刻该位置有动图，则返回动图控制器，否则，返回nil
 */
/****
 Gets the sticker in a specific position of the display area.

 @param point The position in the display area.
 @param time The current playback time.
 @return If a sticker exists in the specified position, the sticker controller is returned. Otherwise, nil is returned.
 */
- (AliyunPasterController *)touchPoint:(CGPoint)point atTime:(double)time;

/**
 删除所有动图控制器，即删除所有动图
 */
/****
 Removes all sticker controllers.
 This method removes all stickers.
 */
- (void)removeAllPasterControllers;

/**
 API_AVAILABLE(3.7.0)

 删除pasterController 并立即从渲染里面移除

 @param pasterController 动图控制器对象
 */
/****
 API_AVAILABLE(3.7.0)
 
 Removes a sticker controller and the corresponding sticker from rendering.

 @param pasterController The sticker controller object to be removed.
 */
- (void)removePasterController:(AliyunPasterController *)pasterController;

/**
 删除所有的普通动图
 */
/****
 Removes all normal stickers.
 */
- (void)removeAllNormalPasterControllers;

/**
 删除所有的字幕动图
 */
/****
 Removes all animated captions.
 */
- (void)removeAllCaptionPasterControllers;

/**
 删除所有的纯文字动图
 */
/****
 Removes all standard captions.
 */
- (void)removeAllSubtitlePasterControllers;

/**
 获取当前正在编辑的动图控制器

 @return 动图控制器
 */
/****
 Gets the sticker controller that is currently being edited.
 
 @return The sticker controller.
 */
- (AliyunPasterController *)getCurrentEditPasterController;

@end
