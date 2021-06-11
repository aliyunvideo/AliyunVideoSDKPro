//
//  AliyunStickerManager.h
//  AliyunVideoSDKPro
//
//  Created by mengyehao on 2021/5/12.
//  Copyright © 2021 aliyun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AliyunGifStickerController.h"
#import "AliyunCaptionStickerController.h"



@interface AliyunStickerManager : NSObject

/**
 添加字幕 API_AVAILABLE(3.22.0)
 
 @param text 显示的文字
 @param bubblePath 气泡文字模版文件夹路径
 @param startTime 开始时间，单位：秒
 @param duration 时长，单位：秒
 @return AliyunCaptionStickerController 贴图控制器
 */
- (AliyunCaptionStickerController *)addCaptionText:(NSString *)text
                                        bubblePath:(NSString *)bubblePath
                                      startTime:(CGFloat)startTime
                                       duration:(CGFloat)duration;



/**
 添加动图 API_AVAILABLE(3.22.0)
 
 @param filePath 动图资源文件夹路径
 @param startTime 动图开始时间，单位：秒
 @param duration 动图持续时间，单位：秒
 @return 返回 AliyunGifStickerController控制器
 */
- (AliyunGifStickerController *)addGif:(NSString *)filePath
                             startTime:(double)startTime
                              duration:(double)duration;


/**
 删除贴图控制器 API_AVAILABLE(3.22.0)
 
 @param controller 贴图控制器
 */
- (void)remove:(AliyunRenderBaseController *)controller;


/**
 查找贴图控制器 API_AVAILABLE(3.22.0)
 
 @param point 点击点，通常相对preview
 @param time 时间戳，单位：秒
 @return 贴图控制器
 */
- (AliyunRenderBaseController *)findControllerAtPoint:(CGPoint)point
                                               atTime:(double)time;

/**
 获取所有的贴图控制器 API_AVAILABLE(3.22.0)
 
 @return 动图控制器数组
 */
- (NSArray< AliyunRenderBaseController *> *)getAllController;

@end

